#include "Character.h"
#include "Item.h"

Character* Character::instance = nullptr;

Character::Character(string _name)
{
	name = _name;
	level = 1;
	health = 200;
	maxHealth = 200;
	attack = 30;
	experience = 0;
	gold = 0;
}

void Character::DestroyInstance()
{
	delete instance;
	instance = nullptr;
}

Character::~Character()
{
	for (Item* a : inventory)
	{
		delete(a);
	}
	inventory.clear();
}

Character* Character::GetInstance(string _name)
{
	if (instance == nullptr)
	{
		instance = new Character(_name);
	}
	return instance;
}

string Character::GetName() const
{
	return name;
}

void Character::InitCharacter()
{
	level = 1;
	health = 200;
	maxHealth = 200;
	attack = 30;
	experience = 0;
	gold = 0;
	for (Item* a : inventory)
	{
		delete(a);
	}
	inventory.clear();
}

vector<Item*>& Character::GetInventory()
{
	return inventory;
}

int Character::GetLevel() const
{
	return level;
}

int Character::GetHealth() const
{
	return health;
}

void Character::SetHealth(int val)
{
	health = val;
}

int Character::GetMaxHealth() const
{
	return maxHealth;
}

void Character::SetMaxHealth(int val)
{
	maxHealth = val;
}

int Character::GetAttack() const
{
	return attack;
}

void Character::SetAttack(int val)
{
	attack = val;
}

int Character::GetGold() const
{
	return gold;
}

void Character::SetGold(int val)
{
	if (val < 0)
	{
		gold = 0;
	}
	else
	{
		gold = val;
	}
}

void Character::AddExperience(int val)
{
	experience += val;
	if (experience >= 100)
		LevelUp();
}

void Character::DisplayStatus() const
{
	cout << "이름 : " << name << endl;
	cout << "레벨 : " << level << endl;
	cout << "경험치 : " << experience << endl;
	cout << "체력 : " << health << "/" << maxHealth << endl;
	cout << "공격력 : " << attack << endl;
	cout << "골드 : " << gold << endl;
}

void Character::TakeDamage(int val)
{
	int currentHp = health;
	health -= val;
	if (health < 0)
	{
		health = 0;
	}
	cout << "피해를 입었습니다!! " << currentHp << "->" << health << endl;
}

void Character::LevelUp()
{
	if (level >= 10) return;
	int currentLv = level;
	level++;
	cout << "레벨 업!  Lv." << currentLv << " -> Lv." << level << endl;
	maxHealth += 20;
	health = maxHealth;
	attack += 5;
	experience -= 100;
}

void Character::UseItem(int index)
{
	if (inventory.size() < index) return;
	Item* useItem = inventory[index];
	useItem->Use(instance);
	inventory.erase(inventory.begin() + index);
	delete(useItem);
}

void Character::DisplayInventory() const
{
	if (inventory.size() != 0) cout << endl;
	for (int index = 0; index < inventory.size(); index++) {
		Item* item = inventory[index];
		cout << index + 1 << ": " << item->GetName() << " (가격 : " << item->GetPrice() << "G)" << endl;
	}
}