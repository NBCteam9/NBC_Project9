#include "Monster.h"

Monster::Monster(int level) : name("default"), health(0), attack(0) {}

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

int Monster::getRandomNum(int n) {
	return rand() % n;
}