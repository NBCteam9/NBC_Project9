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
	virtual const string getName() const = 0;
	virtual void use(Character* Character) = 0;
	virtual bool isUsable() const = 0;
	virtual int getPrice() const = 0;
};