#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
public:
    Item();
    Item(std::string, std::string, char);
    ~Item();
    std::string getItemName();
    std::string getItemDescription();
    char getItemTypeIdentifier();
private:
    std::string itemName;
    std::string itemDescription;
    char itemTypeIdentifier;
};
#endif
