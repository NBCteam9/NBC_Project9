#include <random>
#include <Windows.h>
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
	player->setGold(curPlayerGold + monster->getDropGold());

	Item* dropItem = monster->dropItem();

	if (dropItem != nullptr) {
		player->getInventory().push_back(dropItem);
	}
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

bool GameManager::Battle(Character* player)
{
	Monster* monster = nullptr;
	if (player->getLevel() >= 10) {
		monster = GenerateBossMonster(player->getLevel());
		cout << "BossMonster " << monster->getName() << " appears!" << endl;
		bIsBoss = true;
	}
	else {
		monster = GenerateMonster(player->getLevel());
		cout << "Monster " << monster->getName() << " appears!" << endl;
	}
	Sleep(500);

	vector<Item*>& playerInventory = player->getInventory();

	bool isPlayerTurn = true;

	while (true)
	{
		if (isPlayerTurn) {
			for (int index = playerInventory.size() - 1; index >= 0; index--) {
				if (playerInventory[index]->isUsable(player)) {
					player->UseItem(index);
				}
			}

			cout << player->getName() << " attacks the " << monster->getName() << "! ";
			monster->TakeDamage(player->getAttack());

			if (monster->getHealth() <= 0) {
				cout << monster->getName() << " defeat! : Victory!" << endl;
				cout << "\n====================\n" << endl;
				if (bIsBoss) return true;

				OnBattleVictory(player, monster);
				player->DisplayStatus();
				player->DisplayInventory();
				return true;
			}
		}
		else {
			cout << monster->getName() << " attacks the " << player->getName() << "! ";
			player->TakeDamage(monster->getAttack());

			if (player->getHealth() <= 0) {
				cout << player->getName() << " Defeat..." << endl;
				return false;
			}
		}

		isPlayerTurn = !isPlayerTurn;
		Sleep(500);
	}

	delete monster;
}

GameManager::~GameManager()
{
	delete shop;
}
