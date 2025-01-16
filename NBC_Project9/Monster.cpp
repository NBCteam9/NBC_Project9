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
	// 확률
	int probability = 0;

	// 1번째 랜덤 숫자가 몬스터가 가진 드랍률보다 낮게 나오면 아이템이 드랍되는 것이다.
	if (firstRandomNum < dropRate)
	{
		// pair의 1번째 int에는 그 아이템이 나올 확률, 2번째 Item*에는 아이템의 메모리 주소
		vector<pair<int, Item*>> items = 
		{
			{50, new HealthPotion()},
			{50, new AttackBoost()},
			{50, new MaxHPBoost()}
		};

		// itemMax에 확률 관련 숫자를 다 더해준다.
		for (pair<int, Item*> item : items) 
		{
			itemMax += item.first;
		}

		// 2번째 랜덤 숫자는 현재 1~150까지 나오게 된다.
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

			// probability의 값이 for문을 돌 때 1: 50, 2: 100, 3: 150
			// 그래서 만약 2번째 랜덤 숫자가 99면 for문의 2번째 순회에서 걸리게 된다!
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
