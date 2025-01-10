#pragma once

#include "Character.h"
#include <string>

using namespace std;

class Item
{
private:
	int price;
public:
	virtual const string GetName() = 0;
	virtual void Use(Character* Character) = 0;
	const int getPrice() { return price; }
	void setPrice(int value) { price = value; }
};