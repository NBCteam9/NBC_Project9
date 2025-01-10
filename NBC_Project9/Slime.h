#pragma once

#include "Monster.h"
class Slime :
    public Monster
{
public:
    Slime();
    virtual string getName() override;
    int getHealth();
    int getAttack();
};