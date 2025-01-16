#include "Monster.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "MaxHPBoost.h"
#include <random>
#include <vector>

// Monster Constructor
Monster::Monster(int level) 
{
	name = "default";
	health = 0;
	attack = 0;
	dropRate = 0;
	dropGold = 0;
}

void Monster::Initialize(int level)
{
}

string Monster::GetName() const
{
	return name;
}

int Monster::GetHealth() const
{
	return health;
}

int Monster::GetAttack() const
{
	return attack;
}

void Monster::TakeDamage(int damage)
{
	int preHp = health;
	health -= damage;
	if (health <= 0)
	{
		health = 0;
	}
	cout << preHp << "->" << health << endl;
}

// 
//int Monster::getRandomNum(int min, int max) {
//	int randomNum = rand() % (max - min + 1); 
//	randomNum += min;
//	return randomNum;
//}

int Monster::GetRandomNum(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}

Item* Monster::DropItem() 
{
	Item* output = nullptr;

	int firstRandomNum = GetRandomNum(1, 100);
	int secondRandomNum;
	int itemMax = 0;
	// Ȯ��
	int probability = 0;

	// 1��° ���� ���ڰ� ���Ͱ� ���� ��������� ���� ������ �������� ����Ǵ� ���̴�.
	if (firstRandomNum < dropRate)
	{
		// pair�� 1��° int���� �� �������� ���� Ȯ��, 2��° Item*���� �������� �޸� �ּ�
		vector<pair<int, Item*>> items = 
		{
			{50, new HealthPotion()},
			{50, new AttackBoost()},
			{50, new MaxHPBoost()}
		};

		// itemMax�� Ȯ�� ���� ���ڸ� �� �����ش�.
		for (pair<int, Item*> item : items) 
		{
			itemMax += item.first;
		}

		// 2��° ���� ���ڴ� ���� 1~150���� ������ �ȴ�.
		secondRandomNum = GetRandomNum(1, itemMax);

		/*for (pair<int, Item*> item : items)
		{
			probability += item.first;

			if (secondRandomNum <= probability)
			{
				return item.second;
			}
		}*/

		int selectIndex = 0;
		for (int i = 0; i < items.size(); i++) 
		{
			probability += items[i].first;

			// probability�� ���� for���� �� �� 1: 50, 2: 100, 3: 150
			// �׷��� ���� 2��° ���� ���ڰ� 99�� for���� 2��° ��ȸ���� �ɸ��� �ȴ�!
			if (secondRandomNum <= probability)
			{
				selectIndex = i;
				break;
			}
		}

		for (int i = 0; i < items.size(); i++) 
		{
			if (selectIndex == i) 
			{
				output = items[i].second;
			} 
			else 
			{
				delete items[i].second;
			} 
		}
	}

	return output;
}

int Monster::GetDropGold() const
{
	return dropGold;
}
