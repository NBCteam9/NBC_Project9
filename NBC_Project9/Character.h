#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Item;

class Character
{
public:
	Character(const Character&) = delete;
	~Character();
	Character& operator=(const Character&) = delete;
	static Character* GetInstance(string _name = "");
	vector<Item*>& GetInventory();
	string GetName() const;
	int GetLevel() const;
	int GetHealth() const;
	void SetHealth(int val);
	int GetMaxHealth() const;
	void SetMaxHealth(int val);
	int GetAttack() const;
	void SetAttack(int val);
	void AddExperience(int val);
	int GetGold() const;
	void SetGold(int val);
	void DisplayStatus() const;
	void TakeDamage(int val);
	void LevelUp();
	void UseItem(int index);
	void DisplayInventory() const;
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
