using System;
using System.Collections.Generic;

namespace GamePPA
{
    class Menu
    {
        Field field;
        List<int> unitsChoosenLeft = new List<int>();
        List<int> unitsChoosenRight = new List<int>();

        public void Game()
        {
            UnitPick();
            FormationPick();
            Movment();
        }
        public void UnitPick()
        {
            int Bank = 10;
            int choose = 1;
            bool leftFront = true;

            while (true)
            {
                if (choose < 1 || choose > 6)
                    Console.WriteLine("Выбран несуществующий юнит!!!!!!\n");
                if (leftFront)
                {
                    Console.WriteLine("Выберите юнита для левой стороны:");
                    Console.WriteLine("Количество монет: " + Bank);
                }
                else
                {
                    Console.WriteLine("Выберите юнита для правой стороны:");
                    Console.WriteLine("Количество монет: " + Bank);
                }
                Console.WriteLine("1:Warior; 2:Archer; 3:Wizard; 4:Tumbleweed 5:Knight 6:Healer");



                try
                {
                    choose = Convert.ToInt32(Console.ReadLine());
                }
                catch (Exception ex)
                {
                    choose = 7;
                }
                if (choose == 1)
                {
                    Bank -= 2;
                    if (leftFront)
                        unitsChoosenLeft.Add(choose);
                    else
                        unitsChoosenRight.Add(choose);
                }
                else if (choose == 2 && Bank - 4 >= 0)
                {
                    Bank -= 4;
                    if (leftFront)
                        unitsChoosenLeft.Add(choose);
                    else
                        unitsChoosenRight.Add(choose);
                }
                else if (choose == 3 && Bank - 10 >= 0)
                {
                    Bank -= 10;
                    if (leftFront)
                        unitsChoosenLeft.Add(choose);
                    else
                        unitsChoosenRight.Add(choose);
                }
                else if (choose == 4 && Bank - 14 >= 0)
                {
                    Bank -= 14;
                    if (leftFront)
                        unitsChoosenLeft.Add(choose);
                    else
                        unitsChoosenRight.Add(choose);
                }
                else if (choose == 5 && Bank - 12 >= 0)
                {
                    Bank -= 12;
                    if (leftFront)
                        unitsChoosenLeft.Add(choose);
                    else
                        unitsChoosenRight.Add(choose);
                }
                else if (choose == 6 && Bank - 8 >= 0)
                {
                    Bank -= 8;
                    if (leftFront)
                        unitsChoosenLeft.Add(choose);
                    else
                        unitsChoosenRight.Add(choose);
                }

                else
                    Console.WriteLine("Казна пуста, милорд");

                if (Bank == 0 && !leftFront)
                    break;
                if (Bank == 0)
                {
                    leftFront = false;
                    Bank = 10;
                }
                Console.Clear();
            }
        }

        public void FormationPick()
        {
            int choose = 1;
            Console.Clear();
            while (true)
            {
                if (choose < 1 || choose > 3) { Console.WriteLine("Выбраной формации не существует!!!!\n"); }
                Console.WriteLine("Выберите формацию: \n" +
                    "1: Стенка на стенку\n" +
                    "2: 1 колонна на 1 колонну\n" +
                    "3: 3 колонны на 3 колонны");
                try
                {
                    choose = Convert.ToInt32(Console.ReadLine());
                }
                catch (Exception ex)
                {
                    choose = 7;
                }
                if (choose == 1)
                {
                    field = Field.getInstance(Math.Max(unitsChoosenLeft.Count, unitsChoosenRight.Count));
                    for (int i = 0; i < unitsChoosenLeft.Count; i++)
                        field.AddUnitsToLine(unitsChoosenLeft.GetRange(i, 1), i + 1, true);
                    for (int i = 0; i < unitsChoosenRight.Count; i++)
                        field.AddUnitsToLine(unitsChoosenRight.GetRange(i, 1), i + 1, false);
                    break;
                }
                else if (choose == 2)
                {
                    field = Field.getInstance();
                    field.AddUnitsToLine(unitsChoosenLeft, 1, true);
                    field.AddUnitsToLine(unitsChoosenRight, 1, false);
                    break;
                }
                else if (choose == 3)
                {
                    field = Field.getInstance(3);
                    for (int i = 3; i > 0; i--)
                    {
                        field.AddUnitsToLine(unitsChoosenLeft.GetRange(0, unitsChoosenLeft.Count / i), 4 - i, true);
                        unitsChoosenLeft.RemoveRange(0, unitsChoosenLeft.Count / i);

                        field.AddUnitsToLine(unitsChoosenRight.GetRange(0, unitsChoosenRight.Count / i), 4 - i, false);
                        unitsChoosenRight.RemoveRange(0, unitsChoosenRight.Count / i);
                    }
                    break;
                }
                Console.Clear();
            }
        }

        public void Movment()
        {

            Console.Clear();
            Console.WriteLine("Армии составлены");
            Console.ReadKey();

            int choose = 1;

            bool flag = true;
            field.command.makeBackup();
            Console.Clear();
            while (flag)
            {
                
                Console.WriteLine(field.GetFieldInfo());
                Console.WriteLine("1:Шаг" +
                    " 2:Save" +
                    " 3:Load" +
                    " 4:Отмена действия" +
                    " 5:Exit");
                try
                {
                    choose = Convert.ToInt32(Console.ReadLine());
                }
                catch (Exception)
                {

                    choose = 6;
                }
                
                Console.Clear();

                switch (choose)
                {
                    case 1:
                        field.command.makeBackup();
                        switch (field.MovementIteration())
                        {
                            case 1:
                                Console.Clear();
                                Console.WriteLine("Левая армия победила");
                                flag = false;
                                break;
                            case 2:
                                Console.Clear();
                                Console.WriteLine("Правая армия победила");
                                flag = false;
                                break;
                            case 3:
                                Console.Clear();
                                Console.WriteLine("Ничья");
                                flag = false;
                                break;
                            default:
                                break;
                        }

                        break;
                    case 2:
                        field.command.UserSave();
                        break;
                    case 3:
                        field.Load(field.command.UserLoad());
                        break;
                    case 4:
                        field.Load(field.command.Undo());
                        break;
                    case 5:
                        flag = false;
                        break;
                    default:
                        Console.WriteLine("Выбран неверный вариант\n");
                        break;
                }
            }
        }
    }
}
