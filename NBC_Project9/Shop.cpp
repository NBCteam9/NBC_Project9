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
		cout << "ERROR : Shop->buyItem : availableItems�� ������ ������ϴ�. : " << index << endl;
		return;
	}

	//�÷��̾��� ��� �ּ���...
	//�÷��̾� ��� ���̱� ���� & ��差 üũ

	vector<Item*>& playerInventory = player->getInventory();
	playerInventory.push_back(availableItems[index]);
}

void Shop::sellItem(int index, Character* player)
{
	vector<Item*>& playerInventory = player->getInventory();

	if (index >= playerInventory.size()) {
		cout << "ERROR : Shop->sellItem : playerInventory�� ������ ������ϴ�. : " << index << endl;
		return;
	}

	//�÷��̾��� ��� �ּ���...
	//�÷��̾� ��� �ø��� ����

	playerInventory.erase(playerInventory.begin() + index);
}
