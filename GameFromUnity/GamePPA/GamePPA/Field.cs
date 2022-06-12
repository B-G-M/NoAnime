using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;


public class Field
{
    private static Field instance;
    private static object instanceLock = new object();
    private static string savePath = "note1.txt";

    public List<Line> lines;
    Barracks barracks = new Barracks();

    //Создание линий на поле
    public Field(int linesCount)
    {
        this.lines = new List<Line>(linesCount);
    }


    //Получения инфы по полю в виде строки
    public string GetFieldInfo()
    {
        string info = "";
        for (int i = 0; i < lines.Count; i++)
        {
            info += lines[i].GetLineInfo();
            info += "\n";
        }
        return info;
    }

    //Создания поля
    public static Field getInstance(int linesCount = 1)
    {
        if (instance == null)
        {
            lock (instanceLock)
            {
                if (instance == null)
                {
                    instance = new Field(linesCount);
                }
            }
        }
        return instance;
    }


    //Добавление юнитов в линию на поле
    public void AddUnitsToLine(List<int> unitId, int lineNumber, bool isPlayerFront)
    {
        bool flag = false;
        Line line;
        if (lineNumber > lines.Count)
        {
            flag = true;
            line = new Line();
        }
        else
        {
            line = lines[lineNumber - 1];
        }
        for (int i = 0; i < unitId.Count; i++)
        {
            if (isPlayerFront)
            {
                line.addLeft(barracks.Birth(unitId[i]));
            }
            else if (!isPlayerFront)
            {
                line.addRight(barracks.Birth(unitId[i]));
            }
        }
        if (flag)
            lines.Add(line);
        else
        {
            if (isPlayerFront)
                lines[lineNumber - 1].leftFront = line.leftFront;
            else
                lines[lineNumber - 1].rightFront = line.rightFront;
        }
    }


    //Проверка на умерших юнитов на поле
    public void Wasted()
    {
        for (int i = 0; i < lines.Count; i++)
        {
            lines[i].Wasted();
        }
    }

    //схлопывает линии
    public void LinesMoving()
    {
        for (int i = 0; i < lines.Count - 1; i++)
        {
            if (lines[i].leftFront.Count == 0 && lines[i + 1].leftFront.Count != 0)
            {
                lines[i].leftFront.Clear();
                lines[i].leftFront.InsertRange(0, lines[i + 1].leftFront.GetRange(0, lines[i + 1].leftFront.Count));
                lines[i + 1].leftFront.Clear();
            }
            if (lines[i].rightFront.Count == 0 && lines[i + 1].rightFront.Count != 0)
            {
                lines[i].rightFront.Clear();
                lines[i].rightFront.InsertRange(0, lines[i + 1].rightFront.GetRange(0, lines[i + 1].rightFront.Count));
                lines[i + 1].rightFront.Clear();
            }
        }
    }

    //Ход на поле
    public int MovementIteration()
    {
        for (int i = 0; i < lines.Count; i++)
        {
            lines[i].Movement();
            Wasted();
        }
        LinesMoving();
        return GameEnd();
    }

    private int GameEnd()
    {
        if (lines[0].leftFront.Count != 0 && lines[0].rightFront.Count == 0)
            return 1;
        else if (lines[0].leftFront.Count == 0 && lines[0].rightFront.Count != 0)
            return 2;
        else if (lines[0].leftFront.Count == 0 && lines[0].rightFront.Count == 0)
            return 3;
        return 0;
    }

    //Метод сохранения
    public void Save()
    {
        String result = "";
        foreach (var line in lines)
        {
            result = result + line.ToString() + "\n";
        }

        try
        {
            StreamWriter sw = new StreamWriter(savePath);
            sw.WriteLine(result);
            sw.Close();
        }
        catch (Exception e)
        {
        }

    }

    //Метод загрузки инфы из сохранения
    public void Load()
    {
        String row;
        try
        {
            StreamReader sr = new StreamReader(savePath);
            Regex regex = new Regex(@"{(.+)}");
            row = sr.ReadLine();
            while (row != null)
            {
                if (regex.Matches(row).Count > 0)
                {
                    Line line = new Line();
                    line.Deserialization(regex.Matches(row)[0].Value);
                    this.lines.Add(line);
                }
                row = sr.ReadLine();
            }
            sr.Close();
        }
        catch (Exception e)
        {
            Console.WriteLine("Exception: " + e.Message);
        }
    }
}
