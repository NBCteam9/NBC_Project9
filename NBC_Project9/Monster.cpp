#include "Monster.h"

Monster::Monster(int level) : name("default"), health(0), attack(0) {
	cout << "monster spawn!" << endl;
}

string Monster::getName()
{
	cout << name << endl;
	return name;
}

int Monster::getHealth()
{
	cout << health << endl;
	return health;
}

int Monster::getAttack()
{
	cout << attack << endl;
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