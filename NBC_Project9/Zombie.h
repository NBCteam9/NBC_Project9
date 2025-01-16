#pragma once
#include "Monster.h"

class Zombie : public Monster
{
public:
    Zombie(int level);
    
    virtual void Initialize(int level) override;
};
