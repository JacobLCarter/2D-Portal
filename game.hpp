#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "worldMap.hpp"
#include <string>

enum Ending {VICTORY, BURNED, MELTED, EXITED};

class Game
{
public:
    Game();
    ~Game();
   
    //get and set functions
    int getTurnCounter();
    Player* getTestSubject();
    char getUserAction();
    bool getGameOver();
    void setTurnCounter(int);
    void setGameOver(bool);

    //map functions
    Space* getPlayerSpace();
    World_Map* getMap();
    void setPlayerSpace();
    
    //text menus
    std::string gameIntroduction();
    std::string gameOutro(Ending);
    std::string displayHelpMenu();

    //movement functions
    void makeMove(char);
    void moveThroughPortal();
    void showPosition(char);
   
    //game integrity check functions
    void checkForItem();
    bool checkForPortalGun();
    void checkForCake();
    void checkDoor();
    void checkForEnding();
    bool isOutOfBounds(char);
    bool isObstacle(char);
  
    //game execution functions
    void playRound();
    void executeUserInput(char);
    void endGame(Ending);
private:
    int turnCounter;
    bool isGameOver;
    char tempSpaceType;
    Player *testSubject;
    Space *playerSpace;
    World_Map *map;
};
#endif
