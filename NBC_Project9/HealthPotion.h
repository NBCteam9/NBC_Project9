#pragma once
#include "Item.h"

class HealthPotion :public Item
{
private:
	const int healthRestore = 50;
public:
	HealthPotion();
	bool isUsable(Character* character) const override;
	void use(Character* character) override;
};