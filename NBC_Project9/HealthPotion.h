#pragma once

#include "Item.h"
class HealthPotion {
private:
	int const healthRestore;
	string name;
public:
	HealthPotion() : healthRestore(50) {};
	string getName();
	void use(Character* character);
};