#include "MaxHPBoost.h"

MaxHPBoost::MaxHPBoost()
{
	name = "�ִ� ü�� ���� ����";
	price = 25;
}

bool MaxHPBoost::IsUsable(const Character* character) const  // �ִ� ü�� ������ �׻� ��� ����
{
	return true;
}

void MaxHPBoost::Use(Character* character)  // �ִ� ü�� ����
{
	int curMaxHealth = character->GetMaxHealth();
	curMaxHealth += maxHPIncrease;
	cout << name << " ���, �ִ� ü�� +" << maxHPIncrease <<" ����, ���� ü�� : " << character->GetHealth() << " / " << curMaxHealth << endl;
	character->SetMaxHealth(curMaxHealth);
}

void MaxHPBoost::PrintExplanation()
{
	cout << "�ִ� ü���� " << maxHPIncrease << "��ŭ ������ ����, ������ ���۵Ǹ� ����";
}
