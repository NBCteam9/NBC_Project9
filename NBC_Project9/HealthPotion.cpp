#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "Health Potion";
	price = 15;
}

bool HealthPotion::isUsable(Character* character) const //체력이 포션만큼 닳았는지 확인
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

void HealthPotion::use(Character* character)//체력 회복하여 캐릭터 체력에 적용
{
	int currentHealth = character->getHealth();
	currentHealth += 50;
	cout << "Use HealPotion, +50 HP , Your HP :  " << currentHealth << endl;
	character->setHealth(currentHealth);
}