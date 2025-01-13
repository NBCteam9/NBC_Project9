#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
	string name;
	int attackIncrease;
public:
	AttackBoost();
	const string getName() const;
	void use(Character* Character);
	int getPrice() const;
};