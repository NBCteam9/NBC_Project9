#include "Dragon.h"

Dragon::Dragon(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(100, 300);

	name = "Dragon";
	health = 120 + level * (60 + healthRandomValue);
	attack = 15 + level * (12 + attackRandomValue);
	dropRate = 97;
	dropGold = goldReward;
}