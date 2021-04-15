/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: Barbarian.hpp - contains
prototype methods for Barbarian class. This class
used to represent a Barbarian character. It is child
class of Character class. It is used by the GamePlay class
for construction of fighters of said type.
********************************************/

#ifndef FANTASYTOURNAMENT_BARBARIAN_H
#define FANTASYTOURNAMENT_BARBARIAN_H

#include <stdio.h>
#include <string>
#include "Character.h"
using std::string;

class Barbarian : public Character{
private:
    const string type = "Barbarian";

    int total_attack, total_defense,
            total_damage, new_strength;

    const int ATTACK_DICE_AMT = 2,
            DEFENSE_DICE_AMT = 2,
            ATTACK_DICE_MAX_SIDES = 6,
            DEFENSE_DICE_MAX_SIDES = 6;

    int attackRoll();
    int defenseRoll();

public:
    Barbarian(int armor, int strength, string name);
    string getType() override;
    int attack(Attack_Type &, bool) override;
    void defense(int, Attack_Type, bool &, int &) override;
    int getTotalAttack() override;
    int getTotalDefense() override;
    int getTotalDamage() override;
    int getNewStrength() override;
    void healthRecovery() override; //virtual
};
#endif //FANTASYTOURNAMENT_BARBARIAN_H
