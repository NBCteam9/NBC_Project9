#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
    Goblin(int level);
    virtual void Initialize(int level) override;
};