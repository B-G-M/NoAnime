using System;
using System.Collections;
using System.Collections.Generic;
using System.Text.RegularExpressions;

public class Line
{
	public List<IUnit> leftFront = new List<IUnit>();
	public List<IUnit> rightFront = new List<IUnit>();

	public int leftDeath;
	public int rightDeath;
	public void addLeft(IUnit unit)
	{
		leftFront.Add(unit);
	}

	public void addRight(IUnit unit)
	{
		rightFront.Add(unit);
	}

	//Проверка на умерших юнитов в линии
	public void Wasted()
	{
        for (int i = 0; i < leftFront.Count; i++)
        {
            if (leftFront[i].Health <= 0)
            {
				leftFront.RemoveAt(i);
            }
        }
		for (int i = 0; i < rightFront.Count; i++)
		{
			if (rightFront[i].Health <= 0)
			{
				rightFront.RemoveAt(i);
			}
		}
	}


	//ходы
	public void Movement(bool leftFirst)
	{
        if (leftFirst)
        {
			for (int i = 1; i < leftFront.Count; i++)
			{
				if (rightFront.Count > 1 && leftFront[i].AttackRange > i)
				{
					rightFront[0].DamageTaken(leftFront[i].Damage);
					leftFront[i].SpecialAbility(this, (uint)i, 'l');
				}
			}
			for (int i = 1; i < rightFront.Count; i++)
			{
				if (leftFront.Count > 1 && rightFront[i].AttackRange > i)
				{
					leftFront[0].DamageTaken(rightFront[i].Damage);
					rightFront[i].SpecialAbility(this, (uint)i, 'r');
				}
			}
		}
        else
        {
			for (int i = 1; i < rightFront.Count; i++)
			{
				if (leftFront.Count > 1 && rightFront[i].AttackRange > i)
				{
					leftFront[0].DamageTaken(rightFront[i].Damage);
					rightFront[i].SpecialAbility(this, (uint)i, 'r');
				}
			}
			for (int i = 1; i < leftFront.Count; i++)
			{
				if (rightFront.Count > 1 && leftFront[i].AttackRange > i)
				{
					rightFront[0].DamageTaken(leftFront[i].Damage);
					leftFront[i].SpecialAbility(this, (uint)i, 'l');
				}
			}
		}
	}
	
	public void FirstRankMovement(bool leftFirst)
    {
		if(leftFront.Count == 0 || rightFront.Count == 0)
			return;
		if (leftFirst)
        {
			rightFront[0].DamageTaken(leftFront[0].Damage);
			leftFront[0].DamageTaken(rightFront[0].Damage);
		}
		else
        {
			leftFront[0].DamageTaken(rightFront[0].Damage);
			rightFront[0].DamageTaken(leftFront[0].Damage);
		}
    }

	public string GetLineInfo()
    {
		string info = "";
		leftFront.Reverse();
		for (int i = 0; i < leftFront.Count; i++)
		{
			info += "{"+leftFront[i].Name + " ; " + leftFront[i].Health+"}";
			if (leftFront[i].Id == 5)
				foreach (var ammun in ((Knight)leftFront[i]).DressedAmmunitions)
				{
					info += ";" + ammun.Name;
				}
		}
		leftFront.Reverse();
		info += " = ";
		for (int i = 0; i < rightFront.Count; i++)
		{
			info += "{" + rightFront[i].Name + " ; " + rightFront[i].Health + "}";
			if (rightFront[i].Id == 5)
				foreach (var ammun in ((Knight)rightFront[i]).DressedAmmunitions)
				{
					info += ";" + ammun.Name;
				}
		}
		return info;
    }

	//Вывод инфы о списке юнитов
	public String GetFrontInfo(List<IUnit> front)
	{
		String frontInfo = "";
		foreach (var unit in front)
		{
			String unitInfo = unit.Name.ToString() + ';' + unit.Health.ToString();

			String unitAddInfo = "";
			
			if (unit.Id == 5)
				foreach (var ammun in ((Knight)unit).DressedAmmunitions)
				{
					unitAddInfo = unitAddInfo + ";" + ammun.Name;
				}

			frontInfo = frontInfo + "(" + unitInfo + unitAddInfo + ")";
		}

		return frontInfo;
	}

	//Вывод инфы об обоих фронтах
	public override string ToString()
	{
		return "{" + GetFrontInfo(leftFront) + '=' + GetFrontInfo(rightFront) + "}";
	}


	private void FullFront(String text, List<IUnit> front)
	{
		front.Clear();
		Regex regex = new Regex(@"\((.*?)\)");
		MatchCollection matches = regex.Matches(text);
		int id = 0;
		if (matches.Count > 0)
		{
			Barracks barracks = new Barracks();
			foreach (Match match in matches)
			{
				text = match.Groups[1].Value;
				String[] unitInfo = text.Split(new char[] { ';' });
				if (unitInfo[0] == "Wa")// сделать Enum
					id = 1;
				else if (unitInfo[0] == "Ar")
					id = 2;
				else if (unitInfo[0] == "Wi")
					id = 3;
				else if (unitInfo[0] == "Tum")
					id = 4;
				else if (unitInfo[0] == "Kni")
					id = 5;
				else if (unitInfo[0] == "Heal")
					id= 6;
				IUnit unit = barracks.Birth(id, Int32.Parse(unitInfo[1]));

				if (unit.Id == 5)
					for (int i = 2; i < unitInfo.Length; i++)
					{
						switch (unitInfo[i])
						{
							case "Шлем":
								((Knight)unit).DressedAmmunitions.Add(new Hemlet());
								break;
							case "Щит":
								((Knight)unit).DressedAmmunitions.Add(new Shield());
								break;
							case "Пика":
								((Knight)unit).DressedAmmunitions.Add(new Peak());
								break;
							case "Коняшка":
								((Knight)unit).DressedAmmunitions.Add(new Horse());
								break;
							default: break;
						}
					}
				front.Add(unit);
			}
		}
	}

	//Разделение инфы на 2 части FullFront
	public void Deserialization(String text)
	{
		String[] frontInfo = text.Split(new char[] { '=' });
		if (frontInfo.Length > 1)
		{
			this.FullFront(frontInfo[0], leftFront);
			this.FullFront(frontInfo[1], rightFront);
		}
	}
}
