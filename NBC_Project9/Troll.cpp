#include "Troll.h"

Troll::Troll(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);

	name = "Troll";
	health = 60 + level * (35 + healthRandomValue);
	attack = 10 + level * (9 + attackRandomValue);
	dropRate = 40;
}