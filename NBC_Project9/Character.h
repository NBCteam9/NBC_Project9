#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Item;

class Character
{
public:
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

	static Character* GetInstance(string _name = "");
	vector<Item*>& GetInventory();
	string GetName();
	int GetLevel();
	int GetHealth();
	void SetHealth(int val);
	int GetMaxHealth();
	void SetMaxHealth(int val);
	int GetAttack();
	void SetAttack(int val);
	void AddExperience(int val);
	int GetGold();
	void SetGold(int val);
	void DisplayStatus();
	void TakeDamage(int val);
	void LevelUp();
	void UseItem(int index);
	void DisplayInventory();
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
};
