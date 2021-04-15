/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: Menu.h - contains
prototype methods for Menu class. This class
represents a menu system. It is used by the
main.cpp to display menus, get input data from
user, and display error messages.
********************************************/

#ifndef FANTASYTOURNAMENT_MENU_H
#define FANTASYTOURNAMENT_MENU_H

#include <stdio.h>
#include <string>
#include <sstream>
#include "Character.h"
using std::string;
using std::stringstream;

class Menu{

private:

    stringstream ss_startMenu;
    stringstream ss_endMenu;
    stringstream ss_invalidInput;
    stringstream ss_invalidSelection;
    stringstream ss_characterSelection;
    stringstream ss_endOfRoundInfo;
    stringstream ss_displayLosingTeam;
    stringstream ss_endOfFightInfo;

    void initializeStringstreamObjects();
    int testForInvalidParameterInputs(const string& input, int min, int max);

public:
    Menu();
    int showAndGetCharacterSelect();
    int getEndMenuSelect();
    int getStartMenuSelect();
    int getFighterAmount();
    int getDisplayLosingTeamSelect();
    void fightingMessage();
    void selectAnotherCharacter();
    void exitGameMessage();
    void displayCharacterDeath(Character *);
    void endOfAttackInfo(Character *attack, Character *defend, int);
    void endOfFightInfo(Character *attack, Character *defend, int);
    string getCharacterName();
};

#endif //FANTASYTOURNAMENT_MENU_H
