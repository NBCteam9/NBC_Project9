#include "Character.h"
#include "Item.h"
Character::Character(string name)
{

}

Character* Character::getInstance(string name)
{
	return nullptr;
}

vector<Item*> Character::getInventory()
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

void Character::DisplayStatus()
{
	
}
void Character::LevelUp()
{
	
}
void Character::UseItem(int index)
{
	if (inventory.size() < index) return;

}