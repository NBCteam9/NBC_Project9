#include <iostream>
#include "GameManager.h"
#include "Character.h"

using namespace std;

int main()
{
    GameManager gm;
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
			if (gm.Battle(warrior) == false) {
				return 0;
			}
			else {
				cout << "Congratulations! Game cleared!" << endl;
				return 0;
			}

		}
		else {
			if (gm.Battle(warrior) == false) {
				return 0;
			}
		}

		cout << "You want to go shop?? (Y/N)";
		string choice;
		cin >> choice;
		if (choice == "Y" || choice == "y") {
			gm.VisitShop(warrior);
		}
		cout << "\n====================\n" << endl;
	}
	return 0;
}