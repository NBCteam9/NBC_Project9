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
	vector<Item*>& playerInventory = player->GetInventory();

	cout << "\n====================\n" << endl;
	cout << "상점에 오신걸 환영합니다!" << endl;

	while (true)
	{
		string shopOption = "";
		cout << "\n구매 : 1, 판매 : 2, 나가기 : 0 (현재 골드 : " << player->GetGold() << ") ";
		cin >> shopOption;
		cout << "\n====================\n" << endl;
		if (shopOption == "0")
		{
			break;
		}
		if (shopOption.size() != 1 || shopOption[0] - '2' > 0 || shopOption[0] - '1' < 0)
		{
			cout << "다시 입력해주세요." << endl;
			continue;
		}

		if (shopOption[0] == '1')
		{
			DisplayItem();
			cout << "\n구매를 원하는 아이템 번호를 입력해주세요. (취소 : 0) ";

			string buyInput;
			stringstream ss;
			int buyIndex;

			cin >> buyInput;
			ss << buyInput;
			ss >> buyIndex;

			if (ss.fail()) 
			{
				cout << "\n다시 입력해주세요." << endl;
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
			for (int i = 0; i < playerInventory.size(); i++) {
				cout << i + 1 << ": " << playerInventory[i]->GetName() << " (가격 : " << (int)(playerInventory[i]->GetPrice() * sellPriceRate) << "G)" << endl;
			}

			cout << "\n판매를 원하는 아이템 번호를 입력해주세요. (취소 : 0) ";

			string sellInput;
			stringstream ss;
			int sellIndex;

			cin >> sellInput;
			ss << sellInput;
			ss >> sellIndex;

			if (ss.fail()) 
			{
				cout << "\n다시 입력해주세요." << endl;
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

	cout << "상점에서 나왔습니다." << endl;
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
		cout << index + 1 << ". " << curItem->GetName() << " (가격 : " << curItem->GetPrice() << "G)";
		cout << " : ";
		curItem->PrintExplanation();
		cout << endl;
	}
}

void Shop::BuyItem(int selectNum, Character* player)
{
	if ((selectNum - 1) >= availableItems.size())
	{
		cout << "\n상점에 그런 아이템은 없습니다." << endl;
		return;
	}

	int playerGold = player->GetGold();
	if (playerGold < availableItems[selectNum - 1]->GetPrice())
	{
		cout << "\n골드가 부족합니다." << endl;
		return;
	}

	Item* item = GenerateItem(selectNum);

	player->SetGold(playerGold - item->GetPrice());
	cout << "\n" << item->GetName() << " 구매했습니다. (현재 골드 : " << player->GetGold() << "G)" << endl;

	vector<Item*>& playerInventory = player->GetInventory();
	playerInventory.push_back(item);
}

void Shop::SellItem(int selectNum, Character* player)
{
	vector<Item*>& playerInventory = player->GetInventory();

	if ((selectNum - 1) >= playerInventory.size())
	{
		cout << "\n인벤토리에 그런 아이템은 없습니다." << endl;
		return;
	}

	int playerGold = player->GetGold();

	player->SetGold(playerGold + playerInventory[selectNum - 1]->GetPrice() * sellPriceRate);

	cout << "\n" << playerInventory[selectNum - 1]->GetName() << " 판매했습니다. (현재 골드 : " << player->GetGold() << "G)" << endl;

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
