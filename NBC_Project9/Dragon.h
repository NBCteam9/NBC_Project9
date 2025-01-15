#pragma once
#include "Monster.h"

class Dragon : public Monster
{
public:
    Dragon(int level);

    virtual void Initialize(int level) override;
};
