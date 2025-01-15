#pragma once
#include "Monster.h"

class Slime : public Monster
{
public:
	Slime(int level);
};

class Wolf : public Monster
{
public:
	Wolf(int level);
};

class Goblin : public Monster
{
public:
	Goblin(int level);
};

class GoldenGoblin : public Monster
{
public:
	GoldenGoblin(int level);
};

class Skeleton : public Monster
{
public:
	Skeleton(int level);
};

class Orc : public Monster
{
public:
	Orc(int level);
};

class Zombie : public Monster
{
public:
	Zombie(int level);
};

class Troll : public Monster
{
public:
	Troll(int level);
};

class Dragon : public Monster
{
public:
	Dragon(int level);
};
