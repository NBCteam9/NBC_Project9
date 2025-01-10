#pragma once

#include "Character.h"
#include <string>

using namespace std;

class Item
{
protected:
	int price;
public:
	virtual const string GetName() = 0;
	virtual void Use(Character* Character) = 0;
	const int getPrice() { return price; }
};