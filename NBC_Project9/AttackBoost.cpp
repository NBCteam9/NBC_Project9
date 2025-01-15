#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "Attack Boost";
	price = 30;
}

bool AttackBoost::IsUsable(const Character* character) const
{
	return true;	// Attack Boost is always usable
}

void AttackBoost::Use(Character* character)	// Use Attack Boost, Increase Character Attack
{
	cout << "Attack increased " << attackIncrease << "!";
	character->SetAttack(character->GetAttack() + attackIncrease);
	cout << " Current attack : " << character->GetAttack() << endl;
}
