#pragma once

#include "Monster.h"
class Troll :
    public Monster
{
public:
    Troll();
    virtual string getName() override;
    int getHealth();
    int getAttack();
};