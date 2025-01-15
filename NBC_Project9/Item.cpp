#include "Item.h"

Item::Item()
{
    name = "default";
    price = 0;
}

string Item::GetName() const
{
    return name;
}

int Item::GetPrice() const
{
    return price;
}