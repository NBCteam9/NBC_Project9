#pragma once

#include "Character.h"
#include "Monster.h"
#include "Goblin.h"
#include "Orc.h"

class GameManager
{
public:
	Monster* GenerateMonster(int level);
	void Battle(Character* player);
	void DisplayInventory(Character* player);
};