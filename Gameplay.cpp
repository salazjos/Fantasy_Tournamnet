/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: GamePlay.cpp - contains method
implementations for GamePlay class.
********************************************/

#include "Gameplay.h"
#include "Menu.h"
#include "Character.h"
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include "Character_Node.h"
#include "Character_Linked_List.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
/*************************
Class constructor
*************************/

Gameplay::Gameplay(){

    team_one.character_list = new Character_Linked_List();
    team_two.character_list = new Character_Linked_List();
    losing_list = new Character_Linked_List();
    srand(time(nullptr));

}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function runs the
Fantasy Combat Tournament game
******************************************/
void Gameplay::playGame(){

    int fighter_amount = 0, coin_toss = 0, attackingTeam = 0;
    int attackAMt = 0, attack_amount = 1, endMenu_selection = 0,
            startGame_selection = 0, displayLosingFighters_selection = 0;
    int attacking_character = 0, defending_character = 0,
            charm_counter = 1, fightNumber = 1;
    bool isCharacterDead = false, charmOn = false;
    Character::Attack_Type a_type;

    //get menu selection
    startGame_selection = menu.getStartMenuSelect();

    if(startGame_selection == 2){
        //display game ending message
        menu.exitGameMessage();
        return;
    }

    do{
        //get the fighter amount for both teams.
        fighter_amount = menu.getFighterAmount();

        //inititalize the teams with characters
        cout << "\n--- Setting up Team 1 roster ---" << endl;
        initializeTeam(team_one, fighter_amount);
        cout << "\n--- Setting up Team 2 roster ---" << endl;
        initializeTeam(team_two, fighter_amount);

        //display team rosters
        cout << "\nTeam 1 is: " << endl;
        team_one.character_list->traverse_forward();
        cout << "\nTeam 2 is: " << endl;
        team_two.character_list->traverse_forward();

        //determine who will attack first
        coin_toss = (1 + rand() % 2);
        attackingTeam = (coin_toss == 1) ? 1 : 2;

        while(!team_one.character_list->isEmpty() && !team_two.character_list->isEmpty()){

            //assign who is attacking/defending
            assignAttackingDefending(attackingTeam);
            //display characters are fighting
            menu.fightingMessage();

            while(!isCharacterDead){

                while(attack_amount <= 2){
                    //charm is activated. potential attack is 50%
                    if(charmOn && charm_counter == 3){
                        attackAMt = attacking_c->attack(a_type, charmOn = true);
                        charm_counter = 0;
                        charmOn = false;
                    }
                    else{ //normal attack
                        attackAMt = attacking_c->attack(a_type, charmOn);
                    }

                    //character defends.
                    int defender_strength = 0;
                    defending_c->defense(attackAMt, a_type, charmOn, defender_strength);

                    //test if defending character has died
                    if(defending_c->getStrength_points() <= 0){
                        //display the end of fight results
                        endOfFightInfo(attacking_c, defending_c, fightNumber);
                        //character has died
                        isCharacterDead = true;
                        //place loser at the back of the losing list
                        losing_list->insert_front(defending_c);
                        //assign points to the winning team
                        (attackingTeam == 1) ? team_one.team_score += WIN_POINTS :
                                team_two.team_score += WIN_POINTS;
                        //recover some health to the attacker
                        attacking_c->healthRecovery();

                        team_one.character_list->pop_front();
                        team_two.character_list->pop_front();

                        //add attacking character to back of team list since they won
                        (attackingTeam == 1) ? team_one.character_list->insert_back(attacking_c) :
                        team_two.character_list->insert_back(attacking_c);

                        //flip attacker and defender
                        attackingTeam = (attackingTeam == 1) ? 2 : 1;

                        attacking_c = nullptr;
                        defending_c = nullptr;
                        //break from inner while loop
                        break;
                    }

                    if(charmOn)
                        charm_counter++;

                    attack_amount++;
                    a_type = Character::NORMAL_ATTACK;
                    attackingTeam = (attackingTeam == 1) ? 2 : 1;
                } //end inner most while loop

                attack_amount = 0;
            } //end middle while loop

            fightNumber++;
            isCharacterDead = false;
        } //end outer most while loop

        //display end of tournamment info
        endTournamentInfo();
        //ask to display losing pile
        displayLosingFighters_selection = menu.getDisplayLosingTeamSelect();
        //display losing pile if selected
        if(displayLosingFighters_selection == 1){
            displayLosingFighters();
        }

        team_one.team_score = 0;
        team_two.team_score = 0;
        isCharacterDead = false;
        fightNumber = 1;
        delete attacking_c;
        attacking_c = nullptr;
        delete defending_c;
        defending_c = nullptr;

        while(!team_one.character_list->isEmpty()){
            team_one.character_list->pop_front();
        }

        while(!team_two.character_list->isEmpty()){
            team_two.character_list->pop_front();
        }

        while(!losing_list->isEmpty()){
            losing_list->pop_front();
        }

        //ask if they would like to play again
        endMenu_selection = menu.getEndMenuSelect();

    }while(endMenu_selection != 2);

    menu.exitGameMessage();

    if(attacking_c != nullptr){
        delete attacking_c;
        attacking_c = nullptr;
    }

    if(defending_c != nullptr){
        delete defending_c;
        defending_c = nullptr;
    }
}

/******************************************
Function parameters: CharacterTeam &team - team to initialize
                     const int &fight_amt - amount of fighters
Function Return type: void
Function Description: Function initializes team roster via reference.
Function uses addFighterToList function to create characters and
assign to team list.
******************************************/
void Gameplay::initializeTeam(CharacterTeam &team, const int &fight_amt){

    int character_choice = 0;
    string fighter_name;
    for(int i = 0; i < fight_amt; i++){

        //choose type of fighter
        character_choice = menu.showAndGetCharacterSelect();

        //get the name of the fighter
        fighter_name = menu.getCharacterName();

        //add fighter to the list
        addFighterToList(team, character_choice, fighter_name);
    }
}

/******************************************
Function parameters: CharacterTeam &team - team to initialize
                     const int &select - character selection
Function Return type: void
Function Description: Function initializes characters and fills
team list.
******************************************/
void Gameplay::addFighterToList(CharacterTeam &team, const int &selection, const string& name){


    switch(selection){
        case 1:
            //c = new Vampire(1,18);
            //c->setFighterName(name);
            team.character_list->insert_back(new Vampire(1,18, name));
            break;
        case 2:
            //c = new Barbarian(0,12);
            // c->setFighterName(name);
            team.character_list->insert_back(new Barbarian(0,12, name));
            break;
        case 3:
            //  c = new BlueMen(3,12);
            //  c->setFighterName(name);
            team.character_list->insert_back(new BlueMen(3,12, name));
            break;
        case 4:
            //  c = new Medusa(3,8);
            //  c->setFighterName(name);
            team.character_list->insert_back(new Medusa(3,8, name));
            break;
        case 5:
            //   c = new HarryPotter(0,10);
            //   c->setFighterName(name);
            team.character_list->insert_back(new HarryPotter(0,10, name));
            break;
        default: break;
    }
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function displays the losing
fighters from the losing_list.
******************************************/
void Gameplay::displayLosingFighters(){
    cout << endl;
    cout << losing_list->getAmount() << " loosing fighters." << endl;
    cout << "Losing fighters are: " << endl;
    losing_list->traverse_forward();
}

/******************************************
Function parameters: const int &attacking_team - which team is attacking
Function Return type: void
Function Description: Based on attacking team value, function
assigns attacking and defending characters from teams.
******************************************/
void Gameplay::assignAttackingDefending(const int &attacking_team){

    if(attacking_team == 1){
        attacking_c = team_one.character_list->getFront();
        defending_c = team_two.character_list->getFront();
    }
    else{ //attackingTeam == 2
        attacking_c = team_two.character_list->getFront();
        defending_c = team_one.character_list->getFront();
    }
}

/******************************************
Function parameters: Character *a - first character
                     Character *b - second character
Function Return type: void
Function Description: Function displays end of fight info;
which characters fought, type and name, and who won that
round.
******************************************/
void Gameplay::endOfFightInfo(Character *a, Character *b, int fightNumber){

    cout << "\n --- Fight " << fightNumber << " ---" << endl;
    cout << a->getType() << " - " << a->getFighterName() << endl;
    cout << "vs" << endl;
    cout << b->getType() << " - " << b->getFighterName() << endl;
    cout << "Winner is " << a->getType() << " - " << a->getFighterName() << endl;
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function displays end
of tournament info; teams scores and winning
team.
******************************************/
void Gameplay::endTournamentInfo(){

    cout << "\n Team 1 final score: " << team_one.team_score << endl;
    cout << " Team 2 final score: " << team_two.team_score << endl;

    if(team_one.team_score == team_two.team_score){
        cout <<"Tournament was a tie." << endl;
    }
    else if(team_one.team_score > team_two.team_score){
        cout << "Tournament winner: Team 1" << endl;
    }
    else if(team_two.team_score > team_one.team_score){
        cout << "Tournament winner: Team 2" << endl;
    }
}

/******************************************
Function parameters: pointer to a character linked list
Function Return type: void
Function Description: removes all nodes from the list
******************************************/
void Gameplay::emptyCharacterList(Character_Linked_List *list){
    while(!list->isEmpty())
        list->pop_front();
}

/*******
class destructor
******/
Gameplay::~Gameplay(){

    emptyCharacterList(team_one.character_list);
    emptyCharacterList(team_two.character_list);
    emptyCharacterList(losing_list);

    delete losing_list;
    delete team_one.character_list;
    delete team_two.character_list;
}
