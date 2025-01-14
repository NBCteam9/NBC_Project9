#include "Orc.h"

Orc::Orc(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(15, 20);

	name = "Orc";
	health = 45 + level * (25 + healthRandomValue);
	attack = 7 + level * (7 + attackRandomValue);
	dropRate = 30;
	dropGold = goldReward;
}