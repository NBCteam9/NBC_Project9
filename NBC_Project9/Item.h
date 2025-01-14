#pragma once

#include "Character.h"
#include <string>

using namespace std;

class Item
{
protected:
	string name;
	int price;
public:
	const string getName() const;
	int getPrice() const;
	virtual bool isUsable(Character* character) const = 0;
	virtual void use(Character* Character) = 0;
};