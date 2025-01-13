#pragma once

#include <iostream>
#include <string>
#include "Item.h"
#include <cstdlib> // rand(), srand()

using namespace std;
class Monster
{
protected:
	string name;
	int health;
	int attack;
public:
	Monster(int level);

	string getName();
	int getHealth();
	int getAttack();
	void TakeDamage(int damage);
	Item* dropItem();
	int getRandomNum();
};