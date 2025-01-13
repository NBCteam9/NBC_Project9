#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
	string name;
	const int attackIncrease = 10;
public:
	AttackBoost();
	bool isUsable(Character* character) const override;
	const string getName() const override;
	void use(Character* Character) override;
	int getPrice() const override;
};