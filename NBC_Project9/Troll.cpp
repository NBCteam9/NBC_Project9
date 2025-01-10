#include "Troll.h"

Troll::Troll()
{
	name = "Troll";
	health = 500;
	attack = 50;
}
string Troll::getName()
{

	return name;
}

int Troll::getAttack()
{
	return attack;
}

int Troll::getHealth()
{
	return health;
}