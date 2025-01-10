#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "공격력 물약";
	attackIncrease = 10;
}

const string AttackBoost::getName()
{
	return name;
}

void AttackBoost::use(Character* character)
{
	character->UseItem(attackIncrease);
	cout << "공격력이 " << attackIncrease << " 올랐습니다." << endl;
}