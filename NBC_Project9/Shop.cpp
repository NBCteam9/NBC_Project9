#include <sstream>
#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "MaxHPBoost.h"

Shop::Shop()
{
	availableItems.push_back(new HealthPotion());
	availableItems.push_back(new AttackBoost());
	availableItems.push_back(new MaxHPBoost());
}

void Shop::visitShop(Character* player)
{
	cout << "Welcome to the shop!" << endl;

	while (true)
	{
		string shopOption = "";
		cout << "\nBuy : 1, Sell : 2, Exit : 0 (Current Gold : " << player->getGold() << ") ";
		cin >> shopOption;

		if (shopOption == "0") break;

		if (shopOption.size() != 1 || shopOption[0] - '2' > 0 || shopOption[0] - '1' < 0) {
			cout << "\nPlease input it again" << endl;
			continue;
		}

		if (shopOption[0] == '1') {
			displayItem();
			cout << "Choose the number of the item you wish to purchase. (Cancel : 0) ";

			string buyInput;
			stringstream ss;
			int buyIndex;

			cin >> buyInput;
			ss << buyInput;
			ss >> buyIndex;

			if (ss.fail()) 
			{
				cout << "\nPlease input it again" << endl;
				continue;
			}
			else 
			{
				buyItem(buyIndex, player);
			}
		}
		else if (shopOption[0] == '2') {
			player->DisplayInventory();
			cout << "Choose the number of the item you wish to sell. (Cancel : 0) ";

			string sellInput;
			stringstream ss;
			int sellIndex;

			cin >> sellInput;
			ss << sellInput;
			ss >> sellIndex;

			if (ss.fail()) 
			{
				cout << "\nPlease input it again" << endl;
				continue;
			}
			else 
			{
				sellItem(sellIndex, player);
			}
		}
		else {
			cout << "That option is not available.\n" << endl;
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
	case 3:
		output = new MaxHPBoost();
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
		cout << "\nThat item does not exist in the shop." << endl;
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
		cout << "\nThat item does not exist in your inventory." << endl;
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
