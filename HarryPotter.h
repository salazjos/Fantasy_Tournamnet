/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: HarryPotter.h - contains
prototype methods for HarryPotter class. This class
used to represent a HarryPotter character. It is child
class of Character class. It is used by the GamePlay class
for construction fighters of said type.
********************************************/

#ifndef FANTASYTOURNAMENT_HARRYPOTTER_H
#define FANTASYTOURNAMENT_HARRYPOTTER_H

#include <stdio.h>
#include "string"
#include "Character.h"
using std::string;

class HarryPotter : public Character{

private:
    const string type = "Harry Potter";

    int total_attack, total_defense,
            total_damage, new_strength;

    int revive_amt;

    const int ATTACK_DICE_AMT = 2,
            DEFENSE_DICE_AMT = 2,
            ATTACK_DICE_MAX_SIDES = 6,
            DEFENSE_DICE_MAX_SIDES = 6;

    int attackRoll();
    int defenseRoll();
    void reactivate();
public:
    HarryPotter(int armor, int strength, string name);
    string getType() override;
    int attack(Attack_Type &, bool) override;
    void defense(int, Attack_Type,  bool &, int &) override;
    int getTotalAttack() override;
    int getTotalDefense() override;
    int getTotalDamage() override;
    int getNewStrength() override;
    void healthRecovery() override; //virtual
};

#endif //FANTASYTOURNAMENT_HARRYPOTTER_H
