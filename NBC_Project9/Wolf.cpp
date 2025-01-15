#include "Wolf.h"

Wolf::Wolf(int level) : Monster(level)
{
	int healthRandomValue = GetRandomNum(1, 10);
	int attackRandomValue = GetRandomNum(1, 5);
	int goldReward = GetRandomNum(4, 8);

	name = "Wolf";
	health = 25 + level * (18 + healthRandomValue);
	attack = 4 + level * (5 + attackRandomValue);
	dropRate = 15;
	dropGold = goldReward;
}