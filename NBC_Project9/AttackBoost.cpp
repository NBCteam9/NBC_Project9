#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "Attack Boost";
	price = 30;
}

bool AttackBoost::isUsable(Character* character) const
{
	return true;	// Attack Boost is always usable
}

void AttackBoost::use(Character* character)	// Use Attack Boost, Increase Character Attack
{
	cout << "Attack increased " << attackIncrease << "!";
	character->setAttack(character->getAttack() + attackIncrease);
	cout << " Current attack : " << character->getAttack() << endl;
}