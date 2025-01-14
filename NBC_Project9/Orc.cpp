#include "Orc.h"

Orc::Orc(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);
	int goldReward = getRandomNum(15, 20);

	name = "Orc";
	health = 45 + level * (25 + healthRandomValue);
	attack = 7 + level * (6 + attackRandomValue);
	dropRate = 30;
	dropGold = getRandomNum(15, 20);
}