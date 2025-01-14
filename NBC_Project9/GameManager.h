#pragma once

#include <vector>
#include <iostream>
using namespace std;

class GameManager
{
private:
	void OnBattleVictory(class Character* player, class Monster* monster);
	class MonsterFactory* monsterFactory;

public:
	GameManager();

	bool Battle(class Character* player);

	~GameManager();
};