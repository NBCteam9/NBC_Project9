#include "Item.h"

Item::Item()
{
    name = "default";
    price = 0;
}

const string Item::GetName() const
{
    return name;
}

int Item::GetPrice() const
{
    return price;
}
