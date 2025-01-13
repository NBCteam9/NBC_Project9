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
	int getRandomNum(int end);
	// int getRandomNum(int n, int m);
	int getRandomNum(int min, int max);
	int dropRate;
public:
	Monster(int level);

	string getName();
	int getHealth();
	int getAttack();
	void TakeDamage(int damage);
	Item* dropItem();
};