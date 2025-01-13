#pragma once

#include <vector>
#include <iostream>
using namespace std;

class GameManager
{
private:
	Monster* GenerateMonster(int level);
	Item* GenerateItem();
	void OnBattleVictory(class Character* player);

public:
	void Battle(class Character* player);
	void DisplayInventory(class Character* player);
};