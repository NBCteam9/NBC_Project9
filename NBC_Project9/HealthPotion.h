#pragma once

#include "Item.h"

class HealthPotion : public Item
{
private:
	string name;
	int healthRestore;
public:
	HealthPotion();
	string getName();
	void use(Character* character);
};