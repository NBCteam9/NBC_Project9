#include "Monster.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "MaxHPBoost.h"
#include <random>
#include <vector>

// Monster Constructor
Monster::Monster(int level) 
{
	name = "default";
	health = 0;
	attack = 0;
	dropRate = 0;
	dropGold = 0;
}

string Monster::GetName() const
{
	return name;
}

int Monster::GetHealth() const
{
	return health;
}

int Monster::GetAttack() const
{
	return attack;
}

void Monster::TakeDamage(int damage)
{
	int preHp = health;
	health -= damage;
	if (health <= 0)
	{
		health = 0;
	}
	cout << preHp << "->" << health << endl;
}

// 
//int Monster::getRandomNum(int min, int max) {
//	int randomNum = rand() % (max - min + 1); 
//	randomNum += min;
//	return randomNum;
//}

int Monster::GetRandomNum(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}

Item* Monster::DropItem() 
{
	int r1 = GetRandomNum(1, 100);
	int r2;
	int itemMax = 0;
	// probability = hwak ryul
	int probability = 0;

	if (r1 < dropRate) 
	{
		vector<pair<int, Item*>> items = 
		{
			{50, new HealthPotion()},
			{50, new AttackBoost()},
			{50, new MaxHPBoost()}
		};

		for (pair<int, Item*> item : items) 
		{
			itemMax += item.first;
		}

		r2 = GetRandomNum(1, itemMax);

		for (pair<int, Item*> item : items)
		{
			probability += item.first;

			if (r2 <= probability)
			{
				return item.second;
			}
		}
	}
	return nullptr;
}

int Monster::GetDropGold() const
{
	return dropGold;
}
