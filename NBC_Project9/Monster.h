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
	virtual string getName();
	int getHealth();
	int getAttack();
	void TakeDamage(int damage);
};