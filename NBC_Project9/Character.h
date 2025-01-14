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
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

	static Character* getInstance(string _name = "");
	vector<Item*>& getInventory();
	string getName();
	int getLevel();
	int getHealth();
	void setHealth(int val);
	int getMaxHealth();
	void setMaxHealth(int val);
	int getAttack();
	void setAttack(int val);
	void AddExperience(int val);
	int getGold();
	void setGold(int val);
	void DisplayStatus();
	void TakeDamage(int val);
	void LevelUp();
	void UseItem(int index);
	void DisplayInventory();
};