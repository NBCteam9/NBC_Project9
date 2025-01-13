#pragma once

#include <vector>
#include <iostream>
using namespace std;

class GameManager
{
private:
	class Monster* GenerateMonster(int level);
	void OnBattleVictory(class Character* player, class Monster* monster);

	class Shop* shop;

public:
	GameManager();

	void VisitShop(class Character* player);
	bool Battle(class Character* player);
	void DisplayInventory(class Character* player);
};