/*******************************************************************************
 * Class Name: Button
 * Description: Handles all functions related to the special space type, Button.
 * Functionality includes get and set functions, getSpaceTypeDescription, 
 * and spaceTypeSpecialInteraction. 
 * Derived class of Space. 
 ******************************************************************************/
#include "button.hpp"
#include <iostream>

Button::Button()
    : Space('O')
{
}

Button::~Button()
{
}

/*******************************************************************************
 * Name: getSpaceTypeDescription 
 * Description: Returns a written description of the space type 
 * Parameters: None 
 ******************************************************************************/
std::string Button::getSpaceTypeDescription()
{
    return "A button that requires a lot of force to push down.";
}

/*******************************************************************************
 * Name: spaceTypeSpecialInteraction 
 * Description: Executes a special action specific to the space Type 
 * Parameters: Pointer to a Player object, Pointer to an Item object 
 ******************************************************************************/
void Button::spaceTypeSpecialInteraction(Player *playerInput, Item *cc, Item *pg)
{
    //if the player has the Companion Cube, press the button down
    if (playerInput->checkBackpackForItem(cc))
    {
        isPressed = true;
        //remove the Companion Cube from the player's backpack
        playerInput->removeItemFromBackpack(cc);
        
        std::cout << "What?! How did you just open that door?!" << std::endl;
    }
}
