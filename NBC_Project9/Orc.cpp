#include "Orc.h"

Orc::Orc(int level) : Monster(level)
{
	int healthRandomValue = GetRandomNum(1, 10);
	int attackRandomValue = GetRandomNum(1, 5);
	int goldReward = GetRandomNum(15, 20);

	name = "Orc";
	health = 45 + level * (25 + healthRandomValue);
	attack = 7 + level * (8 + attackRandomValue);
	dropRate = 30;
	dropGold = goldReward;
}

void Orc::Initialize(int level)
{
	int healthRandomValue = GetRandomNum(1, 10);
	int attackRandomValue = GetRandomNum(1, 5);
	int goldReward = GetRandomNum(15, 20);

	name = "Orc";
	health = 45 + level * (25 + healthRandomValue);
	attack = 7 + level * (8 + attackRandomValue);
	dropRate = 30;
	dropGold = goldReward;
}
