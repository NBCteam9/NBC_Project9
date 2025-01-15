#pragma once
#include "Monster.h"

class GoldenGoblin : public Monster
{
public:
    GoldenGoblin(int level);

    virtual void Initialize(int level) override;
};
