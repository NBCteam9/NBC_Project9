#pragma once
#include "Monster.h"

class Skeleton : public Monster
{
public:
    Skeleton(int level);

    virtual void Initialize(int level) override;
};