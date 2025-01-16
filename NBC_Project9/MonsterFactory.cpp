#include "MonsterFactory.h"
#include <random>
#include "Monster.h"

MonsterFactory* MonsterFactory::instance = nullptr;

MonsterFactory* MonsterFactory::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new MonsterFactory();
	}
	return instance;
}

Monster* MonsterFactory::GenerateRandomMonster(int level)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);

	if (availableMonsters.size() == 0) 
	{
		cout << "ERROR // MonsterFactory's GenerateMonster -> Please Push Monster in availableMonsters" << endl;
		return nullptr;
	}

	int randValue = dis(gen) % availableMonsters.size();
	availableMonsters[randValue]->Initialize(level);
	return availableMonsters[randValue];

	/*switch (randValue)
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

	return output;*/
}

Monster* MonsterFactory::GenerateRandomBossMonster()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);

	if (availableBossMonsters.size() == 0)
	{
		cout << "ERROR // MonsterFactory's GenerateMonster -> Please Push Monster in availableBossMonsters" << endl;
	}

	int randValue = dis(gen) % availableBossMonsters.size();
	availableBossMonsters[randValue]->Initialize(BossLevel);
	return availableBossMonsters[randValue];

	/*switch (randValue)
	{
	case 0:
		output = new Dragon(15);
		break;
	default:
		cout << "ERROR : GameManager GenerateMonster randValue over" << endl;
		break;
	}

	return output;*/
}

void MonsterFactory::AddMonster(Monster* monster)
{
	availableMonsters.push_back(monster);
}

void MonsterFactory::AddBossMonster(Monster* bossMonster)
{
	availableBossMonsters.push_back(bossMonster);
}

void MonsterFactory::DestoryInstance()
{
	delete instance;
	instance = nullptr;
}

MonsterFactory::~MonsterFactory()
{
	for (Monster* monster : availableMonsters)
	{
		delete monster;
	}
	availableMonsters.clear();

	for (Monster* monster : availableBossMonsters)
	{
		delete monster;
	}
	availableBossMonsters.clear();
}
