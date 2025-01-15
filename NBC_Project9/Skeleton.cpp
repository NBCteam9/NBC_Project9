#include "Skeleton.h"

Skeleton::Skeleton(int level) : Monster(level)
{
	int healthRandomValue = GetRandomNum(1, 10);
	int attackRandomValue = GetRandomNum(1, 5);
	int goldReward = GetRandomNum(10, 15);

	name = "Skeleton";
	health = 37 + level * (23 + healthRandomValue);
	attack = 6 + level * (7 + attackRandomValue);
	dropRate = 25;
	dropGold = goldReward;
}

void Skeleton::Initialize(int level)
{
	int healthRandomValue = GetRandomNum(1, 10);
	int attackRandomValue = GetRandomNum(1, 5);
	int goldReward = GetRandomNum(10, 15);

	name = "Skeleton";
	health = 37 + level * (23 + healthRandomValue);
	attack = 6 + level * (7 + attackRandomValue);
	dropRate = 25;
	dropGold = goldReward;
}
