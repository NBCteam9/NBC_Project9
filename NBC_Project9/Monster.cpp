#include "Monster.h"

Monster::Monster(string n, int h, int a) : name(n), health(h), attack(a) {
	cout << "monster spawn!" << endl;
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
	health -= damage;

	if (health <= 0)
	{
		cout << name << "몬스터가 쓰러졌다" << endl;
		health = 0;
	}
	else
	{
		cout << name << "몬스터가" << damage << "만큼 피해를 입음" << "남은 몬스터의 체력:" << health << endl;
	}
}