#pragma once
#include "Monster.h"

class Troll : public Monster
{
public:
    Troll(int level);

    virtual void Initialize(int level) override;
};
