#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "Health Potion";
	price = 100;
}

bool HealthPotion::isUsable(Character* character) const
{
	int currentHealth = character->getHealth();
	int maxHealth = character->getMaxHealth();

	if (maxHealth - currentHealth <= healthRestore)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const string HealthPotion::getName() const
{
	return name;
}

void HealthPotion::use(Character* character)
{
	int currentHealth = character->getHealth();
	currentHealth += 50;
	cout << "Use HealPotion, +50 HP , Your HP :  " << currentHealth << endl;
	character->setHealth(currentHealth);
}

int HealthPotion::getPrice() const
{
	return price;
}