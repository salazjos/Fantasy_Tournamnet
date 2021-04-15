/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: InputValidation.h - contains
prototype methods for InputValidation.cpp. File
is used by Menu class to validate user input.
********************************************/

#ifndef FANTASYTOURNAMENT_INPUTVALIDATION_H
#define FANTASYTOURNAMENT_INPUTVALIDATION_H

#include <stdio.h>
#include <string>
using std::string;

bool isInputInteger(const string &str);
bool isNumberInRange(int selection, int rangeMin, int rangeMax);

#endif //FANTASYTOURNAMENT_INPUTVALIDATION_H
