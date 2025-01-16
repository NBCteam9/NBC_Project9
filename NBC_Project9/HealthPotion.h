#pragma once
#include "Item.h"

class HealthPotion :public Item
{
public:
	HealthPotion();
	bool IsUsable(const Character* character) const override;
	void Use(Character* character) override;
	void PrintExplanation() override;
private:
	const int healthRestore = 50;
};
