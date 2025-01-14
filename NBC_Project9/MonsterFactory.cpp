#include "MonsterFactory.h"
#include <random>
#include "Monster.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Slime.h"

Monster* MonsterFactory::GenerateMonster(int level)
{
	Monster* output = nullptr;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);

	int randValue = dis(gen) % 4;

	switch (randValue)
	{
	case 0:
		output = new Goblin(level);

		break;
	case 1:
		output = new Orc(level);
		break;
	case 2:
		output = new Troll(level);
		break;
	case 3:
		output = new Slime(level);
		break;
	default:
		cout << "ERROR : GameManager GenerateMonster randValue over" << endl;
		break;
	}

	return output;
}
