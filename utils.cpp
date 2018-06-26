/*******************************************************************************
 * Name: Utils
 * Description: A set of utilities for checking user input and printing menus
 ******************************************************************************/

#include "utils.hpp"
#include <iostream>
#include <cstdlib>

/***********************************************************************
 * Name: getString
 * Description: Promts the user to input a std::string 
 **********************************************************************/
std::string getString(bool prompt)
{
    std::string input;
  
    if (prompt == true)
    {
        std::cout << "Enter a word or phrase: ";
    }

    //get the user's input
    std::getline(std::cin, input);

    //remprompt if input is empty std::string
    while (input == "")
    {
        std::cout << "Empty string -- enter at least one character: "
            << std::endl;
        std::getline(std::cin, input);
    }
    
    return input;
}

/***********************************************************************
 * Name: getInt 
 * Description: Prompts the user to input an int and validates it
 **********************************************************************/
int getInt(bool prompt)
{
    std::string input;

    //causes the function to output a generic prompt
    if (prompt == true)
    {
        std::cout << "Enter an integer: ";
    }

    //get the users input
    std::getline(std::cin, input);

    //reprompt if the input is blank or not made up of int values 
    while (input.find_first_not_of("0123456789-") != std::string::npos ||
            input == "")
    {
        std::cout << "Not an integer -- please enter an int: " 
            << std::endl;
        std::getline(std::cin, input);
    }
       
    //convert the input to an integer
    int i = std::atoi(input.c_str());
    
    return i;
}

/***********************************************************************
 * Name: getDouble
 * Description: Prompts the user to input a double and validates it
 **********************************************************************/
double getDouble()
{
    std::string input;
  
    std::cout << "Enter a double :";
    std::getline(std::cin, input);

    while (input.find_first_not_of("0123456789.-") != std::string::npos ||
            input == "")
    {
        std::cout << "Not a double -- enter a double: " << std::endl;
        std::getline(std::cin, input);
    }
        
    double d = std::atof(input.c_str());
    
    return d;
}

/************************************************************************
 * Name: getChar
 * Description: Prompts the user for a char and validates it 
 ***********************************************************************/
char getChar()
{
    
    std::string input;
  
    std::getline(std::cin, input);

    while (input.find_first_not_of("wsadebmthx") != std::string::npos ||
            input == "")
    {
        std::cout << "Not a valid control input -- try again" 
            << std::endl;
        std::getline(std::cin, input);
    }

    return input[0];
}

/************************************************************************
 * Name: getHorizontalChar
 * Description: Prompts the user for a char and validates it 
 ***********************************************************************/
char getHorizontalChar()
{
    
    std::string input;
  
    std::getline(std::cin, input);

    while (input.find_first_not_of("adx") != std::string::npos ||
            input == "")
    {
        std::cout << "Not a valid control input -- try again" 
            << std::endl;
        std::getline(std::cin, input);
    }

    return input[0];
}

/************************************************************************
 * Name: getVerticalChar
 * Description: Prompts the user for a char and validates it 
 ***********************************************************************/
char getVerticalChar()
{
    
    std::string input;
  
    std::getline(std::cin, input);

    while (input.find_first_not_of("wsx") != std::string::npos ||
            input == "")
    {
        std::cout << "Not a valid control input -- try again" 
            << std::endl;
        std::getline(std::cin, input);
    }

    return input[0];
}

char getMenuChar()
{
    
    std::string input;
  
    std::getline(std::cin, input);

    while (input.find_first_not_of("yn") != std::string::npos ||
            input == "")
    {
        std::cout << "Not a valid control input -- try again" 
            << std::endl;
        std::getline(std::cin, input);
    }

    return input[0];
}

/************************************************************************
 * Name: setRange
 * Description: used to limit user input to a specific range
 ***********************************************************************/
int setRange(int size, int lowerRange, int upperRange)
{
    int status = -1;

    //if the input is within the desired range and 0 is
    //allowed, set status to 0
    if (size >= lowerRange && size <= upperRange)
    {
        status = 0;
    }

    return status;
}


/************************************************************************
 * Name: fillArray
 * Description: Fills an array with integers from the specified file 
 ***********************************************************************/
void fillArray(int *array, std::string filename)
{
    std::ifstream fins;
    fins.open(filename.c_str());
    
    std::string line;
    
    while (std::getline(fins, line))
    {
        line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

        for (unsigned int i = 0; i < line.size(); i++)
        {
            int j = line[i] - '0'; 
            array[i] = j;
        }
    }
    fins.close();
}

/************************************************************************
 * Name: printArray
 * Description: Prints the values of an array 
 ***********************************************************************/
void printArray(int *array, int s)
{
    int i = 0;
    
    while (i < s)
    {
        std::cout << array[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

/*************************************************************************
 * Name: mainMenu
 * Description: Prints the main  menu to the screen, allows the user to make
 * one of the choices listed, and returns the choice to main.
 * Aperture Science Logo art sourced from: http://archive.jamisonjudd.com/aperture-science-logo/
 ************************************************************************/
int mainMenu()
{
    int choice;
    std::string logo;

    logo = "              .,-:;/;;:=,\n";
    logo += "         . :H@@@MM@M#H/.,+%;,\n";
    logo += "      ,/X+ +M@@M@MM%=,-%HMMM@X/,\n";
    logo += "    -+@MM; $M@@MH+-,;XMMMM@MMMM@+-\n";
    logo += "   ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.\n";
    logo += " ,%MM@@MH ,@%=             .---=-=:=,.\n";
    logo += " =@#@@@MX.,                -%HX$$%%%:;\n";
    logo += "=-./@M@M$                   .;@MMMM@MM:\n";
    logo += "X@/ -$MM/       PORTAL       . +MM@@@M$\n";
    logo += "@M@H: :@:       ------       . =X#@@@@-\n";
    logo += "@@@MMX, .       1. Play      /H- ;@M@M=\n";
    logo += "H@@@@M@+,       2. Quit      %MM+..%#$.\n";
    logo += "/MMMM@MMH/.                  XM@MH; =;\n";
    logo += " /%+%$XHH@$=              , .H@@@@MX,\n";
    logo += "  .=--------.           -%H.,@@@@@MX,\n";
    logo += "  .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM%.\n";
    logo += "    =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=\n";
    logo += "      =%@M@M#@$-.=$@MM@@@M; %M%=\n";
    logo += "        ,:+$+-,/H#MMMMMMM@= =,\n";
    logo += "              =++%%%%+/:-.\n";


    
    do
    {
        std::cout << logo << std::endl << std::endl;
        std::cout << "Please enter a choice 1-2: ";
        
        choice = getInt(false);

        std::cout << std::endl;
    }
    while (setRange(choice, 1, 2) != 0);

    return choice;
}

/*************************************************************************
 * Name: replay
 * Description: Prompts the user for a replay 
 ************************************************************************/
char replay()
{
    char choice;

    do
    {
        std::cout << std::endl;
        std::cout << "Would you like to play again? (y/n)" << std::endl;
        choice = getMenuChar();
    }
    while (choice != 'y' && choice !='n');

    return choice;
}

/*************************************************************************
 * Name: selectionYN
 * Description: Allows the user to enter 'y' or 'n' for choice 
 ************************************************************************/
char selectionYN()
{
    char choice;

    do
    {
        std::cout << std::endl;
        std::cout << "Please enter yes or no? (y/n)" << std::endl;
        choice = getMenuChar();
    }
    while (choice != 'y' && choice != 'n');

    return choice;
}
