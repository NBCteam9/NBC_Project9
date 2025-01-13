#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "Attack Boost";
	price = 30;
}

bool AttackBoost::isUsable(Character* character) const
{
	return true;
}

const string AttackBoost::getName() const
{
	return name;
}

void AttackBoost::use(Character* character)
{
	cout << "Attack increased " << attackIncrease << "!";
	character->setAttack(character->getAttack() + attackIncrease);
	cout << " Current attack : " << character->getAttack() << endl;
}

int AttackBoost::getPrice() const
{
	return price;
}