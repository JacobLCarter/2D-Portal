/*******************************************************************************
 * Class Name: Player
 * Description: Handles all functions related to and neccessary for creating and
 * maintaining a player of the game. 
 * Functionality includes get and set functions, incrementCurrentX,
 * incrementCurrentY, decrementCurrentX, decrementCurrentY, addItemToBackpack,
 * removeItemFromBackpack, displayBackpackContents, and checkBackpackForItem.
 ******************************************************************************/
#include "player.hpp"
#include <iostream>

Player::Player()
{
    setHitPoints(100);
    std::cout << "It's waking up...what was it's name again?" << std::endl;
    std::cout << "Enter your name: ";
    setName(getString(false));
    setCurrentX(0);
    setCurrentY(0);
}

Player::~Player()
{
    backpack.clear();
}

int Player::getHitPoints()
{
    return hitPoints;
}

std::string Player::getName()
{
    return name;
}

int Player::getCurrentX()
{
    return currentX;
}

int Player::getCurrentY()
{
    return currentY;
}

void Player::setCurrentX(int xToSet)
{
    currentX = xToSet; 
}

void Player::setCurrentY(int yToSet)
{
    currentY = yToSet; 
}

void Player::setHitPoints(int hitPointsInput)
{
    hitPoints = hitPointsInput;
}

void Player::setName(std::string nameSelection)
{
    name = nameSelection;
}

/*******************************************************************************
 * Name: incrementCurrentX 
 * Description: Adds one to the player's current X value 
 * Parameters: None 
 ******************************************************************************/
void Player::incrementCurrentX()
{
    currentX++;
}

/*******************************************************************************
 * Name: incrementCurrentY 
 * Description: Adds one to the player's current Y value 
 * Parameters: None 
 ******************************************************************************/
void Player::incrementCurrentY()
{
    currentY++;
}

/*******************************************************************************
 * Name: decrementCurrentX 
 * Description: Subtracts one from the player's current X value 
 * Parameters: None 
 ******************************************************************************/
void Player::decrementCurrentX()
{
    currentX--;
}

/*******************************************************************************
 * Name: decrementCurrentY 
 * Description: Subtracts one from the player's current X value 
 * Parameters: None 
 ******************************************************************************/
void Player::decrementCurrentY()
{
    currentY--;
}

/*******************************************************************************
 * Name: addItemToBackpack 
 * Description: Adds an item to the player's backpack 
 * Parameters: None 
 ******************************************************************************/
void Player::addItemToBackpack(Item *itemPickedUp)
{
    backpack.push_back(itemPickedUp);
}

/*******************************************************************************
 * Name: removeItemFromBackpack 
 * Description: Removes an item from the player's backpack 
 * Parameters: None 
 ******************************************************************************/
void Player::removeItemFromBackpack(Item *itemToDrop)
{
    backpack.erase(std::remove(backpack.begin(), backpack.end(), itemToDrop),
                   backpack.end());
}

/*******************************************************************************
 * Name: displayBackpackContents 
 * Description: Shows the current contents of the player's backpack 
 * Parameters: None 
 ******************************************************************************/
void Player::displayBackpackContents()
{
    std::cout << "Current contents of your backpack: " << std::endl;

    if (backpack.empty())
    {
        std::cout << "Nothing!" << std::endl;
    }
    else
    {
        //for each item, print an ascending number and the name and description
        for (int i = 0; i < backpack.size(); i++)
        {
            std::cout << i + 1 << ": " << backpack.at(i)->getItemName()
                      << " - " << backpack.at(i)->getItemDescription()
                      << std::endl;
        }
        std::cout << std::endl;
    }
}

/*******************************************************************************
 * Name: checkBackpackForItem 
 * Description: Checks if the player currently has a certain item 
 * Parameters: Pointer to an Item object 
 ******************************************************************************/
bool Player::checkBackpackForItem(Item *itemCheckingFor)
{
    if (find(backpack.begin(), backpack.end(), itemCheckingFor) != backpack.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
