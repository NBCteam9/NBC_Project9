#include "Wolf.h"

Wolf::Wolf(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(4, 8);

	name = "Wolf";
	health = 25 + level * (18 + healthRandomValue);
	attack = 4 + level * (4 + attackRandomValue);
	dropRate = 15;
	dropGold = goldReward;
}