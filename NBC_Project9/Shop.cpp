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

void Shop::displayItem()
{
	for (int index = 0; index < availableItems.size(); index++) {
		Item* curItem = availableItems[index];
		cout << index + 1 << ". " << curItem->getName() << " (Price : " << curItem->getPrice() << "G)" << endl;
	}
}

void Shop::buyItem(int index, Character* player)
{
	if (index - 1 >= availableItems.size()) {
		cout << "The " << index << "th item does not exist in the shop." << endl;
		return;
	}

	Item* item = availableItems[index - 1];

	int playerGold = player->getGold();
	if (playerGold < item->getPrice()) {
		cout << "You do not have enough gold." << endl;
		return;
	}

	player->setGold(playerGold - item->getPrice());
	cout << "You have purchased the" << item->getName() << ". (Current Gold : " << player->getGold() << "G)" << endl;

	vector<Item*>& playerInventory = player->getInventory();
	playerInventory.push_back(availableItems[index - 1]);
}

void Shop::sellItem(int index, Character* player)
{
	vector<Item*>& playerInventory = player->getInventory();

	if (index - 1 >= playerInventory.size()) {
		cout << "the " << index << "th item does not exist in your inventory." << endl;
		return;
	}

	Item* item = availableItems[index - 1];

	int playerGold = player->getGold();
	player->setGold(playerGold + item->getPrice());
	cout << "You have sold the" << item->getName() << ". (Current Gold : " << player->getGold() << "G)" << endl;

	playerInventory.erase(playerInventory.begin() + index - 1);
}
