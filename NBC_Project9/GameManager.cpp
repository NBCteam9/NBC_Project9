#include <random>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Item.h"
#include "Slime.h"

Monster* GameManager::GenerateMonster(int level)
{
	Monster* output = nullptr;

	int randValue = rand() % 1;

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

void GameManager::OnBattleVictory(Character* player, Monster* monster)
{
	player->AddExperience(50);

	int curPlayerGold = player->getGold();
	player->setGold(curPlayerGold + 10 + rand() % 10);

	int itemDropRandom = rand() % 100;

	if (itemDropRandom < 30) {
		Item* dropItem = monster->dropItem();
		player->getInventory().push_back(dropItem);
		cout << "You got a " << dropItem->getName() << endl;
	}
}

bool GameManager::Battle(Character* player)
{
	Monster* monster = GenerateMonster(player->getLevel());
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

			monster->TakeDamage(player->getAttack());
			if (monster->getHealth() <= 0) {
				OnBattleVictory(player, monster);
				cout << "Victory!" << endl;
				return true;
			}
		}
		else {
			player->TakeDamage(monster->getAttack());
			if (player->getHealth() <= 0) {
				cout << "Defeat..." << endl;
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