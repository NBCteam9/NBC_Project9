#pragma once
#include "Item.h"

class MaxHPBoost : public Item
{
private:
	const int maxHPIncrease = 50;
public:
	MaxHPBoost();
	bool isUsable(Character* character) const override;
	void use(Character* character) override;
};