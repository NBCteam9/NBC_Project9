#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

Shop::Shop()
{
	availableItems.push_back(new HealthPotion());
	availableItems.push_back(new AttackBoost());
}

void Shop::visitShop(Character* player)
{
	cout << "Welcome to the shop!" << endl;

	while (true)
	{
		int shopOption = 0;
		cout << "\nBuy : 1, Sell : 2, Exit : 0 (Current Gold : " << player->getGold() << ") ";
		cin >> shopOption;

		if (shopOption == 0) break;

		switch (shopOption)
		{
		case 1:
			displayItem();
			int buyIndex;
			cout << "Choose the number of the item you wish to purchase. (Cancel : 0) ";
			cin >> buyIndex;
			if (buyIndex == 0) break;
			buyItem(buyIndex, player);
			break;
		case 2:
			player->DisplayInventory();
			int sellIndex;
			cout << "Choose the number of the item you wish to sell. (Cancel : 0) ";
			cin >> sellIndex;
			if (sellIndex == 0) break;
			sellItem(sellIndex, player);
			break;
		default:
			cout << "That option is not available.\n" << endl;
			break;
		}
	}

	cout << "You exited the shop." << endl;
}

Item* Shop::GenerateItem(int index)
{
	Item* output = nullptr;

	switch (index)
	{
	case 1:
		output = new HealthPotion();
		break;
	case 2:
		output = new AttackBoost();
		break;
	default:
		cout << "ERROR : GameManager GenerateMonster randValue over" << endl;
		break;
	}

	return output;
}

void Shop::displayItem()
{
	for (int index = 0; index < availableItems.size(); index++) 
	{
		Item* curItem = availableItems[index];
		cout << index + 1 << ". " << curItem->getName() << " (Price : " << curItem->getPrice() << "G)" << endl;
	}
}

void Shop::buyItem(int index, Character* player)
{
	if (index - 1 >= availableItems.size()) 
	{
		cout << "\nThe " << index << "th item does not exist in the shop." << endl;
		return;
	}

	int playerGold = player->getGold();
	if (playerGold < availableItems[index - 1]->getPrice()) 
	{
		cout << "You do not have enough gold." << endl;
		return;
	}

	Item* item = GenerateItem(index);

	player->setGold(playerGold - item->getPrice());
	cout << "You have purchased the " << item->getName() << ". (Current Gold : " << player->getGold() << "G)" << endl;

	vector<Item*>& playerInventory = player->getInventory();
	playerInventory.push_back(item);
}

void Shop::sellItem(int index, Character* player)
{
	vector<Item*>& playerInventory = player->getInventory();

	if (index - 1 >= playerInventory.size()) 
	{
		cout << "\nthe " << index << "th item does not exist in your inventory." << endl;
		return;
	}

	int playerGold = player->getGold();
	player->setGold(playerGold + availableItems[index - 1]->getPrice() * 0.6f);
	cout << "You have sold the " << availableItems[index - 1]->getName() << ". (Current Gold : " << player->getGold() << "G)" << endl;

	delete playerInventory[index - 1];
	playerInventory.erase(playerInventory.begin() + index - 1);
}

Shop::~Shop()
{
	for (Item* item : availableItems) 
	{
		delete item;
	}
}
