#pragma once

#include "Character.h"
#include <string>

using namespace std;

class Item
{
private:
	string name;
public:
	virtual const string GetName();
	virtual void Use(Character* Character) = 0;
};