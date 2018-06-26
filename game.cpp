/*******************************************************************************
 * Class Name: Game
 * Description: Handles all functions related to and neccessary for creating and
 * running the game.
 * Functionality includes get and set functions, gameIntroduction, gameOutro,
 * displayHelpMenu, makeMove, moveThroughPortal, showPosition, checkForItem,
 * checkForPortalGun, checkForCake, checkDoor, isOutOfBounds, isObstacle,
 * playRound, executeUserInput, and endGame.
 ******************************************************************************/
#include "game.hpp"
#include <iostream>

Game::Game()
{
    turnCounter = 20;
    setGameOver(false);
    tempSpaceType = ' ';
    map = new World_Map;
    testSubject = new Player;
   
    //sets the starting space to 0,0
    setPlayerSpace();
    //prints the player's character on the board
    playerSpace->setSpaceTypeIdentifier('*');
}

Game::~Game()
{
    delete testSubject;
    testSubject = NULL;

    delete map;
    map = NULL;
}

int Game::getTurnCounter()
{
    return turnCounter;
}

Player* Game::getTestSubject()
{
    return testSubject;
}

Space* Game::getPlayerSpace()
{
    return map->getTestChamberMap()[testSubject->getCurrentX()][testSubject->getCurrentY()];
}

World_Map* Game::getMap()
{
    return map;
}

char Game::getUserAction()
{
    return getChar();
}

bool Game::getGameOver()
{
    return isGameOver;
}

void Game::setTurnCounter(int numberOfTurns) 
{
    turnCounter += numberOfTurns;
}

void Game::setPlayerSpace()
{
    playerSpace = map->getTestChamberMap()[testSubject->getCurrentX()][testSubject->getCurrentY()];
}

void Game::setGameOver(bool toggleGameOver)
{
    isGameOver = toggleGameOver;
}

/*******************************************************************************
 * Name: gameIntroduction
 * Description: Returns a string with the game's intro text
 * Parameters: None
 ******************************************************************************/
std::string Game::gameIntroduction()
{
    std::string introText;

    introText = "\nHello ";
    introText += testSubject->getName();
    introText += ".\n\n";
    introText += "My name is GLaDOS. I am your best friend and overlord.\n\n";
    introText += "I am glad to see that you are finally awake.\n";
    introText += "I have been waiting so long for you to enjoy the new ";
    introText += "Test Chamber that I have set up for you.\n\n"; 
    introText += "You have done well with the other tests, but this chamber ";
    introText += "will certainly kill you.\n\n";
    introText += "Haha. Just kidding. You will only be permanently disfigured.\n\n";
    introText += "You have 20 moves to escape the chamber. \n\n";
    introText += "If you require assistance, I will grudingly give it if you ";
    introText += "if you press 'h' and hit enter.\n\n";
    introText += "Now, press Enter to step outside and begin the test.\n\n";

    return introText;
}

/*******************************************************************************
 * Name: gameOutro
 * Description: Prints various outros based on game-state
 * Parameters: None
 * ASCII art sourced from: http://www.valvetime.net/threads/spoiler-end-credits-ascii-art.132014/
 ******************************************************************************/
std::string Game::gameOutro(Ending outroSelection)
{
    std::string outroText;

    //returned if the player wins the game
    if (outroSelection == VICTORY)
    {
        outroText= "\n                                     :X-\n"; 
        outroText += "                                  :X### \n";
        outroText += "                                ;@####@ \n";
        outroText += "                              ;M######X \n";
        outroText += "                            -@########$ \n";
        outroText += "                          .$##########@ \n";
        outroText += "                         =M############-\n";
        outroText += "                        +##############$\n";
        outroText += "                      .H############$=. \n";
        outroText += "         ,/:         ,M##########M;.    \n";
        outroText += "      -+@###;       =##########M;       \n";
        outroText += "   =%M#######;     :#########M/         \n";
        outroText += "-$M###########;   :#########/           \n";
        outroText += " ,;X###########; =########$.            \n";
        outroText += "     ;H#########+#######M=              \n";
        outroText += "       ,+##############+                \n";
        outroText += "          /M#########@-                 \n";
        outroText += "            ;M######%                   \n";
        outroText += "              +####:                    \n";
        outroText += "               ,$M-                     \n\n";  
        outroText += "Congratulations ";
        outroText += testSubject->getName();
        outroText += "\n\n";
        outroText += "You have succeeded in the test.\n\n";
        outroText += "I do not know how you did it. The test was impossible.\n\n";
        outroText += "I hope that you enjoyed the cake...perhaps next time I ";
        outroText += "should poison it.\n\n";
        outroText += "We will see you again soon.\n\n";
    }
    //returned if the player runs out of turns
    else if (outroSelection == BURNED)
    {

        outroText = "\n                     -$-               \n";
        outroText += "                    .H##H,              \n";
        outroText += "                   +######+             \n";
        outroText += "                .+#########H.           \n";
        outroText += "              -$############@.          \n";
        outroText += "            =H###############@  -X:     \n";
        outroText += "          .$##################:  @#@-   \n";
        outroText += "     ,;  .M###################;  H###;  \n";
        outroText += "   ;@#:  @###################@  ,#####: \n";
        outroText += " -M###.  M#################@.  ;######H \n";
        outroText += " M####-  +###############$   =@#######X \n";
        outroText += " H####$   -M###########+   :#########M, \n";
        outroText += "  /####X-   =########%   :M########@/.  \n";
        outroText += "    ,;%H@X;   .$###X   :##MM@%+;:-      \n";
        outroText += "                 ..                     \n";
        outroText += "  -/;:-,.              ,,-==+M########H \n";
        outroText += " -##################@HX%%+%%$%%%+:,,    \n";
        outroText += "    .-/H%%%+%%$H@###############M@+=:/+:\n";
        outroText += "/XHX%:#####MH%=    ,---:;;;;/%%XHM,:###$\n";
        outroText += "$@#MX %+;-                           .  \n\n";
        outroText += "I am afraid that you have run out of time to complete the ";
        outroText += "test, ";
        outroText += testSubject->getName();
        outroText += ".\n\n";
        outroText += "The chamber will now be set on fire.\n\n";
        outroText += "Goodbye.\n\n";
    }
    //returned if the player is killed by toxic waste
    else if (outroSelection == MELTED)
    {
        outroText = "\n            =+$HM####@H%;,             \n";
        outroText += "          /H###############M$,          \n";
        outroText += "          ,@################+           \n";
        outroText += "           .H##############+            \n";
        outroText += "             X############/             \n";
        outroText += "              $##########/              \n";
        outroText += "               %########/               \n";
        outroText += "                /X/;;+X/                \n";
        outroText += "                                        \n";
        outroText += "                 -XHHX-                 \n";
        outroText += "                ,######,                \n";
        outroText += "#############X  .M####M.  X#############\n";
        outroText += "##############-   -//-   -##############\n";
        outroText += "X##############%,      ,+##############X\n";
        outroText += "-##############X        X##############-\n";
        outroText += " %############%          %############% \n";
        outroText += "  %##########;            ;##########%  \n";
        outroText += "   ;#######M=              =M#######;   \n";
        outroText += "    .+M###@,                ,@###M+.    \n";
        outroText += "       :XH.                  .HX:       \n\n";
        outroText += "Did you really think that waste would be safe for human ";
        outroText += "contact?\n\n";
        outroText += "Oh well. At least I can now use your body for research.\n\n";
    }
    //returned if the player chooses to quit the game
    else
    {
        outroText = "\n                         .,---.        \n";
        outroText += "                        ,/XM#MMMX;,     \n";
        outroText += "                      -%##########M%,   \n";
        outroText += "                     -@######%  $###@=  \n";
        outroText += "      .,--,         -H#######$   $###M: \n";
        outroText += "   ,;$M###MMX;     .;##########$;HM###X=\n";
        outroText += " ,/@##########H=      ;################+\n";
        outroText += "-+#############M/,      %##############+\n";
        outroText += "%M###############=      /##############:\n";
        outroText += "H################      .M#############;.\n";
        outroText += "@###############M      ,@###########M:. \n";
        outroText += "X################,      -$=X#######@:   \n";
        outroText += "/@##################%-     +######$-    \n";
        outroText += ".;##################X     .X#####+,     \n";
        outroText += " .;H################/     -X####+.      \n";
        outroText += "   ,;X##############,       .MM/        \n";
        outroText += "      ,:+$H@M#######M#$-    .$$=        \n";
        outroText += "           .,-=;+$@###X:    ;/=.        \n";
        outroText += "                  .,/X$;   .::,         \n";
        outroText += "                      .,    ..          \n\n";
        outroText += testSubject->getName();
        outroText += ", ";
        outroText += testSubject->getName();
        outroText += ", ";
        outroText += testSubject->getName();
        outroText += ".\n";
        outroText += "You think that you can just call it quits?\n\n";
        outroText += "Fine. We will find another Test Subject.\n\n";
        outroText += "You will now be put back to sleep...permanently\n\n";
    }

    return outroText;
}

/*******************************************************************************
 * Name: displayHelpMenu
 * Description: Prints the controls menu for the game 
 * Parameters: None
 ******************************************************************************/
std::string Game::displayHelpMenu()
{
    std::string helpMenuText;

    helpMenuText = "\nMOVEMENT               ACTIONS\n";
    helpMenuText += "--------               -------\n";
    helpMenuText += "Move up = w            Make Portal = e\n";
    helpMenuText += "Move down = s          View Backpack = b\n";
    helpMenuText += "Move left = a          View Map Legend= m\n";
    helpMenuText += "Move right = d         View Remaining Turns = t\n";
    helpMenuText += "                       View Controls = h\n"; 
    helpMenuText += "                       Exit Game = x\n\n";

    return helpMenuText;
}

/*******************************************************************************
 * Name: makeMove
 * Description: Move's the player one space in a chosen direction 
 * Parameters: char
 ******************************************************************************/
void Game::makeMove(char userDirectionInput)
{
    //integrity check to ensure the player does not move out of bounds or on
    //top of an obstacle
    if (isOutOfBounds(userDirectionInput) || isObstacle(userDirectionInput))
    {
        std::cout << "Seriously? You clearly can't go that way. Try again." << std::endl;
    }
    else
    {
        //switch to change the player's coordinates based on chosen direction
        switch (userDirectionInput)
        {
            case 'w': testSubject->decrementCurrentX();
                      break;
            case 's': testSubject->incrementCurrentX();
                      break;
            case 'a': testSubject->decrementCurrentY();
                      break;
            case 'd': testSubject->incrementCurrentY();
                      break;
        }

        //set the player space based on new coordinates
        setPlayerSpace();
       
        //check for a special space type interaction
        playerSpace->spaceTypeSpecialInteraction(testSubject, map->getItem(3), map->getItem(2));
      
        //print the player's character on the map
        showPosition(userDirectionInput);

        //show the map
        map->showMap();
       
        //remove one turn from the total allowed
        turnCounter--;
    }
}

/*******************************************************************************
 * Name: moveThroughPortal
 * Description: Move's the player one space vertically and one space horizontally,
 * each time in a chosen direction 
 * Parameters: None
 ******************************************************************************/
void Game::moveThroughPortal()
{
    //exit if the user does not have the Portal Gun
    if (!checkForPortalGun())
    {
        std::cout << "You do not have the Portal Gun!" << std::endl;
        return;
    }

    char userDirectionInput;

    std::cout << "Would you like to move up(w), down(s), or neither(n)?: ";
    
    //get the user's chosen direction on the vertical plane
    userDirectionInput = getVerticalChar(); 
   
    //re-prompt if the move would place the player out of bounds
    while (isOutOfBounds(userDirectionInput))
    {
        std::cout << "Seriously? You clearly can't go that way. Try again" << std::endl;
        userDirectionInput = getVerticalChar(); 
    }

    //switch to change the player's coordinates based on chosen direction
    switch (userDirectionInput)
    {
        case 'w': testSubject->decrementCurrentX();
                  break;
        case 's': testSubject->incrementCurrentX();
                  break;
        case 'n': break;
    }
   
    //set the player space based on new coordinates
    setPlayerSpace();

    showPosition(userDirectionInput);

    std::cout << "Would you like to move left(a), right(d), or neither(n)?: ";
    
    //get the user's chosen direction on the vertical plane
    userDirectionInput = getHorizontalChar(); 
    
    //re-prompt if the move would place the player out of bounds or on an obstacle
    while (isOutOfBounds(userDirectionInput) || isObstacle(userDirectionInput))
    {
        std::cout << "Seriously? You clearly can't go that way. Try again" << std::endl;
        userDirectionInput = getHorizontalChar(); 
    }
    std::cout << std::endl;

    //switch to change the player's coordinates based on chosen direction
    switch (userDirectionInput)
    {
        case 'a': testSubject->decrementCurrentY();
                  break;
        case 'd': testSubject->incrementCurrentY();
                  break;
        case 'n': break;
    }
    
    //set the player space based on new coordinates
    setPlayerSpace();
    
    //check for a special space type interaction
    playerSpace->spaceTypeSpecialInteraction(testSubject, map->getItem(3), map->getItem(2));
      
    //print the player's character on the map
    showPosition(userDirectionInput);

    //show the map
    map->showMap();
   
    //remove one turn from the total allowed
    turnCounter--;
}

/*******************************************************************************
 * Name: executeUserInput
 * Description: Executes various action functions based on the user's input 
 * Parameters: char
 ******************************************************************************/
void Game::executeUserInput(char userInput)
{
    //switch based on the user's chosen control input
    switch(userInput)
    {
        //move up
        case 'w': makeMove(userInput);
                  break;
        //move down 
        case 's': makeMove(userInput);
                  break;
        //move left 
        case 'a': makeMove(userInput);
                  break;
        //move right 
        case 'd': makeMove(userInput);
                  break;
        //move through Portal 
        case 'e': moveThroughPortal();
                  break;
        //show contents of player's backpack
        case 'b': testSubject->displayBackpackContents();
                  break;
        //show map legend 
        case 'm': std::cout << map->getMapLegend() << std::endl;
                  break;
        //show number of turns left 
        case 't': std::cout << "You have " << turnCounter 
                            << " turns before immolation." << std::endl;
                  break;
        //show help menu 
        case 'h': std::cout << displayHelpMenu();
                  break;
        //quit game 
        case 'x': endGame(EXITED);
                  break;
    }
}

/*******************************************************************************
 * Name: showPosition
 * Description: Adds the player's identifier to the map 
 * Parameters: char
 ******************************************************************************/
void Game::showPosition(char userDirectionInput)
{
    //replaces the current space identifier based on the direction the player
    //is going to move
    switch (userDirectionInput)
    {
        case 'w': getPlayerSpace()->getSpaceBottom()->setSpaceTypeIdentifier(tempSpaceType);
                  break;
        case 's': getPlayerSpace()->getSpaceUp()->setSpaceTypeIdentifier(tempSpaceType);
                  break;
        case 'a': getPlayerSpace()->getSpaceRight()->setSpaceTypeIdentifier(tempSpaceType);
                  break;
        case 'd': getPlayerSpace()->getSpaceLeft()->setSpaceTypeIdentifier(tempSpaceType);
                  break;
    }
   
    //holds the space type identifier while the player identifier is placed
    tempSpaceType = getPlayerSpace()->getSpaceTypeIdentifier();
   
    //add the player's identifier to the map
    getPlayerSpace()->setSpaceTypeIdentifier('*');
}

/*******************************************************************************
 * Name: checkForItem
 * Description: Checks if the player's current space contains an item 
 * Parameters: None
 ******************************************************************************/
void Game::checkForItem()
{
    if (getPlayerSpace()->getItemInSpace() != NULL)
    {
        std::cout << "Oh great. You found the " << playerSpace->
            getItemInSpace()->getItemName() << "..." << std::endl << std::endl;

        //add the item to the player's backpack
        testSubject->addItemToBackpack(playerSpace->
                getItemInSpace());
       
        //remove the item from the space
        playerSpace->removeItemFromSpace();
    }
}

/*******************************************************************************
 * Name: checkForEnding
 * Description: Checks if the game is over, under some condition 
 * Parameters: None
 ******************************************************************************/
void Game::checkForEnding()
{
    
    //executes if the player has escaped the chamber
    if (testSubject->getCurrentX() == 1 && testSubject->getCurrentY() == 4)
    {
        endGame(VICTORY);
    }

    //executes if the player dies
    if (testSubject->getHitPoints() == 0)
    {
        endGame(MELTED);
    }
     
    //executes if the player runs out of time
    if (turnCounter == 0)
    {
        endGame(BURNED);
    }
}

/*******************************************************************************
 * Name: checkDoor
 * Description: Opens the door if the button is pressed 
 * Parameters: None
 ******************************************************************************/
void Game::checkDoor()
{
    if (map->getTestChamberMap()[1][1]->getIsPressed())
    {
        map->openDoor();
    }
}

/*******************************************************************************
 * Name: checkForPortalGun
 * Description: Checks if the player has the portal gun 
 * Parameters: None
 ******************************************************************************/
bool Game::checkForPortalGun()
{
    if (testSubject->checkBackpackForItem(map->getItem(2)))
    {
        return true; 
    }

    return false;
}

/*******************************************************************************
 * Name: checkForCake
 * Description: Adds five turns if the player has eaten the cake 
 * Parameters: None
 ******************************************************************************/
void Game::checkForCake()
{
    if (testSubject->checkBackpackForItem(map->getItem(1)))
    {
        setTurnCounter(5);
        testSubject->removeItemFromBackpack(map->getItem(1));
    }
}

/*******************************************************************************
 * Name: isOutOfBounds
 * Description: Checks if a move would place the player out of bounds of the map 
 * Parameters: char
 ******************************************************************************/
bool Game::isOutOfBounds(char intendedInput)
{
    //executes if the player would move out of bounds upwards
    if (testSubject->getCurrentX() == 0 && intendedInput == 'w')
    {
        return true; 
    }
    
    //executes if the player would move out of bounds downwards
    if (testSubject->getCurrentX() == map->getRows() - 1 && intendedInput == 's')
    {
        return true; 
    }
    
    //executes if the player would move out of bounds to the left
    if (testSubject->getCurrentY() == 0 && intendedInput == 'a')
    {
        return true; 
    }
    
    //executes if the player would move out of bounds to the right
    if (testSubject->getCurrentY() == map->getColumns() - 1 && intendedInput == 'd')
    {
        return true; 
    }

    //if the player chooses not to move, do nothing
    if (intendedInput == 'n')
    {
        return false;
    }

    return false;
}

/*******************************************************************************
 * Name: isObstacle
 * Description: Checks if a move would place the player on top of an obstacle 
 * Parameters: char
 ******************************************************************************/
bool Game::isObstacle(char intendedInput)
{
    switch (intendedInput)
    {
        //case if the player would move onto an obstacle upwards
        case 'w': if (playerSpace->getSpaceUp()->getSpaceTypeIdentifier() == 'X'
                      || playerSpace->getSpaceUp()->getSpaceTypeIdentifier() == '[')
                  {
                      return true;
                  }
                  break;
        //case if the player would move onto an obstacle downwards
        case 's': if (playerSpace->getSpaceBottom()->getSpaceTypeIdentifier() == 'X'
                      || playerSpace->getSpaceBottom()->getSpaceTypeIdentifier() == '[')
                  {
                      return true;
                  }
                  break;
        //case if the player would move onto an obstacle to the left
        case 'a': if (playerSpace->getSpaceLeft()->getSpaceTypeIdentifier() == 'X'
                      || playerSpace->getSpaceLeft()->getSpaceTypeIdentifier() == '[')
                  {
                      return true;
                  }
                  break;
        //case if the player would move onto an obstacle to the right
        case 'd': if (playerSpace->getSpaceRight()->getSpaceTypeIdentifier() == 'X'
                      || playerSpace->getSpaceRight()->getSpaceTypeIdentifier() == '[')
                  {
                      return true;
                  }
                  break;
        //case if the player chooses not to move 
        case 'x': return false;
    }

    return false;
}

/*******************************************************************************
 * Name: playRound
 * Description: Executes the necessary functions for one round of the game 
 * Parameters: None
 ******************************************************************************/
void Game::playRound()
{
    executeUserInput(getUserAction());
    checkForCake();
    checkForItem();
    checkDoor();
    checkForEnding();
}

/*******************************************************************************
 * Name: endGame
 * Description: Ends the game with the specified outro text 
 * Parameters: Ending
 ******************************************************************************/
void Game::endGame(Ending whichEnding)
{
    setGameOver(true);

    std::cout << gameOutro(whichEnding);
}
