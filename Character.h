/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: Character.h - contains
prototype methods for Character class. Class is the
parent class for all child classes. This class
represents all the base characteristics of a character.
********************************************/

#ifndef FANTASYTOURNAMENT_CHARACTER_H
#define FANTASYTOURNAMENT_CHARACTER_H

#include <stdio.h>
#include <string>
using std::string;

class Character{

private:
    int armor, strength_points;
    string fighterName;

protected:
    //none

public:
    enum Attack_Type{NORMAL_ATTACK, GLARE};
    enum Defense_Type{NORMAL_DEFENSE, CHARM};

    Character(int armor, int strength, string name);
    virtual int attack(Attack_Type &, bool);
    virtual void defense(int attack, Attack_Type a, bool &, int &d_strength);
    virtual string getType();
    virtual int getTotalAttack();
    virtual int getTotalDefense();
    virtual int getTotalDamage();
    virtual int getNewStrength();
    void setStrength_points(int pointsAmt);
    int getArmor();
    int getStrength_points();
    void setFighterName(string n);
    void setArmor(int armorAmt);
    virtual void healthRecovery();
    string getFighterName();
};

#endif //FANTASYTOURNAMENT_CHARACTER_H
