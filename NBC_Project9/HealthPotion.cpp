#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "Health Potion";
	price = 15;
}

bool HealthPotion::IsUsable(const Character* character) const // 현재 체력이 체력 물약 회복량보다 작은지 판별
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

void HealthPotion::Use(Character* character)	// 체력 회복 설정
{
	int currentHealth = character->GetHealth();
	currentHealth += healthRestore;
	cout << "Use HealPotion, +" << healthRestore << " HP , Your HP :  " << currentHealth << endl;
	character->SetHealth(currentHealth);
}
