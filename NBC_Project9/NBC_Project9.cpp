#include <iostream>
#include <string>
#include "GameManager.h"
#include "MonsterFactory.h"
#include "Shop.h"
#include "Character.h"
#include "Slime.h"
#include "Wolf.h"
#include "Goblin.h"
#include "GoldenGoblin.h"
#include "Skeleton.h"
#include "Orc.h"
#include "Zombie.h"
#include "Troll.h"
#include "Dragon.h"
#include "Monster.h"

using namespace std;

int main()
{
    GameManager gameManager;

	MonsterFactory::GetInstance()->AddMonster(new Goblin(1));
	MonsterFactory::GetInstance()->AddMonster(new Orc(1));
	MonsterFactory::GetInstance()->AddMonster(new Skeleton(1));
	MonsterFactory::GetInstance()->AddMonster(new Slime(1));
	MonsterFactory::GetInstance()->AddMonster(new Troll(1));
	MonsterFactory::GetInstance()->AddMonster(new Wolf(1));
	MonsterFactory::GetInstance()->AddMonster(new Zombie(1));
	MonsterFactory::GetInstance()->AddMonster(new GoldenGoblin(1));

	MonsterFactory::GetInstance()->AddBossMonster(new Dragon(1));

	Shop shop;

	cout << "Welcome to Game!" << endl;
	cout << "Create your character." << endl;
	string name;
	cin.clear();
	while(1)
	{
		getline(cin, name);

		if (name.find(' ') != string::npos) 
		{
			cout << "Your name contains space. Please try again" << endl;
		}
		else 
		{
			cout << "Your name : " << name << endl;
			cout << "\n====================\n" << endl;
			break;
		}
	}
	Character* warrior = Character::GetInstance(name);
	
	while (true)
	{
		if (warrior->GetLevel() >= 10) 
		{
			if (gameManager.Battle(warrior) == false) 
			{
				break;
			}
			else 
			{
				cout << "Congratulations! Game Clear!" << endl;
				break;
			}

		}
		else 
		{
			if (gameManager.Battle(warrior) == false) 
			{
				break;
			}
		}

		cout << "\n====================\n" << endl;
		cout << "Do you want to go shop?? (Y/N) ";
		while (1) 
		{
			string choice;
			cin >> choice;
			if (choice == "Y" || choice == "y") 
			{
				shop.VisitShop(warrior);
				break;
			}
			else if (choice == "N" || choice == "n") 
			{
				break;
			}
			else
			{
				cout << "Please re-enter (Y/N) " ;
			}
		}
		cout << "\n====================\n" << endl;
	}
	
	Character::DestroyInstance();
	MonsterFactory::DestoryInstance();

	return 0;
}
