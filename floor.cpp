/*******************************************************************************
 * Class Name: Floor
 * Description: Handles all functions related to the special space type, Floor.
 * Functionality includes get and set functions, getSpaceTypeDescription, 
 * and spaceTypeSpecialInteraction. 
 * Derived class of Space. 
 ******************************************************************************/
#include "floor.hpp"

Floor::Floor()
    : Space(' ')
{
}

Floor::~Floor()
{
}

/*******************************************************************************
 * Name: getSpaceTypeDescription 
 * Description: Returns a written description of the space type 
 * Parameters: None 
 ******************************************************************************/
std::string Floor::getSpaceTypeDescription()
{
    return "Just a simple tile floor.";
}

/*******************************************************************************
 * Name: spaceTypeSpecialInteraction 
 * Description: Executes a special action specific to the space Type 
 * Parameters: Pointer to a Player object, Pointer to an Item object 
 ******************************************************************************/
void Floor::spaceTypeSpecialInteraction(Player *playerInput, Item *cc, Item *pg)
{
}
