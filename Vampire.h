/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: Vampire.h - contains
prototype methods for Vampire class. This class
used to represent a Vampire character. It is child
class of Character class. It is used by the GamePlay class
for construction of fighters of said type.
********************************************/

#ifndef FANTASYTOURNAMENT_VAMPIRE_H
#define FANTASYTOURNAMENT_VAMPIRE_H

#include <stdio.h>
#include "string"
#include "Character.h"
using std::string;

class Vampire : public Character{

private:

    const string type = "Vampire";

    int total_attack, total_defense,
            total_damage, new_strength;

    const int ATTACK_DICE_AMT = 1,
            DEFENSE_DICE_AMT = 1,
            ATTACK_DICE_MAX_SIDES = 12,
            DEFENSE_DICE_MAX_SIDES = 6;

    int attackRoll();
    int defenseRoll();

public:
    Vampire(int armor, int strength, string name);
    string getType() override; //virtual
    int attack(Attack_Type &, bool) override; //virtual
    void defense(int, Attack_Type, bool &,int &) override; //virtual
    int getTotalAttack() override;
    int getTotalDefense() override;
    int getTotalDamage() override;
    int getNewStrength() override;
    void healthRecovery() override; //virtual
};

#endif //FANTASYTOURNAMENT_VAMPIRE_H
