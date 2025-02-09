#include "GoldenGoblin.h"

GoldenGoblin::GoldenGoblin(int level) : Monster(level)
{
	int healthRandomValue = GetRandomNum(1, 10);
	int attackRandomValue = GetRandomNum(1, 5);
	int goldReward = GetRandomNum(1, 110);

	name = "GoldenGoblin";
	health = 22 + level * (13 + healthRandomValue);
	attack = 33 + level * (20 + attackRandomValue);
	dropRate = 50;
	dropGold = goldReward;
}

void GoldenGoblin::Initialize(int level)
{
	int healthRandomValue = GetRandomNum(1, 10);
	int attackRandomValue = GetRandomNum(1, 5);
	int goldReward = GetRandomNum(1, 110);

	name = "GoldenGoblin";
	health = 22 + level * (13 + healthRandomValue);
	attack = 33 + level * (20 + attackRandomValue);
	dropRate = 50;
	dropGold = goldReward;
}
