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

void Shop::VisitShop(Character* player)
{
	cout << "Welcome to the shop!" << endl;

	while (true)
	{
		string shopOption = "";
		cout << "\nBuy : 1, Sell : 2, Exit : 0 (Current Gold : " << player->GetGold() << ") ";
		cin >> shopOption;

		if (shopOption == "0")
		{
			break;
		}
		if (shopOption.size() != 1 || shopOption[0] - '2' > 0 || shopOption[0] - '1' < 0)
		{
			cout << "\nPlease input it again" << endl;
			continue;
		}

		if (shopOption[0] == '1')
		{
			DisplayItem();
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
				if (buyIndex != 0)
				{
					BuyItem(buyIndex, player);
				}
			}
		}
		else if (shopOption[0] == '2')
		{
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
				if (sellIndex != 0) 
				{
					SellItem(sellIndex, player);
				}
			}
		}
		else
		{
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

void Shop::DisplayItem() const
{
	for (int index = 0; index < availableItems.size(); index++) 
	{
		Item* curItem = availableItems[index];
		cout << index + 1 << ". " << curItem->GetName() << " (Price : " << curItem->GetPrice() << "G)" << endl;
	}
}

void Shop::BuyItem(int selectNum, Character* player)
{
	if ((selectNum - 1) >= availableItems.size())
	{
		cout << "\nThat item does not exist in the shop." << endl;
		return;
	}

	int playerGold = player->GetGold();
	if (playerGold < availableItems[selectNum - 1]->GetPrice())
	{
		cout << "You do not have enough gold." << endl;
		return;
	}

	Item* item = GenerateItem(selectNum);

	player->SetGold(playerGold - item->GetPrice());
	cout << "You have purchased the " << item->GetName() << ". (Current Gold : " << player->GetGold() << "G)" << endl;

	vector<Item*>& playerInventory = player->GetInventory();
	playerInventory.push_back(item);
}

void Shop::SellItem(int selectNum, Character* player)
{
	vector<Item*>& playerInventory = player->GetInventory();

	if ((selectNum - 1) >= playerInventory.size())
	{
		cout << "\nThat item does not exist in your inventory." << endl;
		return;
	}

	int playerGold = player->GetGold();
	player->SetGold(playerGold + availableItems[selectNum - 1]->GetPrice() * 0.6f);
	cout << "You have sold the " << availableItems[selectNum - 1]->GetName() << ". (Current Gold : " << player->GetGold() << "G)" << endl;

	delete playerInventory[selectNum - 1];
	playerInventory.erase(playerInventory.begin() + selectNum - 1);
}

Shop::~Shop()
{
	for (Item* item : availableItems) 
	{
		delete item;
	}
}
