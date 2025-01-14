#include "Monster.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <random>

Monster::Monster(int level) : name("default"), health(0), attack(0), dropRate(0) {}

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
	cout << preHp << " -> " << health << endl;
}

int Monster::getRandomNum(int end) {
	return rand() % end;
}

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

Item* Monster::dropItem() {
	int r1 = getRandomNum(100);
	int r2 = getRandomNum(100);

	if (r1 < dropRate) {
		if (r2 < 50) {
			return new HealthPotion();
		}
		else
		{
			return new AttackBoost();
		}
	}

	return nullptr;
}

int Monster::getDropGold() {
	return dropGold;
}