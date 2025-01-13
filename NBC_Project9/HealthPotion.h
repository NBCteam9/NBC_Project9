#pragma once
#include "Item.h"

class HealthPotion :public Item
{
private:
	string name;
	const int healthRestore = 50;
public:
	HealthPotion();
	bool isUsable(Character* character) const override;
	const string getName() const override;
	void use(Character* character) override;
	int getPrice() const override;
};