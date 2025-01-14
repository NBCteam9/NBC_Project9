#include "Zombie.h"

Zombie::Zombie(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(20, 25);

	name = "Zombie";
	health = 52 + level * (28 + healthRandomValue);
	attack = 8 + level * (9 + attackRandomValue);
	dropRate = 35;
	dropGold = goldReward;
}