#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "Health Potion";
	price = 100;
}

bool HealthPotion::isUsable(Character* character) const
{
	int currentHealth = character->getHealth(); //���� ü�� �޾ƿ���
	int maxHealth = character->getMaxHealth(); //�ִ� ü�� �޾ƿ���

	if (currentHealth == maxHealth)  // Ǯ���϶� ���� ���԰� ����
	{
		cout << "Max Hp" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

string HealthPotion::getName()
{
	return name;
}

void HealthPotion::use(Character* character)
{
	int currentHealth = character->getHealth();	//���� ü�� �޾ƿ���
	currentHealth += 50;	//ü�� 50 ����
	cout << "Use HealPotion, +50 HP , Your HP :  " << currentHealth << endl;
	character->setHealth(currentHealth); // ü�� �缳��
}