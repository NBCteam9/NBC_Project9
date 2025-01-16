#pragma once

#include "Character.h"
#include <string>

using namespace std;

class Item
{
public:
	Item();
	string GetName() const;
	int GetPrice() const;
	virtual bool IsUsable(const Character* character) const = 0;
	virtual void Use(Character* Character) = 0;
	virtual void PrintExplanation() = 0;
protected:
	string name;
	int price;
};
