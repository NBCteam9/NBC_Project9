#pragma once

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;
class Monster
{
public:
	// constructor!!
	Monster(int level);
	// method!!
	string GetName();
	int GetHealth();
	int GetAttack();
	void TakeDamage(int damage);
	Item* DropItem();
	int GetDropGold();
protected:
	string name;
	int health;
	int attack;
	// int getRandomNum(int n, int m);
	int GetRandomNum(int min, int max);
	int dropRate;
	int dropGold;
};
