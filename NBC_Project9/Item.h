#pragma once

#include "Character.h"
#include "AttackBoost.h"
#include "HealthPotion.h"
#include <string>

using namespace std;

class Item
{
protected:
	int price;
public:
	virtual bool isUsable(Character* character) const = 0;
	virtual const string getName() const = 0;
	virtual void use(Character* Character) = 0;
	virtual int getPrice() const = 0;
};