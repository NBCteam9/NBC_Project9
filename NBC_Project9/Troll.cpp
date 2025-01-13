#include "Troll.h"

Troll::Troll(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);

	name = "Troll";
	health = 60 + level * (40 + healthRandomValue);
	attack = 10 + level * (10 + attackRandomValue);
	dropRate = 40;
}