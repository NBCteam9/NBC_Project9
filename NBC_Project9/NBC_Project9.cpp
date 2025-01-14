#include <iostream>
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
	cin >> name;
	cout << endl;
	Character* warrior = Character::getInstance(name);
	

	while (true)
	{
		if (warrior->getLevel() >= 10) {
			if (gameManager.Battle(warrior) == false) {
				break;
			}
			else {
				cout << "Congratulations! Game Clear!" << endl;
				break;
			}

		}
		else {
			if (gameManager.Battle(warrior) == false) {
				break;
			}
		}

		cout << "\n====================\n" << endl;
		cout << "Do you want to go shop?? (Y/N) ";
		string choice;
		cin >> choice;
		if (choice == "Y" || choice == "y") {
			shop.visitShop(warrior);
		}
		cout << "\n====================\n" << endl;
	}
	cout << "Game over..." << endl;
	return 0;
}