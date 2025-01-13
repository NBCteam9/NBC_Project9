#include "Slime.h"

Slime::Slime(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);

	name = "Slime";
	health = 15 + level * (10 + healthRandomValue);
	attack = 2 + level * (2 + attackRandomValue);
	//dropRate = 0.1f;
}