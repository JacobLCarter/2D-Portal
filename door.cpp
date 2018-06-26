/*******************************************************************************
 * Class Name: Door
 * Description: Handles all functions related to the special space type, Door.
 * Functionality includes get and set functions, getSpaceTypeDescription, 
 * and spaceTypeSpecialInteraction. 
 * Derived class of Space. 
 ******************************************************************************/
#include "door.hpp"
#include <iostream>

Door::Door()
    : Space('[')
{
}

Door::~Door()
{
}

/*******************************************************************************
 * Name: getSpaceTypeDescription 
 * Description: Returns a written description of the space type 
 * Parameters: None 
 ******************************************************************************/
std::string Door::getSpaceTypeDescription()
{
    return "A sturdy door made of some type of hard plastic I don't recognize.";
}

/*******************************************************************************
 * Name: spaceTypeSpecialInteraction 
 * Description: Executes a special action specific to the space Type 
 * Parameters: Pointer to a Player object, Pointer to an Item object 
 ******************************************************************************/
void Door::spaceTypeSpecialInteraction(Player *playerInput, Item *cc, Item *pg)
{
    //printed the space before the exit
    std::cout << "The exit is right in front of me!" << std::endl; 
}
