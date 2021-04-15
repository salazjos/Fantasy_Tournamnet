/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: Character_Node.cpp - contains
method implementations for Character_Node class.
********************************************/

#include "Character_Node.h"
#include "Character.h"

Character_Node::Character_Node(){
    next = nullptr;
    prev = nullptr;
}

/******************************************
Function parameters: Character_Node *p - value to be added to list
Function Return type: void
Function Description: Function assigns *p to
prev pointer
******************************************/
void Character_Node::setPrevious(Character_Node *p){
    prev = p;
}

/******************************************
Function parameters: Character_Node *n - value to be added to list
Function Return type: void
Function Description: Function assigns *n to
next pointer
******************************************/
void Character_Node::setNext(Character_Node *n){
    next = n;
}

/******************************************
Function parameters: Character *c - value to be assigned
Function Return type: void
Function Description: Function assigns *c to
character pointer
******************************************/
void Character_Node::setCharacter(Character *c){
    character = c;
}

/******************************************
Function parameters:  none
Function Return type: Character_Node
Function Description: Function returns next node
******************************************/
Character_Node *Character_Node::getNext(){
    return next;
}

/******************************************
Function parameters:  none
Function Return type: Character_Node
Function Description: Function returns prev node
******************************************/
Character_Node *Character_Node::getPrevious(){
    return prev;
}

/******************************************
Function parameters:  none
Function Return type: Character
Function Description: Function returns character pointer
******************************************/
Character *Character_Node::getCharacter(){
    return character;
}
