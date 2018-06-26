#ifndef CHAMBERLOCK_HPP
#define CHAMBERLOCK_HPP

#include "space.hpp"

class Chamberlock : public Space
{
public:
    Chamberlock();
    ~Chamberlock();
    virtual std::string getSpaceTypeDescription();
    virtual void spaceTypeSpecialInteraction(Player*, Item*, Item*);
};
#endif
