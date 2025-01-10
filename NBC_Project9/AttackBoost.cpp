#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "공격력 물약";
	attackIncrease = 10;
	price = 100;
}

const string AttackBoost::getName() const
{
	return name;
}

void AttackBoost::use(Character* character)
{
	cout << "공격력이 " << attackIncrease << " 올랐다.";
	character->setAttack(character->getAttack() + attackIncrease);
	cout << " 현재 공격력 : " << character->getAttack() << endl;
}

bool AttackBoost::isUsable() const
{
	return true;
}

int AttackBoost::getPrice() const
{
	return price;
}