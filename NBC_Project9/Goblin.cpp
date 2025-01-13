#include "Goblin.h"

Goblin::Goblin(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);

	name = "Goblin";
	health = 30 + level * (20 + healthRandomValue);
	attack = 5 + level * (5 + attackRandomValue);
	dropRate = 20;
	dropGold = getRandomNum(5, 10);
}