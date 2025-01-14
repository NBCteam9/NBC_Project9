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
	Character(string _name);
public:
	static Character* getInstance(string _name = "");
	vector<Item*>& getInventory();
	string getName();
	int getLevel();
	int getHealth();
	void setHealth(int _health);
	int getMaxHealth();
	void setMaxHealth(int _health);
	int getAttack();
	void setAttack(int _attack);
	void AddExperience(int val);
	int getGold();
	void setGold(int val);
	void DisplayStatus();
	void TakeDamage(int val);
	void LevelUp();
	void UseItem(int index);
	void DisplayInventory();
};