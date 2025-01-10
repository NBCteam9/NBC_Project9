#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "���ݷ� ����";
	attackIncrease = 10;
	price = 100;
}

const string AttackBoost::getName() const
{
	return name;
}

void AttackBoost::use(Character* character)
{
	cout << "���ݷ��� " << attackIncrease << " �ö���.";
	character->setAttack(character->getAttack() + attackIncrease);
	cout << " ���� ���ݷ� : " << character->getAttack() << endl;
}

bool AttackBoost::isUsable() const
{
	return true;
}

int AttackBoost::getPrice() const
{
	return price;
}