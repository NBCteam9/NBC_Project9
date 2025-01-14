#include "Skeleton.h"

Skeleton::Skeleton(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(10, 15);

	name = "Skeleton";
	health = 37 + level * (23 + healthRandomValue);
	attack = 6 + level * (6 + attackRandomValue);
	dropRate = 25;
	dropGold = goldReward;
}