#include "Monster.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "MaxHPBoost.h"
#include <random>

// Monster Constructor
Monster::Monster(int level) 
{
	name = "default";
	health = 0;
	attack = 0;
	dropRate = 0;
	dropGold = 0;
}

string Monster::getName()
{
	return name;
}

int Monster::getHealth()
{
	return health;
}

int Monster::getAttack()
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

int Monster::getRandomNum(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}

Item* Monster::dropItem() 
{
	int r1 = getRandomNum(1, 100);
	int r2 = getRandomNum(1, 100);
	int itemCount = 3;

	// Ȯ��
	int probability = 100 / itemCount;

	if (r1 < dropRate) 
	{
		if (r2 < probability)
		{
			return new HealthPotion();
		}
		else if (r2 < probability * 2)
		{
			return new AttackBoost();
		} 
		else if (r2 < probability * 3)
		{
			return new MaxHPBoost();
		}
	}

	return nullptr;
}

int Monster::getDropGold() {
	return dropGold;
}