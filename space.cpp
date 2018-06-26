/*******************************************************************************
 * Class Name: Space
 * Description: Handles all functions related to and neccessary for a single 
 * space on the board. Functionality includes get and set functions, 
 * addItemToSpace, removeItemFromSpace, and spaceTypeSpecialInteraction.
 * Base class for all special space types (Toxic_Waste, Button, Door, Wall, 
 * Floor, and Chamberlock.
 ******************************************************************************/
#include "space.hpp"

Space::Space()
{
    up = bottom = left = right = NULL;
    spaceTypeIdentifier = ' ';
    itemInSpace = NULL;
    isPressed = false;
}

Space::Space(char typeIdentifier)
{
    up = bottom = left = right = NULL;
    spaceTypeIdentifier = typeIdentifier;
    itemInSpace = NULL;
    isPressed = false;
}

Space::~Space()
{
    up = bottom = left = right = NULL;
}

char Space::getSpaceTypeIdentifier()
{
    return spaceTypeIdentifier;
}

bool Space::getIsPressed()
{
    return isPressed;
}

Space* Space::getSpaceUp()
{
    return up;
}

Space* Space::getSpaceBottom()
{
    return bottom;
}

Space* Space::getSpaceLeft()
{
    return left;
}

Space* Space::getSpaceRight()
{
    return right;
}

char Space::getSpaceUpType()
{
    return up->spaceTypeIdentifier;
}

char Space::getSpaceBottomType()
{
    return bottom->spaceTypeIdentifier;
}

char Space::getSpaceLeftType()
{
    return left->spaceTypeIdentifier;
}

char Space::getSpaceRightType()
{
    return right->spaceTypeIdentifier;
}

Item* Space::getItemInSpace()
{
    return itemInSpace;
}

void Space::setSpaceTypeIdentifier(char typeInput)
{
    spaceTypeIdentifier = typeInput;
}

void Space::setSpaceUp(Space* spaceInput)
{
    up = spaceInput;
}

void Space::setSpaceBottom(Space* spaceInput)
{
    bottom = spaceInput;
}

void Space::setSpaceLeft(Space* spaceInput)
{
    left = spaceInput;
}

void Space::setSpaceRight(Space* spaceInput)
{
    right = spaceInput;
}

/*******************************************************************************
 * Name: addItemToSpace
 * Description: Adds an item to the operative space
 * Parameters: Pointer to an Item object
 ******************************************************************************/
void Space::addItemToSpace(Item *itemToPlace)
{
    itemInSpace = itemToPlace;
}

/*******************************************************************************
 * Name: removeItemFromSpace
 * Description: Removes an item from the operative space
 * Parameters: Pointer to an Item object
 ******************************************************************************/
void Space::removeItemFromSpace()
{
    itemInSpace = NULL;
}
