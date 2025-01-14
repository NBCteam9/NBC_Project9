#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "Health Potion";
	price = 15;
}

bool HealthPotion::isUsable(Character* character) const //max health-current health > 50(health potion) check
{
	int currentHealth = character->getHealth();
	int maxHealth = character->getMaxHealth();

	if (maxHealth - currentHealth >= healthRestore)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void HealthPotion::use(Character* character)//set health
{
	int currentHealth = character->getHealth();
	currentHealth += healthRestore;
	cout << "Use HealPotion, +50 HP , Your HP :  " << currentHealth << endl;
	character->setHealth(currentHealth);
}