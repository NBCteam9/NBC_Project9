#pragma once
#include "Monster.h"

class Orc : public Monster
{
public:
    Orc(int level);

    virtual void Initialize(int level) override;
};
