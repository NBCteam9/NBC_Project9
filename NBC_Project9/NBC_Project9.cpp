#include <iostream>
#include <string>
#include "GameManager.h"
#include "Shop.h"
#include "Character.h"

using namespace std;

int main()
{
    GameManager gameManager;
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
		string choice;
		cin >> choice;
		if (choice == "Y" || choice == "y") 
		{
			shop.VisitShop(warrior);
		}
		cout << "\n====================\n" << endl;
	}
	
	delete warrior;

	return 0;
}
