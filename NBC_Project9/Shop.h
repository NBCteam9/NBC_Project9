#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Shop
{ 
private:
	vector<class Item*> availableItems;

public:
	Shop();

	void displayItem();

	void buyItem(int index, class Character* player);

	void sellItem(int index, class Character* player);

	~Shop();
};

