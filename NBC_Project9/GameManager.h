#pragma once

#include <vector>
#include <iostream>
using namespace std;

class GameManager
{
private:
	Monster* GenerateMonster(int level);
	vector<class Monster*> MonsterTypeList;

public:
	void AddMonsterType(class Monster* monster);
	void Battle(class Character* player);
	void DisplayInventory(class Character* player);
};