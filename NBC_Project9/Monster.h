#pragma once

#include <iostream>
#include <string>

using namespace std;
class Monster
{
protected:
	string name;
	int health;
	int attack;
public:
	Monster(string n, int h, int a);	

	string getName();
	int getHealth();
	int getAttack();
	void TakeDamage(int damage);
};