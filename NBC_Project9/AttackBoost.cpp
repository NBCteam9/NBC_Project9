#include "AttackBoost.h"

AttackBoost::AttackBoost()
{

}

const string AttackBoost::getName()
{
	return name;
}

void AttackBoost::use(Character* character)
{
	character->UseItem(attackIncrease);
	cout << "���ݷ��� " << attackIncrease << " �ö����ϴ�." << endl;
}