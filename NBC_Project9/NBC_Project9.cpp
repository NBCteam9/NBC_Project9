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
	Character* warrior = Character::getInstance(name);
	while (1)
	{
		if (gm.Battle(warrior) == false) {
			return;
		}
		gm.Battle(warrior);
		cout << "You want to go shop?? (Y/N)";
		string choice;
		cin >> choice;
		if (choice == "Y" || choice == "y") {
			gm.VisitShop(warrior);
		}
			
	}
	return 0;
}