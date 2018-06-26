#include "item.hpp"

Item::Item()
{
    itemName = " ";
    itemDescription = " ";
}

Item::Item(std::string itemNameInput, std::string itemDescriptionInput,
           char itemTypeInput)
{
    itemName = itemNameInput;
    itemDescription = itemDescriptionInput;
    itemTypeIdentifier = itemTypeInput;
}

Item::~Item()
{
}

std::string Item::getItemName()
{
    return itemName;
}

std::string Item::getItemDescription()
{
    return itemDescription;
}

char Item::getItemTypeIdentifier()
{
    return itemTypeIdentifier;
}
