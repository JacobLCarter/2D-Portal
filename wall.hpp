#ifndef WALL_HPP
#define WALL_HPP

#include "space.hpp"

class Wall : public Space
{
public:
    Wall();
    ~Wall();
    virtual std::string getSpaceTypeDescription();
    void spaceTypeSpecialInteraction(Player*, Item*, Item*);
};
#endif
