#include "Troll.h"

Troll::Troll(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(25, 30);

	name = "Troll";
	health = 60 + level * (30 + healthRandomValue);
	attack = 10 + level * (10 + attackRandomValue);
	dropRate = 40;
	dropGold = goldReward;
}