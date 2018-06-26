#ifndef SPACE_HPP
#define SPACE_HPP

#include "item.hpp"
#include "player.hpp"

class Space
{
public:
    Space();
    Space(char);
    virtual ~Space();

    //virtual function to be used by all space types
    virtual void spaceTypeSpecialInteraction(Player*, Item*, Item*) = 0;
   
    //get and set functions
    virtual std::string getSpaceTypeDescription() = 0;
    char getSpaceTypeIdentifier();
    bool getIsPressed(); 
    Space* getSpaceUp();
    Space* getSpaceBottom();
    Space* getSpaceLeft();
    Space* getSpaceRight();
    char getSpaceUpType();
    char getSpaceBottomType();
    char getSpaceLeftType();
    char getSpaceRightType();
    Item* getItemInSpace();
    void setSpaceTypeIdentifier(char);
    void setSpaceUp(Space*);
    void setSpaceBottom(Space*);
    void setSpaceLeft(Space*);
    void setSpaceRight(Space*);
   
    //Item-related functions
    void addItemToSpace(Item*);
    void removeItemFromSpace();
protected:
    char spaceTypeIdentifier;
    bool isPressed;
    Item* itemInSpace;
    Space *up;
    Space *bottom;
    Space *left;
    Space *right;
};
#endif
