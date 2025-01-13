#include <iostream>
#include "GameManager.h"
#include "Character.h"

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
			gm.Battle(warrior);
			//조건문으로 게임 오버 조건 확인
			
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