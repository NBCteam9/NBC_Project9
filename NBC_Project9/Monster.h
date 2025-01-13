#pragma once

#include <iostream>
#include <string>
#include <cstdlib> // rand(), srand()
#include "Item.h"

using namespace std;
class Monster
{
protected:
	string name;
	int health;
	int attack;
	int getRandomNum(int n);
	int dropRate;
public:
	Monster(int level);

	string getName();
	int getHealth();
	int getAttack();
	void TakeDamage(int damage);
	Item* dropItem();
};