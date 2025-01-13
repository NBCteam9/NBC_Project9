#include <random>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Item.h"
#include "Slime.h"
#include "Shop.h"

Monster* GameManager::GenerateMonster(int level)
{
	Monster* output = nullptr;

	int randValue = getRandomInt() % 4;

	switch (randValue)
	{
	case 0:
		output = new Goblin(level);
		break;
	case 1:
		output = new Orc(level);
		break;
	case 2:
		output = new Troll(level);
		break;
	case 3:
		output = new Slime(level);
		break;
	default:
		cout << "ERROR : GameManager GenerateMonster randValue over" << endl;
		break;
	}

	return output;
}

Monster* GameManager::GenerateBossMonster(int level)
{
	Monster* output = nullptr;

	int randValue = getRandomInt() % 4;

	switch (randValue)
	{
	case 0:
		output = new Goblin(15);
		break;
	case 1:
		output = new Orc(15);
		break;
	case 2:
		output = new Troll(15);
		break;
	case 3:
		output = new Slime(15);
		break;
	default:
		cout << "ERROR : GameManager GenerateBossMonster randValue over" << endl;
		break;
	}

	return output;
}

void GameManager::OnBattleVictory(Character* player, Monster* monster)
{
	player->AddExperience(50);

	int curPlayerGold = player->getGold();
	player->setGold(curPlayerGold + 10 + getRandomInt() % 10);

	/*int itemDropRandom = rand() % 100;

	if (itemDropRandom < 30) {
		Item* dropItem = monster->dropItem();
		player->getInventory().push_back(dropItem);
		cout << "You got a " << dropItem->getName() << endl;
	}*/
}

int GameManager::getRandomInt()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);
	return dis(gen);
}

GameManager::GameManager()
{
	shop = new Shop();
}

void GameManager::VisitShop(Character* player)
{
	cout << "Welcome to the shop!" << endl;

	while (true)
	{
		int shopOption = 0;
		cout << "Buy : 1, Sell : 2, Exit : 0" << endl;
		cin >> shopOption;

		if (shopOption == 0) break;

		switch (shopOption)
		{
		case 1:
			shop->displayItem();
			int buyIndex;
			cout << "Choose the number of the item you wish to purchase." << endl;
			cin >> buyIndex;
			shop->buyItem(buyIndex, player);
			break;
		case 2:
			DisplayInventory(player);
			int sellIndex;
			cout << "Choose the number of the item you wish to sell." << endl;
			cin >> sellIndex;
			shop->sellItem(sellIndex, player);
			break;
		default:
			cout << "That option is not available." << endl;
			break;
		}
	}

	cout << "You exited the shop." << endl << endl;
}

bool GameManager::Battle(Character* player)
{
	Monster* monster = nullptr;

	if (player->getLevel() >= 10) {
		monster = GenerateBossMonster(player->getLevel());
		cout << "BossMonster " << monster->getName() << " appears!" << endl;
	}
	else {
		monster = GenerateMonster(player->getLevel());
		cout << "Monster " << monster->getName() << " appears!" << endl;
	}

	vector<Item*> playerInventory = player->getInventory();

	bool isPlayerTurn = true;

	while (true)
	{
		if (isPlayerTurn) {
			for (int index = playerInventory.size() - 1; index >= 0; index--) {
				if (playerInventory[index]->isUsable(player)) {
					player->UseItem(index);
				}
			}

			cout << player->getName() << " attacks the " << monster->getName() << "! " << endl;
			monster->TakeDamage(player->getAttack());

			if (monster->getHealth() <= 0) {
				cout << monster->getName() << " defeat! : Victory!" << endl << endl;
				OnBattleVictory(player, monster);
				return true;
			}
		}
		else {
			cout << player->getName() << " attacks the " << monster->getName() << "! " << endl;
			player->TakeDamage(monster->getAttack());

			if (player->getHealth() <= 0) {
				cout << player->getName() << " Defeat..." << endl;
				return false;
			}
		}

		isPlayerTurn = !isPlayerTurn;
	}
}

void GameManager::DisplayInventory(Character* player)
{
	vector<Item*> playerInventory = player->getInventory();

	for (int index = 0; index < player->getInventory().size(); index++){
		Item* item = playerInventory[index];
		cout << index << ": " << item->getName() << "(Price : " << item->getPrice() << "G)";
	}
}