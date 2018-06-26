#ifndef TOXIC_WASTE_HPP
#define TOXIC_WASTE_HPP

#include "space.hpp"

class Toxic_Waste : public Space
{
public:
    Toxic_Waste();
    ~Toxic_Waste();
    virtual std::string getSpaceTypeDescription();
    virtual void spaceTypeSpecialInteraction(Player*, Item*, Item*);
};
#endif
