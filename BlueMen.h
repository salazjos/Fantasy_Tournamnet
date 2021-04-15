/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: BlueMen.h - contains
prototype methods for BlueMen class. This class
used to represent a BlueMen character. It is child
class of Character class. It is used by the GamePlay class
for construction of fighters of said type.
********************************************/

#ifndef FANTASYTOURNAMENT_BLUEMEN_H
#define FANTASYTOURNAMENT_BLUEMEN_H

#include <stdio.h>
#include "string"
#include "Character.h"
using std::string;

class BlueMen : public Character{

private:
    const string type = "Blue Men";

    int total_attack, total_defense,
            total_damage, new_strength;

    int defense_die_loss;

    const int ATTACK_DICE_AMT = 2,
            DEFENSE_DICE_AMT = 3,
            ATTACK_DICE_MAX_SIDES = 10,
            DEFENSE_DICE_MAX_SIDES = 6;

    int attackRoll();
    int defenseRoll();
    void calculateDefenseDieLoss();

public:
    BlueMen(int armor, int strength, string name);
    string getType() override;
    int attack(Attack_Type &, bool) override;
    void defense(int, Attack_Type,  bool &, int &) override;
    int getTotalAttack() override;
    int getTotalDefense() override;
    int getTotalDamage() override;
    int getNewStrength() override;
    void healthRecovery() override; //virtual
};

#endif //FANTASYTOURNAMENT_BLUEMEN_H
