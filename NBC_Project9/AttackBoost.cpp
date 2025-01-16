#include "AttackBoost.h"

AttackBoost::AttackBoost()
{
	name = "공격력 증가 물약";
	price = 30;
}

bool AttackBoost::IsUsable(const Character* character) const
{
	return true;	// 공격력 물약은 항상 사용 가능
}

void AttackBoost::Use(Character* character)	// 공격력 물약을 사용하여 캐릭터의 공격력 상승시킴
{
	cout << name << "사용, 공격력 +" << attackIncrease << " 증가, 현재 공격력 : ";
	character->SetAttack(character->GetAttack() + attackIncrease);
	cout << character->GetAttack() << endl;
}
