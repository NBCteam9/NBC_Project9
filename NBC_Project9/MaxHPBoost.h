#pragma once
#include "Item.h"

class MaxHPBoost : public Item
{
public:
	MaxHPBoost();
	bool IsUsable(const Character* character) const override;
	void Use(Character* character) override;
private:
	const int maxHPIncrease = 50;
};
