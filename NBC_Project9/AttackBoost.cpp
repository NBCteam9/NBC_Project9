#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "���ݷ� ���� ����";
	price = 30;
}

bool AttackBoost::IsUsable(const Character* character) const
{
	return true;	// ���ݷ� ������ �׻� ��� ����
}

void AttackBoost::Use(Character* character)	// ���ݷ� ������ ����Ͽ� ĳ������ ���ݷ� ��½�Ŵ
{
	cout << name << "���, ���ݷ� +" << attackIncrease << " ����, ���� ���ݷ� : ";
	character->SetAttack(character->GetAttack() + attackIncrease);
	cout << character->GetAttack() << endl;
}
