#ifndef DOOR_HPP
#define DOOR_HPP

#include "space.hpp"

class Door : public Space
{
public:
    Door();
    ~Door();
    virtual std::string getSpaceTypeDescription();
    virtual void spaceTypeSpecialInteraction(Player*, Item*, Item*);
};
#endif
