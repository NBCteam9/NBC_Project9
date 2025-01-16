#include <random>
#include <Windows.h>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "MonsterFactory.h"

void GameManager::OnBattleVictory(Character* player, Monster* monster)
{
	int curPlayerGold = player->GetGold() + monster->GetDropGold();
	int interest = curPlayerGold / goldPerInterest;
	if (interest > maxInterest)
	{
		interest = maxInterest;
	}
	cout <<  "Current Gold : " << curPlayerGold << endl;
	cout << "Get Interest : " << interest << " (Max Interest : " << maxInterest << ")\n" << endl;

	player->AddExperience(50);

	player->SetGold(curPlayerGold + interest);

	Item* dropItem = monster->DropItem();

	if (dropItem != nullptr) 
	{
		player->GetInventory().push_back(dropItem);
	}
}

bool GameManager::Battle(Character* player)
{
	Monster* monster = nullptr;

	if (player->GetLevel() >= 10) 
	{
		monster = MonsterFactory::GetInstance()->GenerateRandomBossMonster();
		cout << "BossMonster " << monster->GetName() << " appears! health: ";
		cout << monster->GetHealth() << " attack: " << monster->GetAttack() << endl;
	}
	else 
	{
		monster = MonsterFactory::GetInstance()->GenerateRandomMonster(player->GetLevel());
		cout << "Monster " << monster->GetName() << " appears! health: ";
		cout << monster->GetHealth() << " attack: " << monster->GetAttack() << endl;
	}
	Sleep(500);

	vector<Item*>& playerInventory = player->GetInventory();

	bool isPlayerTurn = true;

	while (true)
	{
		if (isPlayerTurn) 
		{
			for (int index = playerInventory.size() - 1; index >= 0; index--) 
			{
				if (playerInventory[index]->IsUsable(player)) 
				{
					player->UseItem(index);
				}
			}

			cout << player->GetName() << " attacks the " << monster->GetName() << "! ";
			monster->TakeDamage(player->GetAttack());

			if (monster->GetHealth() <= 0) 
			{
				cout << monster->GetName() << " defeat! : Victory!" << endl;
				cout << "\n====================\n" << endl;

				OnBattleVictory(player, monster);
				player->DisplayStatus();
				player->DisplayInventory();
				return true;
			}
		}
		else 
		{
			cout << monster->GetName() << " attacks the " << player->GetName() << "! ";
			player->TakeDamage(monster->GetAttack());

			if (player->GetHealth() <= 0) 
			{
				cout << player->GetName() << " Defeat..." << endl;
				cout << "\nGame over..." << endl;
				return false;
			}
		}

		isPlayerTurn = !isPlayerTurn;
		Sleep(500);
	}
}
