#include "MaxHPBoost.h"

MaxHPBoost::MaxHPBoost()
{
	name = "Max Health Boost";
	price = 25;
}

bool MaxHPBoost::isUsable(Character* character) const  // always return true
{
	return true;
}

void MaxHPBoost::use(Character* character)  // set max health
{
	int curMaxHealth = character->getMaxHealth();
	curMaxHealth += maxHPIncrease;
	cout << "Use Max Health Boost, +" << maxHPIncrease <<" Max Health, Your HP : " << character->getHealth() << " / " << curMaxHealth << endl;
	character->setMaxHealth(curMaxHealth);
}
