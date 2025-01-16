#include "MaxHPBoost.h"

MaxHPBoost::MaxHPBoost()
{
	name = "최대 체력 증가 물약";
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
	cout << name << " 사용, 최대 체력 +" << maxHPIncrease <<" 증가, 현재 체력 : " << character->GetHealth() << " / " << curMaxHealth << endl;
	character->SetMaxHealth(curMaxHealth);
}

void MaxHPBoost::PrintExplanation()
{
	cout << "최대 체력이 " << maxHPIncrease << "만큼 영구히 증가, 전투가 시작되면 사용됨";
}
