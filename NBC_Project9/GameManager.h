#pragma once

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class GameManager
{
public:
	bool Battle(class Character* player);
	void Initialize();
	void DisplayKilledMonsters();
private:
	void AddKilledMonsters(class Monster* monster);
	void OnBattleVictory(class Character* player, class Monster* monster);
	int goldPerInterest = 10;
	int maxInterest = 10;
	unordered_map<string, int> KilledMonstersMap;
};
