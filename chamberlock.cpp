/*******************************************************************************
 * Class Name: Chamberlock
 * Description: Handles all functions related to the special space type, 
 * Chamberlock.
 * Functionality includes get and set functions, getSpaceTypeDescription, 
 * and spaceTypeSpecialInteraction. 
 * Derived class of Space. 
 ******************************************************************************/
#include "chamberlock.hpp"
#include <iostream>

Chamberlock::Chamberlock()
    : Space('?')
{
}

Chamberlock::~Chamberlock()
{
}

/*******************************************************************************
 * Name: getSpaceTypeDescription 
 * Description: Returns a written description of the space type 
 * Parameters: None 
 ******************************************************************************/
std::string Chamberlock::getSpaceTypeDescription()
{
    return "A shimmering tube, reminiscent of an elevator. A potential escape...";
}

/*******************************************************************************
 * Name: spaceTypeSpecialInteraction 
 * Description: Executes a special action specific to the space Type 
 * Parameters: Pointer to a Player object, Pointer to an Item object 
 ******************************************************************************/
void Chamberlock::spaceTypeSpecialInteraction(Player *playerInput, Item *cc, Item *pg)
{
    playerInput->removeItemFromBackpack(pg);

    std::cout << "Portal Gun vaporized by Material Emancipation Grill." << std::endl;
}
