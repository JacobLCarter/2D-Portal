#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "item.hpp"
#include "utils.hpp"
#include <string>
#include <vector>

class Player
{
public:
    Player();
    ~Player();
    
    //get and set functions
    int getHitPoints();
    std::string getName();
    int getCurrentX();
    int getCurrentY();
    void setCurrentX(int);
    void setCurrentY(int);
    void setHitPoints(int);
    void setName(std::string);
    void incrementCurrentX();
    void incrementCurrentY();
    void decrementCurrentX();
    void decrementCurrentY();

    //backpack-related functions
    void addItemToBackpack(Item*);
    void removeItemFromBackpack(Item*);
    void displayBackpackContents();
    bool checkBackpackForItem(Item*);

private:
    int hitPoints;
    std::string name;
    int currentX;
    int currentY;
    std::vector<Item*> backpack;
};
#endif
