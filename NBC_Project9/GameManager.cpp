#include <random>
#include <Windows.h>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "MonsterFactory.h"

void GameManager::OnBattleVictory(Character* player, Monster* monster)
{
	int curPlayerGold = player->getGold() + monster->getDropGold();
	int interest = curPlayerGold / goldPerInterest;
	if (interest > maxInterest)
	{
		interest = maxInterest;
	}
	cout << "Get Interest : " << interest << " (Max Interest : " << maxInterest << ", Current Gold : " << curPlayerGold << ")\n" << endl;

	player->AddExperience(50);

	player->setGold(curPlayerGold + interest);

	Item* dropItem = monster->dropItem();

	if (dropItem != nullptr) 
	{
		player->getInventory().push_back(dropItem);
	}
}

GameManager::GameManager()
{
	monsterFactory = new MonsterFactory();
}

bool GameManager::Battle(Character* player)
{
	Monster* monster = nullptr;

	if (player->getLevel() >= 10) 
	{
		monster = monsterFactory->GenerateBossMonster();
		cout << "BossMonster " << monster->getName() << " appears!" << endl;
	}
	else 
	{
		monster = monsterFactory->GenerateMonster(player->getLevel());
		cout << "Monster " << monster->getName() << " appears!" << endl;
	}
	Sleep(500);

	vector<Item*>& playerInventory = player->getInventory();

	bool isPlayerTurn = true;

	while (true)
	{
		if (isPlayerTurn) 
		{
			for (int index = playerInventory.size() - 1; index >= 0; index--) 
			{
				if (playerInventory[index]->isUsable(player)) 
				{
					player->UseItem(index);
				}
			}

			cout << player->getName() << " attacks the " << monster->getName() << "! ";
			monster->TakeDamage(player->getAttack());

			if (monster->getHealth() <= 0) 
			{
				cout << monster->getName() << " defeat! : Victory!" << endl;
				cout << "\n====================\n" << endl;

				OnBattleVictory(player, monster);
				player->DisplayStatus();
				player->DisplayInventory();
				return true;
			}
		}
		else 
		{
			cout << monster->getName() << " attacks the " << player->getName() << "! ";
			player->TakeDamage(monster->getAttack());

			if (player->getHealth() <= 0) 
			{
				cout << player->getName() << " Defeat..." << endl;
				cout << "\nGame over..." << endl;
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
	delete monsterFactory;
}
