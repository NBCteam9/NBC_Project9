#include "Slime.h"

Slime::Slime(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);
	int goldReward = getRandomNum(3, 5);

	name = "Slime";
	health = 15 + level * (10 + healthRandomValue);
	attack = 2 + level * (2 + attackRandomValue);
	dropRate = 10;
	dropGold = getRandomNum(3, 5);
}