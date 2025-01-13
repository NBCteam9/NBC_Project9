#pragma once

#include "Item.h"
class HealPotion {
private:
	int const healthRestore;
	string name;
public:
	HealPotion() : healthRestore(50) {};
	string getName();
	void use(Character* character);
};