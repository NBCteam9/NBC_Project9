#pragma once
#include "Monster.h"

class Wolf : public Monster
{
public:
    Wolf(int level);

    virtual void Initialize(int level) override;
};
