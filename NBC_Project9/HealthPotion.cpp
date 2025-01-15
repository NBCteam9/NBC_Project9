#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "Health Potion";
	price = 15;
}

bool HealthPotion::IsUsable(const Character* character) const //max health-current health > 50(health potion) check
{
	int currentHealth = character->GetHealth();
	int maxHealth = character->GetMaxHealth();

	if (maxHealth - currentHealth >= healthRestore)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void HealthPotion::Use(Character* character)//set health
{
	int currentHealth = character->GetHealth();
	currentHealth += healthRestore;
	cout << "Use HealPotion, +" << healthRestore << " HP , Your HP :  " << currentHealth << endl;
	character->SetHealth(currentHealth);
}
