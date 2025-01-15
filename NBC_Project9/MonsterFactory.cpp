#include "MonsterFactory.h"
#include <random>
#include "MonsterList.h"

Monster* MonsterFactory::GenerateMonster(int level)
{
	Monster* output = nullptr;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);

	int randValue = dis(gen) % 7;

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
	case 4:
		output = new Skeleton(level);
		break;
	case 5:
		output = new Zombie(level);
		break;
	case 6:
		output = new Wolf(level);
		break;
	case 7:
		output = new GoldenGoblin(level);
		break;
	default:
		cout << "ERROR : GameManager GenerateMonster randValue over" << endl;
		break;
	}

	return output;
}

Monster* MonsterFactory::GenerateBossMonster()
{
	Monster* output = nullptr;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);

	int randValue = dis(gen) % 1;

	switch (randValue)
	{
	case 0:
		output = new Dragon(15);
		break;
	default:
		cout << "ERROR : GameManager GenerateMonster randValue over" << endl;
		break;
	}

	return output;
}