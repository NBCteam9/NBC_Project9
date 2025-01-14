#pragma once

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;
class Monster
{
protected:
	string name;
	int health;
	int attack;
	// int getRandomNum(int n, int m);
	int getRandomNum(int min, int max);
	int dropRate;
	int dropGold;
public:
	// constructor!!
	Monster(int level);

	// method!!
	string getName();
	int getHealth();
	int getAttack();
	void TakeDamage(int damage);
	Item* dropItem();
	int getDropGold();
};