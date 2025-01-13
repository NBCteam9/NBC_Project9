#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "Health Potion";
	healthRestore = 50;
	price = 100;
}


string HealthPotion::getName()
{
	return name;
}

void HealthPotion::use(Character* character)
{
	int currentHealth = character->getHealth(); //현재 체력 받아오기
	int maxHealth = character->getMaxHealth(); //최대 체력 받아오기

	if (currentHealth == maxHealth) {// 풀피일때 물약 못먹게 설정
		cout << "Max Hp" << endl;
	}
	else {
		currentHealth += 50;//체력 50 증가
		cout << "Use HealPotion, +50 HP , Your HP =  " << currentHealth << endl;
		character->setHealth(currentHealth); // 체력 재설정
	}
}