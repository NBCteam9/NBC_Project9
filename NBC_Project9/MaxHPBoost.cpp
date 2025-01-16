#include "MaxHPBoost.h"

MaxHPBoost::MaxHPBoost()
{
	name = "Max Health Boost";
	price = 25;
}

bool MaxHPBoost::IsUsable(const Character* character) const  // 최대 체력 물약은 항상 사용 가능
{
	return true;
}

void MaxHPBoost::Use(Character* character)  // 최대 체력 설정
{
	int curMaxHealth = character->GetMaxHealth();
	curMaxHealth += maxHPIncrease;
	cout << "Use Max Health Boost, +" << maxHPIncrease <<" Max Health, Your HP : " << character->GetHealth() << " / " << curMaxHealth << endl;
	character->SetMaxHealth(curMaxHealth);
}
