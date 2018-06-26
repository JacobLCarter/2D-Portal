#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <fstream>
#include <algorithm>

std::string getString(bool);
int getInt(bool);
double getDouble();
char getChar();
char getHorizontalChar();
char getVerticalChar();
char getMenuChar();
int setRange(int size, int lowerRange, int upperRange);
void fillArray(int*, std::string); 
void printArray(int*, int);
int mainMenu();
int charSelection(int);
char replay();

#endif
