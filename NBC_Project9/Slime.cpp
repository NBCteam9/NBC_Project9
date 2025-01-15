#include "Slime.h"

Slime::Slime(int level) : Monster(level)
{
	int healthRandomValue = GetRandomNum(1, 10);
	int attackRandomValue = GetRandomNum(1, 5);
	int goldReward = GetRandomNum(4, 6);

	name = "Slime";
	health = 20 + level * (15 + healthRandomValue);
	attack = 3 + level * (4 + attackRandomValue);
	dropRate = 10;
	dropGold = goldReward;
}