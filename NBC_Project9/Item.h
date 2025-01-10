#pragma once
#include "Character.h"
class Item
{
private:
	string name;
public:
	string GetName();
	void Use(Character* Character);
};