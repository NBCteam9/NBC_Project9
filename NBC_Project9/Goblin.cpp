#include "Goblin.h"

Goblin::Goblin(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(5, 10);

	name = "Goblin";
	health = 30 + level * (20 + healthRandomValue);
	attack = 5 + level * (6 + attackRandomValue);
	dropRate = 20;
	dropGold = goldReward;
}