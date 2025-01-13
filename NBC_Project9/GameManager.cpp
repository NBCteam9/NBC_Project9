#include <random>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Goblin.h"
#include "Item.h"

Monster* GameManager::GenerateMonster(int level)
{
	Monster* output = nullptr;

	int randValue = rand() % 1;

	switch (randValue)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		cout << "ERROR : GameManager GenerateMonster randValue over" << endl;
		break;
	}

	return output;
}

Item* GameManager::GenerateItem()
{
	Item* output = nullptr;

	int randValue = rand() % 1;

	switch (randValue)
	{
	case 0:
		break;
	case 1:
		break;
	default:
		cout << "ERROR : GameManager GenerateItem randValue over" << endl;
		break;
	}

	return output;
}

void GameManager::OnBattleVictory(Character* player)
{
	player->AddExperience(50);

	int curPlayerGold = player->getGold();
	player->setGold(curPlayerGold + 10 + rand() % 10);

	player->getInventory().push_back(GenerateItem());
}

GameManager::GameManager()
{
}

void GameManager::Battle(Character* player)
{
	Monster* monster = GenerateMonster(player->getLevel());
	vector<Item*> playerInventory = player->getInventory();

	bool isPlayerTurn = true;

	while (true)
	{
		if (isPlayerTurn) {
			for (int index = playerInventory.size() - 1; index >= 0; index--) {
				if (playerInventory[index]->isUsable) {
					player->UseItem(index);
				}
			}

			monster->TakeDamage(player->getAttack());
			if (monster->getHealth() <= 0) {
				OnBattleVictory(player);
				break;
			}
		}
		else {
			player->TakeDamage(monster->getAttack());
			if (player->getHealth() <= 0) {
				break;
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