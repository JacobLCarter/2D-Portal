/*******************************************************************************
 * Class Name: World_Map
 * Description: Handles all functions related to and neccessary for creating and
 * maintaining the board. 
 * Functionality includes get and set functions, makeNewMap, initializeSpecialSpaces,
 * initializeItems, linkRooms, addFloor, addToxic_Waste, addButton, addDoor, 
 * addWall, addChamberlock, openDoor, and showMap.
 ******************************************************************************/
#include "worldMap.hpp"
#include <iostream>

World_Map::World_Map()
{
    setRows(5);
    setColumns(5);
    cake = new Item("Cake", "Delicious birthday cake -- eating restores 5 turns.",
                    '+');
    portalGun = new Item("Portal Gun", "Spacial Manipulation Device allowing for"
                         " instantaneous traversal of great distance.", '%');
    companionCube = new Item("Companion Cube", "A very heavy metal cube that is"
                             " emblazoned with a large heart.", '#');
    makeNewMap();
}

World_Map::~World_Map()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            delete testChamberMap[i][j];
        }
        delete [] testChamberMap[i];
    }
    delete [] testChamberMap;
    testChamberMap = NULL;

    delete cake;
    delete portalGun;
    delete companionCube;
}

int World_Map::getRows()
{
    return rows;
}

int World_Map::getColumns()
{
    return columns;
}

Space*** World_Map::getTestChamberMap()
{
    return testChamberMap;
}

/*******************************************************************************
 * Name: getItem 
 * Description: Returns a pointer to the specified Item 
 * Parameters: Integer 
 ******************************************************************************/
Item* World_Map::getItem(int itemToGet)
{
    //switch based on item specified
    switch (itemToGet)
    {
        case 1: return cake;
                break;
        case 2: return portalGun;
                break;
        case 3: return companionCube;
                break;
    }

    return NULL;
}

void World_Map::setRows(int rowsInput)
{
    rows = rowsInput;
}

void World_Map::setColumns(int columnsInput)
{
    columns = columnsInput;
}

/*******************************************************************************
 * Name: getMapLegend 
 * Description: Returns the legend for the game map 
 * Parameters: None 
 ******************************************************************************/
std::string World_Map::getMapLegend()
{
    std::string mapLegendText;

    mapLegendText = "MAP LEGEND\n";
    mapLegendText += "----------\n";
    mapLegendText += "* : My current position.\n";
    mapLegendText += testChamberMap[1][0]->getSpaceTypeIdentifier();
    mapLegendText += " : ";
    mapLegendText += testChamberMap[1][0]->getSpaceTypeDescription();
    mapLegendText += "\n";
    mapLegendText += testChamberMap[0][1]->getSpaceTypeIdentifier();
    mapLegendText += " : ";
    mapLegendText += testChamberMap[0][1]->getSpaceTypeDescription();
    mapLegendText += "\n";
    mapLegendText += testChamberMap[1][3]->getSpaceTypeIdentifier();
    mapLegendText += " : ";
    mapLegendText += testChamberMap[1][3]->getSpaceTypeDescription();
    mapLegendText += "\n";
    mapLegendText += testChamberMap[1][1]->getSpaceTypeIdentifier();
    mapLegendText += " : ";
    mapLegendText += testChamberMap[1][1]->getSpaceTypeDescription();
    mapLegendText += "\n";
    mapLegendText += testChamberMap[3][4]->getSpaceTypeIdentifier();
    mapLegendText += " : ";
    mapLegendText += testChamberMap[3][4]->getSpaceTypeDescription();
    mapLegendText += "\n";
    mapLegendText += testChamberMap[1][4]->getSpaceTypeIdentifier();
    mapLegendText += " : ";
    mapLegendText += testChamberMap[1][4]->getSpaceTypeDescription();
    mapLegendText += "\n";
    mapLegendText += cake->getItemTypeIdentifier(); 
    mapLegendText += " : ";
    mapLegendText += cake->getItemName(); 
    mapLegendText += " - ";
    mapLegendText += cake->getItemDescription();
    mapLegendText += "\n";
    mapLegendText += portalGun->getItemTypeIdentifier();
    mapLegendText += " : ";
    mapLegendText += portalGun->getItemName();
    mapLegendText += " - ";
    mapLegendText += portalGun->getItemDescription();
    mapLegendText += "\n";
    mapLegendText += companionCube->getItemTypeIdentifier();
    mapLegendText += " : ";
    mapLegendText += companionCube->getItemName();
    mapLegendText += " - ";
    mapLegendText += companionCube->getItemDescription();
    mapLegendText += "\n\n";

    return mapLegendText;
}

/*******************************************************************************
 * Name: makeNewMap 
 * Description: Creates a new map of Floor spaces, adds special spaces, links
 * rooms, and adds all items
 * Parameters: None 
 ******************************************************************************/
void World_Map::makeNewMap()
{
     
    testChamberMap = new Space**[rows];
    for (int i = 0; i < rows; i++)
    {
        testChamberMap[i] = new Space*[columns];

        for (int j = 0; j < columns; j++)
        {
            testChamberMap[i][j] = new Floor;
        }
    }
   
    //add all special-type spaces
    initializeSpecialSpaces();
    //link all rooms together
    linkRooms();
    //add all items the map
    initializeItems();
}

/*******************************************************************************
 * Name: initializeSpecialSpaces 
 * Description: Adds all special spaces to the map 
 * Parameters: None 
 ******************************************************************************/
void World_Map::initializeSpecialSpaces()
{
    addButton(1, 1);
    addDoor(1, 3);
    addChamberlock(1, 4);
    addToxic_Waste(4, 3);
    addToxic_Waste(3, 4);
    addToxic_Waste(1, 2);
    addWall(0, 1);
    addWall(0, 3);
    addWall(0, 4);
    addWall(2, 0);
    addWall(2, 3);
    addWall(2, 4);
    addWall(3, 1);
}

/*******************************************************************************
 * Name: initializeItems 
 * Description: Adds all items to the map 
 * Parameters: None 
 ******************************************************************************/
void World_Map::initializeItems()
{
    testChamberMap[0][2]->addItemToSpace(cake);
    testChamberMap[3][0]->addItemToSpace(portalGun);
    testChamberMap[4][4]->addItemToSpace(companionCube);
}

/*******************************************************************************
 * Name: linkRooms 
 * Description: Creates a linked structure from the map array 
 * Parameters: None 
 ******************************************************************************/
void World_Map::linkRooms()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            //if not an edge, link to room above
            if (i > 0)
            {
                testChamberMap[i][j]->setSpaceUp(testChamberMap[i - 1][j]);
            }
            //if not an edge, link to room left
            if (j > 0)
            {
                testChamberMap[i][j]->setSpaceLeft(testChamberMap[i][j - 1]);
            }
            //if not an edge, link to room below
            if (i < rows - 1)
            {
                testChamberMap[i][j]->setSpaceBottom(testChamberMap[i + 1][j]);
            }
            //if not an edge, link to room right
            if (j < columns - 1)
            {
                testChamberMap[i][j]->setSpaceRight(testChamberMap[i][j + 1]);
            }
        }
    }
}

void World_Map::addFloor(int x, int y)
{
    delete testChamberMap[x][y];
    testChamberMap[x][y] = new Floor;
}

void World_Map::addToxic_Waste(int x, int y)
{
    delete testChamberMap[x][y];
    testChamberMap[x][y] = new Toxic_Waste;
}

void World_Map::addButton(int x, int y)
{
    delete testChamberMap[x][y];
    testChamberMap[x][y] = new Button;
}

void World_Map::addDoor(int x, int y)
{
    delete testChamberMap[x][y];
    testChamberMap[x][y] = new Door;
}

void World_Map::addWall(int x, int y)
{
    delete testChamberMap[x][y];
    testChamberMap[x][y] = new Wall;
}

void World_Map::addChamberlock(int x, int y)
{
    delete testChamberMap[x][y];
    testChamberMap[x][y] = new Chamberlock;
}

/*******************************************************************************
 * Name: openDoor 
 * Description: Opens the door when the button is pressed and adds the 
 * Companion cube to the button
 * Parameters: None 
 ******************************************************************************/
void World_Map::openDoor()
{
    testChamberMap[1][3]->setSpaceTypeIdentifier(' ');
    testChamberMap[1][1]->addItemToSpace(companionCube);
}

/*******************************************************************************
 * Name: showMap 
 * Description: Prints the world map 
 * Parameters: None 
 ******************************************************************************/
void World_Map::showMap()
{
    std::cout << std::endl;
    std::cout << std::string(16, '-') << std::endl; 
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            //if there is an item in the space, prints the item's identifier
            if (!testChamberMap[i][j]->getItemInSpace() == NULL)
            {
                //if the final space, print a border after the identifier
                if (j == 4)
                {
                    std::cout << " " << testChamberMap[i][j]->getItemInSpace()->
                    getItemTypeIdentifier() << " |";
                }
                else
                {
                    std::cout << " " << testChamberMap[i][j]->getItemInSpace()->
                        getItemTypeIdentifier() << " ";
                }
            }
            //if there is no item in the space, prints the spaces's identifier
            else
            {
                //if the final space, print a border after the identifier
                if (j == 4)
                {
                    std::cout << " " << testChamberMap[i][j]->getSpaceTypeIdentifier() << " |";
                }
                else
                { 
                    std::cout << " " << testChamberMap[i][j]->getSpaceTypeIdentifier() << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::string(16, '-') << std::endl; 
}
