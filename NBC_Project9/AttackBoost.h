#pragma once
#include "Item.h"

class AttackBoost : public Item
{
public:
	AttackBoost();
	bool IsUsable(const Character* character) const override;
	void Use(Character* character) override;
	void PrintExplanation() override;
private:
	const int attackIncrease = 10;
};
