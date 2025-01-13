#include <iostream>
#include "GameManager.h"
#include "Character.h"

using namespace std;

int main()
{
    GameManager gm;

	while (true)
	{
		cout << "Welcome to Game!" << endl;
		cout << "Create your character." << endl;
		string name;
		cin.clear();
		cin >> name;
		Character* warrior = Character::getInstance(name);

		while (1)
		{
			if (warrior->getLevel() >= 10) {
				if (gm.Battle(warrior) == false) {
					break;
				}
				else {
					cout << "Congratulations! Game cleared!" << endl;
					break;
				}
			}
			else {
				if (gm.Battle(warrior) == false) {
					break;
				}
			}

			
			cout << "You want to go shop?? (Y/N)";
			string choice;
			cin >> choice;
			if (choice == "Y" || choice == "y") {
				gm.VisitShop(warrior);
			}			
		}
	}

	return 0;
}