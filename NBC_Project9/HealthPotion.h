#pragma once

#include "Item.h"
class HealthPotion :public Item{
private:
	int const healthRestore = 50;
	string name;
public:
	HealthPotion();
	string getName();
	void use(Character* character);
};