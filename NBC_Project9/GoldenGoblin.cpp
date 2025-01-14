#include "GoldenGoblin.h"

GoldenGoblin::GoldenGoblin(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(1, 110);

	name = "GoldenGoblin";
	health = 22 + level * (13 + healthRandomValue);
	attack = 11 + level * (11 + attackRandomValue);
	dropRate = 50;
	dropGold = goldReward;
}