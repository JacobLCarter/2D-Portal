/*******************************************************************************
 * Class Name: Toxic_Waste
 * Description: Handles all functions related to the special space type, Toxic
 * Waste.
 * Functionality includes get and set functions, getSpaceTypeDescription, 
 * and spaceTypeSpecialInteraction. 
 * Derived class of Space. 
 ******************************************************************************/
#include "toxic_waste.hpp"

Toxic_Waste::Toxic_Waste()
    : Space('~')
{
}

Toxic_Waste::~Toxic_Waste()
{
}

/*******************************************************************************
 * Name: getSpaceTypeDescription 
 * Description: Returns a written description of the space type 
 * Parameters: None 
 ******************************************************************************/
std::string Toxic_Waste::getSpaceTypeDescription()
{
    return "A bubbling deposit of green sludge that can't be safe to walk on.";
}

/*******************************************************************************
 * Name: spaceTypeSpecialInteraction 
 * Description: Executes a special action specific to the space Type 
 * Parameters: Pointer to a Player object, Pointer to an Item object 
 ******************************************************************************/
void Toxic_Waste::spaceTypeSpecialInteraction(Player *playerInput, Item *cc, Item *pg)
{
    //sets the player's hit points to 0
    playerInput->setHitPoints(0);
}
