#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "Attack Boost";
	attackIncrease = 10;
	price = 100;
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

bool AttackBoost::isUsable() const
{
	return true;
}

int AttackBoost::getPrice() const
{
	return price;
}