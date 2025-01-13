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
		while ()
		{
			gm.Battle(warrior);
		}
	}
	return 0;
}