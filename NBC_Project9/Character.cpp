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

Character* Character::getInstance(string _name)
{
	if (instance == nullptr)
	{
		instance = new Character(_name);
	}
	return instance;
}

string Character::getName()
{
	return name;
}

vector<Item*>& Character::getInventory()
{
	return inventory;
}

int Character::getLevel()
{
	return level;
}

int Character::getHealth()
{
	return health;
}

void Character::setHealth(int val)
{
	health = val;
}

int Character::getMaxHealth()
{
	return maxHealth;
}

void Character::setMaxHealth(int val)
{
	maxHealth = val;
}

int Character::getAttack()
{
	return attack;
}

void Character::setAttack(int val)
{
	attack = val;
}

int Character::getGold()
{
	return gold;
}

void Character::setGold(int val)
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

void Character::DisplayStatus()
{
	cout << "Name:" << name << endl;
	cout << "Level:" << level << endl;
	cout << "Experience:" << experience << endl;
	cout << "Health:" << health << "/" << maxHealth << endl;
	cout << "Attack:" << attack << endl;
	cout << "Gold:" << gold << endl;
}

void Character::TakeDamage(int val)
{
	int currentHp = health;
	health -= val;
	if (health < 0)
	{
		health = 0;
	}
	cout << "Take Damage!! " << currentHp << "->" << health << endl;
}

void Character::LevelUp()
{
	if (level >= 10) return;
	int currentLv = level;
	level++;
	cout << "Level Up!  Lv." << currentLv << " -> Lv." << level << endl;
	maxHealth += 20;
	health = maxHealth;
	attack += 5;
	experience -= 100;
}

void Character::UseItem(int index)
{
	if (inventory.size() < index) return;
	Item* useItem = inventory[index];
	useItem->use(instance);
	inventory.erase(inventory.begin() + index);
	delete(useItem);
}

void Character::DisplayInventory()
{
	if (inventory.size() != 0) cout << endl;
	for (int index = 0; index < inventory.size(); index++) {
		Item* item = inventory[index];
		cout << index + 1 << ": " << item->getName() << " (Price : " << item->getPrice() << "G)" << endl;
	}
}