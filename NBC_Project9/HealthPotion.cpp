#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "체력 회복 물약";
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
	cout << name << " 사용했습니다, 체력 +" << healthRestore << " 회복, 현재 체력 :  " << currentHealth << endl;
	character->SetHealth(currentHealth);
}

void HealthPotion::PrintExplanation()
{
	cout << "체력이 " << healthRestore << "만큼 회복, 체력이 " << healthRestore << "이상 줄었을 때 사용됨";
}
