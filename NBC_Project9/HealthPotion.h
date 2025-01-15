#pragma once
#include "Item.h"

class HealthPotion :public Item
{
public:
	HealthPotion();
	bool IsUsable(Character* character) const override;
	void Use(Character* character) override;
private:
	const int healthRestore = 50;
};
