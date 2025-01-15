#include "Goblin.h"

Goblin::Goblin(int level) : Monster(level)
{
	int healthRandomValue = GetRandomNum(1, 10);
	int attackRandomValue = GetRandomNum(1, 5);
	int goldReward = GetRandomNum(5, 10);

	name = "Goblin";
	health = 30 + level * (20 + healthRandomValue);
	attack = 5 + level * (6 + attackRandomValue);
	dropRate = 20;
	dropGold = goldReward;
}