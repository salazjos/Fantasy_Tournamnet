/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: Character_Linked_List.h - contains
prototype methods for Character_Linked_List class.
This class represents a doubly linked list used to
contain characters. It is used by the GamePlay class
to contain a team roster of fighters.
********************************************/

#ifndef FANTASYTOURNAMENT_CHARACTER_LINKED_LIST_H
#define FANTASYTOURNAMENT_CHARACTER_LINKED_LIST_H

#include <stdio.h>
#include "Character_Node.h"
#include "Character.h"

class Character_Linked_List{

private:
    int amount;
    Character_Node *first, *last;

public:
    Character_Linked_List();
    void insert_front(Character *);
    void insert_back(Character *);
    void pop_front();
    void pop_back();
    bool isEmpty();
    int getAmount();
    void traverse_forward();
    Character *getFront() {return first->getCharacter();} //return character at front of list
    ~Character_Linked_List();
};

#endif //FANTASYTOURNAMENT_CHARACTER_LINKED_LIST_H
