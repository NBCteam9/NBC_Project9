#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Item;

class Character
{
private:
	static Character* instance;
	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int experience;
	int gold;
	vector<Item*> inventory;
	Character(string name);
public:
	static Character* getInstance(string name = "");
	vector<Item*>& getInventory();
	int getHealth();
	void setHealth(int _health);
	int getMaxHealth();
	void setMaxHealth(int _health);
	int getAttack();
	void setAttack(int _attack);
	int getExperience();
	int getGold();
	void setGold(int val);
	void setExperience(int _experience);
	void DisplayStatus();
	void LevelUp();
	void UseItem(int index);
};