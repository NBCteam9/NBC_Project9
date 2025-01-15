#include "MaxHPBoost.h"

MaxHPBoost::MaxHPBoost()
{
	name = "Max Health Boost";
	price = 25;
}

bool MaxHPBoost::IsUsable(const Character* character) const  // always return true
{
	return true;
}

void MaxHPBoost::Use(Character* character)  // set max health
{
	int curMaxHealth = character->GetMaxHealth();
	curMaxHealth += maxHPIncrease;
	cout << "Use Max Health Boost, +" << maxHPIncrease <<" Max Health, Your HP : " << character->GetHealth() << " / " << curMaxHealth << endl;
	character->SetMaxHealth(curMaxHealth);
}