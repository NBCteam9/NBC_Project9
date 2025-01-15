#pragma once

#include <vector>
#include <iostream>
using namespace std;

class MonsterFactory
{
public:
	static MonsterFactory* GetInstance();
	class Monster* GenerateRandomMonster(int level);
	class Monster* GenerateRandomBossMonster();
	void AddMonster(Monster* monster);
	void AddBossMonster(Monster* bossMonster);
	static void DestoryInstance();
	~MonsterFactory();
private:
	MonsterFactory() {};
	MonsterFactory(const MonsterFactory&) = delete;
	MonsterFactory& operator=(const MonsterFactory&) = delete;
	int BossLevel = 15;
	static MonsterFactory* instance;
	vector <class Monster*> availableMonsters;
	vector <class Monster*> availableBossMonsters;
};
