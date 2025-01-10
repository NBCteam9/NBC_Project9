#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "���ݷ� ����";
	attackIncrease = 10;
	price = 100;
}

const string AttackBoost::getName()
{
	return name;
}

void AttackBoost::use(Character* character)
{
	cout << "���ݷ��� " << attackIncrease << " �ö����ϴ�.";
	character->setAttack(character->getAttack() + attackIncrease);
	cout << " ���� ���ݷ� : " << character->getAttack() << endl;
}