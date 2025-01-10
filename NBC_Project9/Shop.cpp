#include "Shop.h"
#include "Character.h"

Shop::Shop()
{
}

void Shop::displayItem()
{
}

void Shop::buyItem(int index, Character* player)
{
	if (index >= availableItems.size()) {
		return;
	}

	//player->
}

void Shop::sellItem(int index, Character* player)
{
}
