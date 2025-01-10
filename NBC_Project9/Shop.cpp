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
		cout << index << " : " << curItem->getName() << " : " << curItem->getPrice() << "G" << endl;
	}
}

void Shop::buyItem(int index, Character* player)
{
	if (index >= availableItems.size()) {
		cout << "ERROR : Shop->buyItem : availableItems의 범위를 벗어났습니다. : " << index << endl;
		return;
	}
	Item* item = availableItems[index];

	//플레이어 골드 줄이기 구현 & 골드량 체크
	int playerGold = player->getGold();
	if (playerGold < item->getPrice()) {
		cout << "골드가 부족합니다." << endl;
		return;
	}
	else {
		player->setGold(playerGold - item->getPrice());
		cout << item->getName() << "을/를 구매했습니다. (남은 골드 : " << player->getGold() << ")" << endl;
	}

	//플레이어 인벤토리에 아이템 추가
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
	Item* item = availableItems[index];

	//플레이어 골드 늘리기 구현
	int playerGold = player->getGold();
	player->setGold(playerGold + item->getPrice());
	cout << item->getName() << "을/를 판매했습니다. (남은 골드 : " << player->getGold() << ")" << endl;

	//플레이어 인벤토리에 아이템 제거
	playerInventory.erase(playerInventory.begin() + index);
}
