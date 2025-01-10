#include "Slime.h"


Slime::Slime()
{
	name = "Slime";
	health = 50;
	attack = 5;
}
string Slime::getName()
{

	return name;
}

int Slime::getAttack()
{
	return attack;
}

int Slime::getHealth()
{
	return health;
}