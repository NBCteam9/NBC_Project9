#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "Attack Boost";
	price = 30;
}

bool AttackBoost::IsUsable(const Character* character) const
{
	return true;	// ���ݷ� ������ �׻� ��� ����
}

void AttackBoost::Use(Character* character)	// ���ݷ� ������ ����Ͽ� ĳ������ ���ݷ� ��½�Ŵ
{
	cout << "Attack increased " << attackIncrease << "!";
	character->SetAttack(character->GetAttack() + attackIncrease);
	cout << " Current attack : " << character->GetAttack() << endl;
}
