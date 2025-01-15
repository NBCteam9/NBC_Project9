#pragma once

#include <vector>
#include <iostream>
using namespace std;

class GameManager
{
public:
	GameManager();
	bool Battle(class Character* player);
	~GameManager();
private:
	void OnBattleVictory(class Character* player, class Monster* monster);
	class MonsterFactory* monsterFactory;
	int goldPerInterest = 10;
	int maxInterest = 10;
};
