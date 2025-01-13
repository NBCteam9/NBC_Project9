#include "Goblin.h"
#include <cstdlib>

Goblin::Goblin(int level) : Monster(level)
{
	int randomValue1 = rand() % 10;
	int randomValue2 = rand() % 5;

	name = "Goblin";
	health = 60 + level * (20+randomValue1);
	attack = 11 + level * (5+randomValue2);

	cout << "Goblin Spawned!!" << endl;
}