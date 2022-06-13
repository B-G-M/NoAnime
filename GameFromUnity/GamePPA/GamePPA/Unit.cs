using System;
using System.Collections;
using System.Collections.Generic;

public interface IUnit
{
	public uint Id { get; }
	public string Name { get; }
	public int Health { get; }
	public int MaxHP { get; }
	public uint Damage { get; }
	public uint Defense { get; }
	public uint AttackRange { get; }
	public float AbilityChance { get; }

	public uint Cost { get; }

	// public IItem Equipment { get; set; }
	public void SpecialAbility(Line line, uint index, char friendly);
	public List<IUnit> GetFriendlyFront(char friendly, Line line);
	public List<IUnit> GetEnemyFront(char friendly, Line line);
	public void DamageTaken(uint damageTaken);
	public bool IsAbility();
	public void Heal(uint receivedHealing);
}

abstract public class Unit : IUnit
{
	protected uint _id;
	protected string _name;
	protected int _hp;
	protected int _maxHP;
	protected uint _dmg;
	protected uint _def;
	protected uint _range;
	protected uint _cost;
	protected float _chance;

	public uint Id => _id;
	public string Name => _name;
	public int Health => _hp;
	public int MaxHP => _maxHP;
	public uint Damage => _dmg;
	public uint Defense => _def;
	public uint AttackRange => _range;
	public uint Cost => _cost;
	public float AbilityChance => _chance;

	public abstract void SpecialAbility(Line line, uint index, char friendly);

	public bool IsAbility() 
	{
		Random rnd = new Random();
		float chance = (float)rnd.NextDouble();
		if (_chance < chance)
		{
			return true;
		}

		return false;
	}

	public List<IUnit> GetFriendlyFront(char friendly, Line line)
	{
		if (friendly == 'l')
		{
			return line.leftFront;
		}

		return line.rightFront;
	}

	public List<IUnit> GetEnemyFront(char friendly, Line line)
	{
		if (friendly == 'r')
		{
			return line.leftFront;
		}

		return line.rightFront;
	}

	public virtual void DamageTaken(uint damageTaken)
	{
		_hp = (int)Math.Max(_hp - damageTaken + _def, 0);
	}

	public void Heal(uint receivedHealing)
	{
		_hp = (int)Math.Min(_hp + receivedHealing, _maxHP);
	}
}


abstract class WariorDecorator : Unit
{
	protected bool Dress(Knight warior)
	{
		List<String> ups = new List<String> { "Шлем", "Щит", "Пика", "Коняшка" };
		foreach (var ammunition in warior.DressedAmmunitions)
		{
			ups.Remove(ammunition.Name);
		}

		if (ups.Count > 0)
		{
			Random rnd = new Random();
			int index = (int)(rnd.NextDouble() * ups.Count);
			switch (ups[index])
			{
				case "Шлем":
					warior.DressedAmmunitions.Add(new Hemlet());
					break;
				case "Щит":
					warior.DressedAmmunitions.Add(new Shield());
					break;
				case "Пика":
					warior.DressedAmmunitions.Add(new Peak());
					break;
				case "Коняшка":
					warior.DressedAmmunitions.Add(new Horse());
					break;
				default: break;
			}

			return true;
		}

		return false;
	}
}

class Warior : WariorDecorator
{
	public Warior()
	{
		_id = 1; 
		_name = "Wa";
		_hp = 50;
		_dmg = 15;
		_def = 5;
		_range = 1;
		_cost = 2;
		_chance = 0.3f;
	}

	

	public override void SpecialAbility(Line line, uint index, char friendly)
	{
		List<IUnit> friends = this.GetFriendlyFront(friendly, line);
		if (friends.Count > 1)
		{
			bool dressFlg = false;
			if (index > 0 && friends[(int)index - 1].Id == 5)
			{
				dressFlg = Dress((Knight)friends[(int)index - 1]);
			}

			if (!dressFlg && index < friends.Count - 1 && friends[(int)index + 1].Id == 5)
			{
				Dress((Knight)friends[(int)index + 1]);
			}
		}
	}
}

class Archer : Unit
{
	public Archer()
	{
		_id = 2; 
		_name = "Ar";
		_hp = 50;
		_dmg = 20;
		_def = 0;
		_range = 3;
		_cost = 4;
		_chance = 0.25f;
	}

	public override void SpecialAbility(Line line, uint index, char friendly)
	{
		if (IsAbility())
		{
			if (this.GetEnemyFront(friendly, line).Count >= 2)
			{
				this.GetEnemyFront(friendly, line)[1].DamageTaken(_dmg);
			}
		}
	}
}

class Wizard : Unit
{
	public Wizard()
	{
		_id = 3;
		_name = "Wi";
		_hp = 40;
		_maxHP = 0;
		_dmg = 50;
		_def = 6;
		_range = 3;
		_cost = 10;
		_chance = 0.2f;
	}

	public override void SpecialAbility(Line line, uint index, char friendly)
	{
        if (IsAbility())
        {
            List<IUnit> friend = GetFriendlyFront(friendly, line);
            Barracks a = new Barracks();
            int newId = -1;

			if(friend.Count > 1)
			{
				if (index > 0)
				{
					newId = (int)friend[(int)index - 1].Id;
				}
				else if (index + 1 < friend.Count)
				{
					newId = (int)friend[(int)index + 1].Id;
				}
			}

            if (newId != -1)
            {
                if (friendly == 'l')
                {
                    line.addLeft(a.Birth(newId));
                }
                else
                {
                    line.addRight(a.Birth(newId));
                }
            }
        }
    }
}

class Tumbleweed : Unit
{
	public Tumbleweed()
	{
		_id = 4;
		_name = "Tum";
		_hp = 200;
		_maxHP = 0;
		_dmg = 0;
		_def = 3;
		_range = 0;
		_cost = 14;
		_chance = 0;
	}

	public override void SpecialAbility(Line line, uint index, char friendly)
	{

	}
}

class Knight : Unit
{
	public Knight()
	{
		_id = 5; 
		_name = "Kni";
		_hp = 100;
		_maxHP = 100;
		_dmg = 40;
		_def = 5;
		_range = 1;
		_cost = 12;
		_chance = 0.15f;
	}

	public List<IAmmunition> DressedAmmunitions { get; } = new List<IAmmunition>();

	public override void SpecialAbility(Line line, uint index, char friendly)
	{
		
	}


	public override void DamageTaken(uint damageTaken)
	{
		// Get hit from enemy.
		base.DamageTaken(damageTaken);

		// May lose one of dressed ammunition.
		if (IsAbility())
		{
			var idx = DressedAmmunitions.Count - 1;

			if (idx >= 0)
			{
				DressedAmmunitions.RemoveAt(idx);
			}
		}
	}
}

class Healer : Unit
{
	public Healer()
	{
		_id = 6; 
		_name = "Heal";
		_hp = 60;
		_maxHP = 60;
		_dmg = 10;
		_def = 7;
		_range = 1;
		_cost = 8;
		_chance = 0.33f;
	}

	public override void SpecialAbility(Line line, uint index, char friendly)
	{
		if (IsAbility())
		{
			List<IUnit> friends = this.GetFriendlyFront(friendly, line);
			IUnit friend = null;
			if (friends.Count > 1)
			{
				if (index > 0)
					friend = friends[(int)index - 1];
				if (index < friends.Count - 1 &&
					(friend == null || friend.Health < friends[(int)index + 1].Health))
					friend = friends[(int)index + 1];

				if (friend != null)
					friend.Heal((uint)friend.Health);
			}
		}
	}
}
