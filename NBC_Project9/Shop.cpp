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
		cout << index << ". " << curItem->getName() << " (Price : " << curItem->getPrice() << "G)" << endl;
	}
}

void Shop::buyItem(int index, Character* player)
{
	//�ε��� üũ
	if (index >= availableItems.size()) {
		cout << "The  " << index << "��° ��ǰ�� �������� �ʽ��ϴ�." << endl;
		return;
	}

	Item* item = availableItems[index];

	//��差 üũ
	int playerGold = player->getGold();
	if (playerGold < item->getPrice()) {
		cout << "��尡 �����մϴ�." << endl;
		return;
	}

	//�÷��̾� ��� ���̱�
	player->setGold(playerGold - item->getPrice());
	cout << item->getName() << "��/�� �����߽��ϴ�. (���� ��� : " << player->getGold() << ")" << endl;

	//�÷��̾� �κ��丮�� ������ �߰�
	vector<Item*>& playerInventory = player->getInventory();
	playerInventory.push_back(availableItems[index]);
}

void Shop::sellItem(int index, Character* player)
{
	vector<Item*>& playerInventory = player->getInventory();

	//�ε��� üũ
	if (index >= playerInventory.size()) {
		cout << "�κ��丮�� " << index << "��° �������� �������� �ʽ��ϴ�." << endl;
		return;
	}

	Item* item = availableItems[index];

	//�÷��̾� ��� �ø���
	int playerGold = player->getGold();
	player->setGold(playerGold + item->getPrice());
	cout << item->getName() << "��/�� �Ǹ��߽��ϴ�. (���� ��� : " << player->getGold() << ")" << endl;

	//�÷��̾� �κ��丮�� ������ ����
	playerInventory.erase(playerInventory.begin() + index);
}
