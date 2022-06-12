using System.Collections;
using System.Collections.Generic;

public abstract class UnitFactory
{
	public IUnit CreateUnit(int hp)
	{
		IUnit unit = Create();
		
		if (hp > 0)
			unit.DamageTaken((uint)(unit.Health + unit.Defense - hp));
		return unit;
	}
	public abstract IUnit Create();
}


class WizardCreator : UnitFactory
{
	public override IUnit Create()
	{
		return new Wizard();
	}
}

class WariorCreator : UnitFactory
{
	public override IUnit Create()
	{
		return new Warior();
	}
}

class ArcherCreator : UnitFactory
{
	public override IUnit Create()
	{
		return new Archer();
	}
}

class KnightCreator : UnitFactory
{
	public override IUnit Create()
	{
		return new Knight();
	}
}

class HealerCreator : UnitFactory
{
	public override IUnit Create()
	{
		return new Healer();
	}
}

class TumbleweedCreator : UnitFactory
{
	public override IUnit Create()
	{
		return new Tumbleweed();
	}
}


class Barracks
{
	
	//public delegate IUnit CreateDelegate();
	//public static Dictionary<uint, CreateDelegate> CreateDictionary = 
	//	new Dictionary<uint, CreateDelegate> 
	//	{ 
	//		{1,new CreateDelegate } 
	//	};

	UnitFactory unitFactory;

	public IUnit Birth(int id, int hp = 0)
	{
        if (id == 1)
        {
			unitFactory = new WariorCreator();
        }
		if(id == 2)
        {
			unitFactory = new ArcherCreator();
        }
		if (id == 3)
		{
			unitFactory = new WizardCreator();
		}
		if (id == 4)
		{
			unitFactory = new TumbleweedCreator();
		}
		if (id == 5)
        {
			unitFactory = new KnightCreator();
        }
		if (id == 6)
        {
			unitFactory = new HealerCreator();
        }
		return unitFactory.CreateUnit(hp);

	}
}
