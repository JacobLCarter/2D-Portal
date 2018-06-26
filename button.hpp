#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "space.hpp"

class Button : public Space
{
public:
    Button();
    ~Button();
    bool getIsPressed();
    virtual std::string getSpaceTypeDescription();
    virtual void spaceTypeSpecialInteraction(Player*, Item*, Item*);
};
#endif
