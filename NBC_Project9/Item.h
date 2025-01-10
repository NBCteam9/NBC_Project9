#pragma once

#include "Character.h"
#include <string>

using namespace std;

class Item
{
private:
	string name;
public:
	string GetName();
	void Use(Character* Character);
};