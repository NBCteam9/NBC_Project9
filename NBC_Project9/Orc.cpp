#include "Orc.h"


Orc::Orc(int level) : Monster(level)
{
	int randomValue1 = rand() % 10;
	int randomValue2 = rand() % 5;
	name = "Orc";
	health = 60 + level * (30 + randomValue1); // 30~40
	attack = 11 + level * (15 + randomValue2);  // 15~25
	cout << "Orc Spawned!!" << endl;
}