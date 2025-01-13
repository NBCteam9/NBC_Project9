#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "Health Potion";
	price = 100;
}

bool HealthPotion::isUsable(Character* character) const
{
	int currentHealth = character->getHealth(); //현재 체력 받아오기
	int maxHealth = character->getMaxHealth(); //최대 체력 받아오기

	if (maxHealth - currentHealth <= healthRestore)  // 회복량 만큼 까이면 사용가능
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
	int currentHealth = character->getHealth();	//현재 체력 받아오기
	currentHealth += 50;	//체력 50 증가
	cout << "Use HealPotion, +50 HP , Your HP :  " << currentHealth << endl;
	character->setHealth(currentHealth); // 체력 재설정
}

int HealthPotion::getPrice() const
{
	return price;
}