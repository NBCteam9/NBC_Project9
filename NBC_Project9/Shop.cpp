#include "Shop.h"
#include "Character.h"
#include "Item.h"

Shop::Shop()
{
}

void Shop::displayItem()
{
	for (int index = 0; index < availableItems.size(); index++) {
		Item* curItem = availableItems[index];
		cout << index << " : " << curItem->GetName() << " : " << curItem->getPrice() << "G" << endl;
	}
}

void Shop::buyItem(int index, Character* player)
{
	if (index >= availableItems.size()) {
		cout << "ERROR : Shop->buyItem : availableItems의 범위를 벗어났습니다. : " << index << endl;
		return;
	}

	//플레이어의 골드 주세요...
	//플레이어 골드 줄이기 구현 & 골드량 체크

	vector<Item*>& playerInventory = player->getInventory();
	playerInventory.push_back(availableItems[index]);
}

void Shop::sellItem(int index, Character* player)
{
	vector<Item*>& playerInventory = player->getInventory();

	if (index >= playerInventory.size()) {
		cout << "ERROR : Shop->sellItem : playerInventory의 범위를 벗어났습니다. : " << index << endl;
		return;
	}

	//플레이어의 골드 주세요...
	//플레이어 골드 늘리기 구현

	playerInventory.erase(playerInventory.begin() + index);
}
