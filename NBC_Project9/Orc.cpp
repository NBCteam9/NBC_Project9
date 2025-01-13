#include "Orc.h"

Orc::Orc(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);

	name = "Orc";
	health = 45 + level * (30 + healthRandomValue);
	attack = 7 + level * (7 + attackRandomValue);
	dropRate = 0.3f;
}