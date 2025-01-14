#pragma once

#include <vector>
#include <iostream>
using namespace std;

class GameManager
{
private:
	class Monster* GenerateMonster(int level);
	class Monster* GenerateBossMonster(int level);
	void OnBattleVictory(class Character* player, class Monster* monster);
	int getRandomInt();
	class Shop* shop;

	bool bIsBoss = false;

public:
	GameManager();

	bool Battle(class Character* player);

	~GameManager();
};