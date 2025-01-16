#include "HealthPotion.h"

HealthPotion::HealthPotion()
{
	name = "ü�� ȸ�� ����";
	price = 15;
}

bool HealthPotion::IsUsable(const Character* character) const // ���� ü���� ü�� ���� ȸ�������� ������ �Ǻ�
{
	int currentHealth = character->GetHealth();
	int maxHealth = character->GetMaxHealth();

	if (maxHealth - currentHealth >= healthRestore)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void HealthPotion::Use(Character* character)	// ü�� ȸ�� ����
{
	int currentHealth = character->GetHealth();
	currentHealth += healthRestore;
	cout << name << " ����߽��ϴ�, ü�� +" << healthRestore << " ȸ��, ���� ü�� :  " << currentHealth << endl;
	character->SetHealth(currentHealth);
}

void HealthPotion::PrintExplanation()
{
	cout << "ü���� " << healthRestore << "��ŭ ȸ��, ü���� " << healthRestore << "�̻� �پ��� �� ����";
}
