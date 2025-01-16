#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Shop
{
public:
	Shop();
	~Shop();
	void VisitShop(class Character* player);
	class Item* GenerateItem(int index);
	void DisplayItem() const;
	void BuyItem(int selectNum, class Character* player);
	void SellItem(int selectNum, class Character* player);
private:
	vector<class Item*> availableItems;
};
