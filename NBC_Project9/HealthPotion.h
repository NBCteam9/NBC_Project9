#pragma once

#include "Item.h"

class HealthPotion :public Item
{
private:
	string name;
	const int healthRestore = 50;
public:
	HealthPotion();
	bool isUsable(Character* character) const;
	string getName();
	void use(Character* character);
};