#include "Goblin.h"
#include <cstdlib> // rand(), srand()

Goblin::Goblin(int level) : Monster(level)
{
	int randomValue1 = rand() % 10;
	int randomValue2 = rand() % 5;
	name = "Goblin";
	health = 60 + level * (20+randomValue1); // 20~30
	attack = 11 + level * (5+randomValue2);  // 5~10
	cout << "Goblin Spawned!!" << endl;
}