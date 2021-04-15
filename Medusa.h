/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: Medusa.hpp - contains
prototype methods for Medusa class. This class
used to represent a Medusa character. It is child
class of Character class. It is used by the GamePlay class
for construction of fighters of said type.
********************************************/

#ifndef FANTASYTOURNAMENT_MEDUSA_H
#define FANTASYTOURNAMENT_MEDUSA_H

#include <stdio.h>
#include "string"
#include "Character.h"
using std::string;

class Medusa : public Character{

private:
    const string type = "Medusa";

    int total_attack, total_defense,
            total_damage, new_strength;

    const int ATTACK_DICE_AMT = 2,
            DEFENSE_DICE_AMT = 1,
            ATTACK_DICE_MAX_SIDES = 6,
            DEFENSE_DICE_MAX_SIDES = 6;

    int attackRoll();
    int defenseRoll();

public:
    Medusa(int armor, int strength, string name);
    string getType() override;
    int attack(Attack_Type &, bool) override;
    void defense(int, Attack_Type,  bool &, int &) override;
    int getTotalAttack() override;
    int getTotalDefense() override;
    int getTotalDamage() override;
    int getNewStrength() override;
    void healthRecovery() override; //virtual
};


#endif //FANTASYTOURNAMENT_MEDUSA_H
