#include "Dragon.h"

Dragon::Dragon(int level) : Monster(level)
{
	int healthRandomValue = GetRandomNum(1, 10);
	int attackRandomValue = GetRandomNum(1, 5);
	int goldReward = GetRandomNum(100, 300);

	name = "Dragon";
	health = 80 + level * (42 + healthRandomValue);
	attack = 11 + level * (10 + attackRandomValue);
	dropRate = 97;
	dropGold = goldReward;
}