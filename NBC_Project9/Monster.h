#pragma once
#include <iostream>

using namespace std;
class Monster
{
private:
	string name;
	int health;
	int attack;
public:
	string getName();
	int getHealth();
	int getAttack();
	void TakeDamage(int damage);
};