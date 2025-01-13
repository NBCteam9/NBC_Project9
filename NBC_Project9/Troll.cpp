#include "Troll.h"

Troll::Troll(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);

	name = "Troll";
	health = 120 + level * (40 + healthRandomValue);
	attack = 20 + level * (10 + attackRandomValue);

	cout << "Troll Spawned!!" << endl;
}