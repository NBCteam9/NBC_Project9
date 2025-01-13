#include "Orc.h"


Orc::Orc(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);

	name = "Orc";
	health = 90 + level * (30 + healthRandomValue);
	attack = 15 + level * (7 + attackRandomValue);

	cout << "Orc Spawned!!" << endl;
}