#include "Goblin.h"
#include <cstdlib>

Goblin::Goblin(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);

	name = "Goblin";
	health = 60 + level * (20 + healthRandomValue);
	attack = 11 + level * (5 + attackRandomValue);

	cout << "Goblin Spawned!!" << endl;
}