#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "space.hpp"

class Floor : public Space
{
public:
    Floor();
    ~Floor();
    virtual std::string getSpaceTypeDescription();
    virtual void spaceTypeSpecialInteraction(Player*, Item*, Item*);
};
#endif
