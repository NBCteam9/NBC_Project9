#pragma once

#include <vector>
#include <iostream>
using namespace std;

class MonsterFactory
{
public:
	class Monster* GenerateMonster(int level);
	class Monster* GenerateBossMonster();
};