#pragma once

#include <vector>
#include <iostream>
using namespace std;

class GameManager
{
private:
	class Monster* GenerateMonster(int level);
	class Item* GenerateItem();
	void OnBattleVictory(class Character* player);

public:
	GameManager();

	void Battle(class Character* player);
	void DisplayInventory(class Character* player);
};