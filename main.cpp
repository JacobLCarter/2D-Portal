/*******************************************************************************
 * Program Name: portal 
 * Author: Jacob Carter
 * Date: 3/7/2018
 * Description: This program is a 2D reimagining of the video game, Portal.
 * To run, start the game from the main menu and move through the game using the
 * specified controls.
 ******************************************************************************/
#include "game.hpp"
#include <iostream>

int main()
{
    //get user's choice at the main menu
    int menuChoice = mainMenu();

    //executes if the user chooses to play
    if (menuChoice == 1)
    {
        //loop repeats until the user chooses not to replay
        do
        {
            //make a new game
            Game *currentGame = new Game;
      
            //show the introduction and wait for the user to press enter to continue
            std::cout << currentGame->gameIntroduction();
            std::cin.get();

            //show the starting map
            currentGame->getMap()->showMap();

            //show the map legend
            std::cout << currentGame->getMap()->getMapLegend();

            //display the game's controls
            std::cout << currentGame->displayHelpMenu();

            //play another round while it is not true that the game is over
            while (!currentGame->getGameOver())
            {
                currentGame->playRound();
            }
           
            //free memory allocated for the game
            delete currentGame;
        }
        while (replay() != 'n');
    }
    else
    {
        std::cout << "Exiting the program" << std::endl;
    }
}
