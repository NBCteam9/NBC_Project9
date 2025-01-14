#include "GoldenGoblin.h"

GoldenGoblin::GoldenGoblin(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(1, 90);

	name = "GoldenGoblin";
	health = 22 + level * (13 + healthRandomValue);
	attack = 11 + level * (10 + attackRandomValue);
	dropRate = 50;
	dropGold = goldReward;
}