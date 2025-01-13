#include "Slime.h"


Slime::Slime(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(10);
	int attackRandomValue = getRandomNum(5);

	name = "Slime";
	health = 30 + level * (10 + healthRandomValue);
	attack = 5 + level * (2 + attackRandomValue);

	cout << "Slime Spawned!!" << endl;
}