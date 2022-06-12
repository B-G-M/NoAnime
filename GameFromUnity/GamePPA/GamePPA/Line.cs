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

	public void Wasted()
	{
		//Подписчик на смерть юнита
		//Удаляет юнита если пришло сообщение о смерти

		//Если все юниты умерли, то отправляет сообщение о проигрыше полю 

		//Добавляет умершего юнита в счетчик смертей фронта линии
	}

	public void Movement()
	{
		for (int i = 0; i < leftFront.Count; i++)
		{
			if (rightFront.Count > 0 && leftFront[i].AttackRange > i)
			{
				rightFront[0].Hit(leftFront[i].Damage);
				leftFront[i].SpecialAbility(this, (uint)i, 'l');
			}
		}
		for (int i = 0; i < rightFront.Count; i++)
		{
			if (leftFront.Count > 0 && rightFront[i].AttackRange > i)
			{
				leftFront[0].Hit(rightFront[i].Damage);
				rightFront[i].SpecialAbility(this, (uint)i, 'r');
			}
		}
	}

	private String GetFrontInfo(List<IUnit> front)
	{
		String frontInfo = "";
		foreach (var unit in leftFront)
		{
			String unitInfo = unit.Id.ToString() + ';' + unit.Health.ToString();

			String unitAddInfo = "";
			
			if (unit.Id == 5)
				foreach (var ammun in ((Kinght)unit).DressedAmmunitions)
				{
					unitAddInfo = unitAddInfo + ";" + ammun.Name;
				}

			frontInfo = frontInfo + "(" + unitInfo + unitAddInfo + ")";
		}

		return frontInfo;
	}
	public override string ToString()
	{
		return "{" + GetFrontInfo(leftFront) + '=' + GetFrontInfo(rightFront) + "}";
	}

	private void FullFront(String text, List<IUnit> front)
	{
		Regex regex = new Regex(@"\((.+)\)");
		if (regex.Matches(text).Count > 0)
		{
			Barracks barracks = new Barracks();
			foreach (var match in regex.Matches((text)))
			{
				String[] unitInfo = text.Split(new char[] { ';' });

				IUnit unit = barracks.Birth(Int32.Parse(unitInfo[0]), Int32.Parse(unitInfo[1]));

				if (unit.Id == 5)
					for (int i = 2; i < unitInfo.Length; i++)
					{
						switch (unitInfo[i])
						{
							case "Шлем":
								((Kinght)unit).DressedAmmunitions.Add(new Hemlet());
								break;
							case "Щит":
								((Kinght)unit).DressedAmmunitions.Add(new Shield());
								break;
							case "Пика":
								((Kinght)unit).DressedAmmunitions.Add(new Peak());
								break;
							case "Коняшка":
								((Kinght)unit).DressedAmmunitions.Add(new Horse());
								break;
							default: break;
						}
					}
			}
		}
	}
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
