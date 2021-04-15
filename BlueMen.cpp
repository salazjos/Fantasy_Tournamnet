/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: BlueMen.cpp - contains method
implementations for BlueMen class.
********************************************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cmath>
#include "BlueMen.h"
#include "string"
using std::string;
using std::cout;

/*****************************************
class constructor.
*****************************************/
BlueMen::BlueMen(int _armor, int _strength, string _name) : Character(_armor, _strength, _name){
    srand(time(nullptr));
    defense_die_loss = 0;
}

/******************************************
Function parameters: none
Function Return type: string
Function Description: Function returns class
variable type.
******************************************/
string BlueMen::getType(){
    return type;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function returns class
variable total_attack.
******************************************/
int BlueMen::getTotalAttack(){
    return total_attack;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function returns class
variable total_defense.
******************************************/
int BlueMen::getTotalDefense(){
    return total_defense;
}

/******************************************
Functi/on parameters: none
Function Return type: int
Function Description: Function returns class
variable total_damage.
******************************************/
int BlueMen::getTotalDamage(){
    return total_damage;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function returns class
variable new_strength.
******************************************/
int BlueMen::getNewStrength(){
    return new_strength;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function returns summed
up dice roll based on class amount of dice and
sides for attacking. Returned value is potential damage
inflicted on opponent.
******************************************/
int BlueMen::attackRoll(){

    total_attack = 0;
    int random_num = 0;

    for(int i = 0; i < ATTACK_DICE_AMT; i++){
        random_num = rand() % ATTACK_DICE_MAX_SIDES + 1;
        total_attack += random_num;
    }

    return total_attack;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function returns summed
up dice roll based on class amount of dice and
sides for defending. Returned value is defense
value against attack.
******************************************/
int BlueMen::defenseRoll(){

    total_defense = 0;
    int random_num = 0;

    for(int i = 0; i < DEFENSE_DICE_AMT - defense_die_loss; i++){
        random_num = rand() % DEFENSE_DICE_MAX_SIDES + 1;
        total_defense += random_num;
    }

    return total_defense;
}

/******************************************
Function parameters: Attack &a_type, Defense d_type
Function Return type: int
Function Description: Function returns attack value
from attackRoll method. If defense type is Charm, then
50% chance of attacking. If not attack, 0 is returned.
******************************************/
int BlueMen::attack(Attack_Type &a_type, bool isCharm){
    if(isCharm){
        int random_num = (1 + rand() % 2)  -  1;
        if(random_num == 1){ //true, attact is 0, doesnt attack
            cout <<"\n";
            cout << "Vampire charmed into not attacking!!\n";
            total_attack = 0;
            return 0;
        }
    }

    a_type = NORMAL_ATTACK;
    int roll_amount = attackRoll();
    return roll_amount;
}

/******************************************
Function parameters:  int attackAmt, Attack_Type a_type,
                      Defense_Type &d_type, bool &charmOn,
                      int &d_strength.
Function Return type: void
Function Description: Function defendes against attack. Total
damage inflicted is calculated.
******************************************/
void BlueMen::defense(int attackAmt, Attack_Type a_type,
                      bool &chamrOn, int &d_stength){

    /* If Glare was used by Medusa then instant death. */
    if(a_type == GLARE){
        setStrength_points(0);
        cout << "Medusa used Glare. Instant death!!!\n";
    }
    else{
        /* Calculate damage and assign to class variables.*/
        d_stength = getStrength_points();
        int strength = getStrength_points();
        total_defense = defenseRoll();
        total_damage = attackAmt - total_defense - getArmor();

        if(total_damage < 0){
            total_damage = 0;
        }

        new_strength  = strength - total_damage;

        calculateDefenseDieLoss(); //calculate and assign potential loss of dice.
        setStrength_points(new_strength);
    }
}

/******************************************
Function parameters:  none
Function Return type: void
Function Description: Function calculates loss
of defense die.
******************************************/
void BlueMen::calculateDefenseDieLoss(){

    int loss_die_amnt = (int) (total_damage / 4);
    if(loss_die_amnt > 0){
        cout << "Blue Men just lost " << loss_die_amnt << " defense die.\n";
    }
    defense_die_loss = loss_die_amnt;
}

/******************************************
Function parameters:  none
Function Return type: void
Function Description: Based on random number,
function recovers either 10,20,30, or 40 percent
of the lost strenght points in a battle.
******************************************/
void BlueMen::healthRecovery(){

    int percentageArray[] = {10,20,30,40};
    int random_number = (1 + rand() % 5) - 1;
    float recover_percent = percentageArray[random_number] / 100;
    int lost_strength = 12 - getStrength_points();
    float temp_recovery = lost_strength * recover_percent;
    int recoveryAmount = (int)ceil(temp_recovery);
    if(recoveryAmount + 12 >= 12){
        recoveryAmount -= 1;
    }
    setStrength_points(getStrength_points() + recoveryAmount);
}
