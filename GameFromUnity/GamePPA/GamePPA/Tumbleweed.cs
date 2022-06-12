using System;
using System.Collections;
using System.Collections.Generic;

namespace Assets.Scripts
{
	public interface IUnitIncompatible
	{
		public int GetHealth();
		public uint GetDefense();
		public uint GetCost();
		public void GetHit(uint damageTaken);
		public void GetHeal(uint healing, int maxHp);
	}

	public class Tumbleweed : IUnitIncompatible
	{
		private int _hp;
		private readonly uint _def;
		private readonly uint _cost;

		public Tumbleweed(int hp, uint def, uint cost)
		{
			_hp = hp;
			_def = def;
			_cost = cost;
		}

		public int GetHealth()
		{
			return _hp;
		}

		public uint GetDefense()
		{
			return _def;
		}

		public uint GetCost()
		{
			return _cost;
		}

		public void GetHit(uint damageTaken)
		{
			_hp = (int)Math.Max(_hp - damageTaken + _def, 0);
		}

		public void GetHeal(uint healing, int maxHp)
		{
			_hp = (int)Math.Min(_hp + healing, maxHp);
		}
	}

	public class TumbleweedAdapter : IUnit
	{
		private readonly IUnitIncompatible _incompatible;
		private uint _id;
		private string _name;
		private int _maxHP;
		private uint _dmg;
		private uint _range;
		private float _chance;

		// Incompatible unit passed as external dependency
		public TumbleweedAdapter(IUnitIncompatible unit)
		{
			_incompatible = unit;

			_id = 4;
			_name = "Tumbleweed";
			_maxHP = 0;
			_dmg = 0;
			_range = 0;
			_chance = 0;
		}

		public uint Id => _id;
		public string Name => _name;
		public int MaxHP => _maxHP;
		public uint Damage => _dmg;
		public uint AttackRange => _range;
		public float AbilityChance => _chance;
		public uint Cost => _incompatible.GetCost();
		public uint Defense => _incompatible.GetDefense();
		public int Health => _incompatible.GetHealth();

		public void SpecialAbility(Line line, uint index, char friendly)
		{
			// fsociety
		}

		public List<IUnit> GetFriendlyFront(char friendly, Line line)
		{
			return friendly == 'l' ? line.leftFront : line.rightFront;
		}

		public List<IUnit> GetEnemyFront(char friendly, Line line)
		{
			return friendly == 'r' ? line.leftFront : line.rightFront;
		}

		public void DamageTaken(uint damageTaken)
		{
			_incompatible.GetHit(damageTaken);
			if (_incompatible.GetHealth() == 0)
			{
				// ... delete unit
			}
		}

		public bool IsAbility()
		{
			return false;
		}

		public void Heal(uint receivedHealing)
		{
			_incompatible.GetHeal(receivedHealing, _maxHP);
		}
	}
}