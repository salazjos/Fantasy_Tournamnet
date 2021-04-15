/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: GamePlay.h - contains
prototype methods for GamePlay class. This class is used
by main.cpp to enable gameplay of Fantast Combat
Tournament game. It contains all core logic for
gameplay simulation.
********************************************/

#ifndef FANTASYTOURNAMENT_GAMEPLAY_H
#define FANTASYTOURNAMENT_GAMEPLAY_H

#include <stdio.h>
#include "Menu.h"
#include "Character.h"
#include "Character_Linked_List.h"

class Gameplay {
private:

    Menu menu;
    Character *attacking_c = nullptr;
    Character *defending_c = nullptr;
    const int WIN_POINTS = 2;

    struct CharacterTeam{
        int team_score = 0;
        Character_Linked_List *character_list;
    };

    CharacterTeam team_one, team_two;

    Character_Linked_List *losing_list;

    void initializeTeam(CharacterTeam &, const int &fightAmt);
    void addFighterToList(CharacterTeam &, const int &selection, const string& name);
    void displayLosingFighters();
    void endOfFightInfo(Character *a, Character *b, int);
    void assignAttackingDefending(const int &);
    void endTournamentInfo();
    void emptyCharacterList(Character_Linked_List *list);

public:
    Gameplay();
    void playGame();
    ~Gameplay();
};


#endif //FANTASYTOURNAMENT_GAMEPLAY_H
