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

	void visitShop(class Character* player);

	class Item* GenerateItem(int index);

	void displayItem();

	void buyItem(int selectNum, class Character* player);

	void sellItem(int selectNum, class Character* player);

	~Shop();
};

