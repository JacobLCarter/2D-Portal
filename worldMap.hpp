#ifndef WORLD_MAP_HPP
#define WORLD_MAP_HPP

#include "toxic_waste.hpp"
#include "button.hpp"
#include "door.hpp"
#include "wall.hpp"
#include "chamberlock.hpp"
#include "floor.hpp"
#include <string>

class World_Map
{
public:
    World_Map();
    ~World_Map();
   
    //get & set functions
    int getRows();
    int getColumns();
    Space*** getTestChamberMap();
    Item* getItem(int);
    std::string getMapLegend();
    void setRows(int);
    void setColumns(int);

    //map creation functions
    void makeNewMap();
    void initializeSpecialSpaces();
    void initializeItems();
    void linkRooms();
    void addFloor(int, int);
    void addToxic_Waste(int, int);
    void addButton(int, int);
    void addDoor(int, int);
    void addWall(int, int);
    void addChamberlock(int, int);
    void openDoor();

    //print functions
    void showMap();
private:
    int rows;
    int columns;
    Space ***testChamberMap;
    Item *cake;
    Item *portalGun;
    Item *companionCube;
};
#endif
