#pragma once
#include "Monster.h"

class Slime : public Monster
{
public:
    Slime(int level);

    virtual void Initialize(int level) override;
};