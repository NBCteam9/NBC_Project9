#include <random>
#include <Windows.h>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "MonsterFactory.h"

void GameManager::AddKilledMonsters(Monster* monster)
{
	string monsterName = monster->GetName();
	auto it = KilledMonstersMap.find(monsterName);

	//Not Found!
	if (it == KilledMonstersMap.end()) {
		KilledMonstersMap[monsterName] = 1;
	}
	//Found!
	else {
		KilledMonstersMap[monsterName]++;
	}
}

void GameManager::OnBattleVictory(Character* player, Monster* monster)
{
	int dropGold = monster->GetDropGold();
	int curPlayerGold = player->GetGold() + dropGold;
	player->AddExperience(50);

	cout << "\n50 경험치와 " << dropGold << " 골드를 얻었습니다.\n" << endl;

	int interest = curPlayerGold / goldPerInterest;
	if (interest > maxInterest)
	{
		interest = maxInterest;
	}
	cout <<  "현재 골드 : " << curPlayerGold << endl;
	cout << "얻은 이자 : " << interest << " (최대 이자 : " << maxInterest << ")" << endl;

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
		cout << "보스 몬스터 " << monster->GetName() << "(이)가 나타났습니다! 체력: ";
		cout << monster->GetHealth() << " attack: " << monster->GetAttack() << endl;
	}
	else 
	{
		monster = MonsterFactory::GetInstance()->GenerateRandomMonster(player->GetLevel());
		cout << "몬스터 " << monster->GetName() << "(이)가 나타났습니다! 체력: ";
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

			cout << player->GetName() << "(이)가 " << monster->GetName() << "(을)를 공격했습니다! ";
			monster->TakeDamage(player->GetAttack());

			if (monster->GetHealth() <= 0) 
			{
				cout << monster->GetName() << "의 패배! : 승리했습니다!" << endl;
				AddKilledMonsters(monster);
				OnBattleVictory(player, monster);
				cout << "\n====================\n" << endl;

				player->DisplayStatus();
				player->DisplayInventory();
				return true;
			}
		}
		else 
		{
			cout << monster->GetName() << "(이)가 " << player->GetName() << "(을)를 공격했습니다! ";
			player->TakeDamage(monster->GetAttack());

			if (player->GetHealth() <= 0) 
			{
				cout << player->GetName() << " 패배했습니다..." << endl;
				cout << "\nGame over..." << endl;
				return false;
			}
		}

		isPlayerTurn = !isPlayerTurn;
		Sleep(500);
	}
}

void GameManager::Initialize()
{
	KilledMonstersMap.clear();
}

void GameManager::DisplayKilledMonsters()
{
	cout << "쓰러트린 몬스터\n" << endl;
	for (const auto& pair : KilledMonstersMap) {
		cout << pair.first << " : " << pair.second << endl;
	}
}
