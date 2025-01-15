#pragma once

#include <vector>
#include <iostream>
using namespace std;

class MonsterFactory
{
private:
	static MonsterFactory* instance;

	vector <class Monster*> availableMonsters;
	vector <class Monster*> availableBossMonsters;

public:
	static MonsterFactory* GetInstance();

	class Monster* GenerateRandomMonster(int level);
	class Monster* GenerateRandomBossMonster();

	void AddMonster(Monster* monster);
	void AddBossMonster(Monster* bossMonster);

	~MonsterFactory();
};