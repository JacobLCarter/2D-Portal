/*******************************************************************************
 * Class Name: Wall
 * Description: Handles all functions related to the special space type, Wall.
 * Functionality includes get and set functions, getSpaceTypeDescription, 
 * and spaceTypeSpecialInteraction. 
 * Derived class of Space. 
 ******************************************************************************/
#include "wall.hpp"
#include <iostream>

Wall::Wall()
    : Space('X')
{
}

Wall::~Wall()
{
}

/*******************************************************************************
 * Name: getSpaceTypeDescription 
 * Description: Returns a written description of the space type 
 * Parameters: None 
 ******************************************************************************/
std::string Wall::getSpaceTypeDescription()
{
    return "A solid wall -- there is no way through this.";
}

/*******************************************************************************
 * Name: spaceTypeSpecialInteraction 
 * Description: Executes a special action specific to the space Type 
 * Parameters: Pointer to a Player object, Pointer to an Item object 
 ******************************************************************************/
void Wall::spaceTypeSpecialInteraction(Player *playerInput, Item *cc, Item *pg)
{
    //player cannot walk on walls -- should never be called
    std::cout << "How the hell did you get up there?!?" << std::endl;
}
