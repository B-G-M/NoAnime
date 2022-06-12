using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;


public class Field
{
	private static Field instance;
	private static object instanceLock = new object();
	private static string savePath = "note1.txt";

	List<Line> lines;
	Barracks barracks;

	protected Field(int linesCount)
	{
		this.lines = new List<Line>(linesCount);
	}

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

	public void AddUnitsToLine(int[] unitId, int lineNumber, bool isPlayerFront = true)
	{
		foreach (var id in unitId)
		{
			Line line = lines[lineNumber];

			if (isPlayerFront)
			{
				line.addLeft(barracks.Birth(id));
			}
			else
			{
				line.addRight(barracks.Birth(id));
			}
		}
	}

	public void Wasted()
	{
		 
	}

	public void MovementIteration()
	{
		foreach (var line in lines)
		{
			line.Movement();
		}
	}

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
