#include "MonsterList.h"

Slime::Slime(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(4, 6);

	name = "Slime";
	health = 20 + level * (15 + healthRandomValue);
	attack = 3 + level * (4 + attackRandomValue);
	dropRate = 10;
	dropGold = goldReward;
}

Wolf::Wolf(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(4, 8);

	name = "Wolf";
	health = 25 + level * (18 + healthRandomValue);
	attack = 4 + level * (5 + attackRandomValue);
	dropRate = 15;
	dropGold = goldReward;
}

Goblin::Goblin(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(5, 10);

	name = "Goblin";
	health = 30 + level * (20 + healthRandomValue);
	attack = 5 + level * (6 + attackRandomValue);
	dropRate = 20;
	dropGold = goldReward;
}

GoldenGoblin::GoldenGoblin(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(1, 110);

	name = "GoldenGoblin";
	health = 22 + level * (13 + healthRandomValue);
	attack = 11 + level * (11 + attackRandomValue);
	dropRate = 50;
	dropGold = goldReward;
}

Skeleton::Skeleton(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(10, 15);

	name = "Skeleton";
	health = 37 + level * (23 + healthRandomValue);
	attack = 6 + level * (7 + attackRandomValue);
	dropRate = 25;
	dropGold = goldReward;
}

Orc::Orc(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(15, 20);

	name = "Orc";
	health = 45 + level * (25 + healthRandomValue);
	attack = 7 + level * (8 + attackRandomValue);
	dropRate = 30;
	dropGold = goldReward;
}

Zombie::Zombie(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(20, 25);

	name = "Zombie";
	health = 52 + level * (28 + healthRandomValue);
	attack = 8 + level * (9 + attackRandomValue);
	dropRate = 35;
	dropGold = goldReward;
}

Troll::Troll(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(25, 30);

	name = "Troll";
	health = 60 + level * (30 + healthRandomValue);
	attack = 10 + level * (10 + attackRandomValue);
	dropRate = 40;
	dropGold = goldReward;
}

Dragon::Dragon(int level) : Monster(level)
{
	int healthRandomValue = getRandomNum(1, 10);
	int attackRandomValue = getRandomNum(1, 5);
	int goldReward = getRandomNum(100, 300);

	name = "Dragon";
	health = 80 + level * (42 + healthRandomValue);
	attack = 11 + level * (10 + attackRandomValue);
	dropRate = 97;
	dropGold = goldReward;
}