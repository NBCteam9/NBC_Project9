#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
	const int attackIncrease = 10;
public:
	AttackBoost();
	bool isUsable(Character* character) const override;
	void use(Character* character) override;
};