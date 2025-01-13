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

	if (maxHealth - currentHealth <= healthRestore)  // ȸ���� ��ŭ ���̸� ��밡��
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
	int currentHealth = character->getHealth();	//���� ü�� �޾ƿ���
	currentHealth += 50;	//ü�� 50 ����
	cout << "Use HealPotion, +50 HP , Your HP :  " << currentHealth << endl;
	character->setHealth(currentHealth); // ü�� �缳��
}

int HealthPotion::getPrice() const
{
	return price;
}