#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "Health Potion";
	price = 15;
}

bool HealthPotion::isUsable(Character* character) const //ü���� ���Ǹ�ŭ ��Ҵ��� Ȯ��
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

void HealthPotion::use(Character* character)//ü�� ȸ���Ͽ� ĳ���� ü�¿� ����
{
	int currentHealth = character->getHealth();
	currentHealth += 50;
	cout << "Use HealPotion, +50 HP , Your HP :  " << currentHealth << endl;
	character->setHealth(currentHealth);
}