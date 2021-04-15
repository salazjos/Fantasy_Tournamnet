/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
Description: Character.cpp - contains method
implementations for Character.cpp methods.
********************************************/
#include "Character.h"

#include <utility>

Character::Character(int _armor, int _strength, string _name){
    setArmor(_armor);
    setStrength_points(_strength);
    setFighterName(_name);
}

/******************************************
Function parameters: int s  = strength
Function Return type: void
Function Description: Function assigns strength
to class variables strength_points
******************************************/
void Character::setStrength_points(int s){
    strength_points = s;
}

/******************************************
Function parameters: int armorAmt
Function Return type: void
Function Description: Function assigns armorAmt
to class variable armor
******************************************/
void Character::setArmor(int armorAmt) {
    armor = armorAmt;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function returns class
variable armor.
******************************************/
int Character::getArmor(){
    return armor;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function returns class
variable strength_points.
******************************************/
int Character::getStrength_points(){
    return strength_points;
}

/******************************************
Function parameters: string n - fighter name
Function Return type: void
Function Description: Function assigns n to
class variable fighterName
******************************************/
void Character::setFighterName(string n){
    fighterName = n;
}

/******************************************
Function parameters: none
Function Return type: string
Function Description: Function returns class
variable fighterName.
******************************************/
string Character::getFighterName(){
    return fighterName;
}

/* Overriden in child classes */
int Character::attack(Attack_Type &a, bool c){
    return 0;
}

/* Overriden in child classes */
void Character::defense(int a, Attack_Type,  bool &charm, int &c){
    //blank
}

/* Overriden in child classes */
string Character::getType(){
    return "";
}

/* Overriden in child classes */
int Character::getTotalAttack(){
    return 0;
}

/* Overriden in child classes */
int Character::getTotalDefense(){
    return 0;
}

/* Overriden in child classes */
int Character::getTotalDamage(){
    return 0;
}

/* Overriden in child classes */
int Character::getNewStrength(){
    return 0;
}

/* Overriden in child classes */
void Character::healthRecovery(){
    //blank
}

