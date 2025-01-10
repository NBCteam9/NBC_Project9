#include "Character.h"
#include "Item.h"
Character::Character(string name)
{

}

Character* Character::getInstance(string name)
{
	return nullptr;
}

vector<Item*>& Character::getInventory()
{
	return inventory;
}
int Character::getHealth() 
{
	return health;
}
void Character::setHealth(int _health)
{
	health = _health;
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
void Character::setAttack(int _attack)
{
	attack = _attack;
}
int Character::getExperience()
{
	return experience;
}
void Character::setExperience(int _experience)
{
	experience = _experience;
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

void Character::DisplayStatus()
{
	cout << "ü��:" << health << "/" << maxHealth << endl;
	cout << "���ݷ�:" << attack << endl;
	cout << "����ġ:" << experience << endl;
	cout << "���� ���:" << gold << endl;
}


void Character::LevelUp()
{
	
}
void Character::UseItem(int index)
{
	if (inventory.size() < index) return;

}