#pragma once

#include <vector>
#include <iostream>
using namespace std;

class GameManager
{
public:
	bool Battle(class Character* player);

private:
	void OnBattleVictory(class Character* player, class Monster* monster);
	int goldPerInterest = 10;
	int maxInterest = 10;
};
