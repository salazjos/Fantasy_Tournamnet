/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: Character_Node.h - contains
prototype methods for Character_Node class. This
class represents a node of characters. This class
is used by the Character_Linked_List class.
********************************************/

#ifndef FANTASYTOURNAMENT_CHARACTER_NODE_H
#define FANTASYTOURNAMENT_CHARACTER_NODE_H

#include <stdio.h>
#include "Character.h"

class Character_Node{

private:
    Character_Node *next, *prev;
    Character *character;

public:
    Character_Node();
    void setPrevious(Character_Node *);
    void setNext(Character_Node *);
    void setCharacter(Character *);

    Character_Node *getPrevious();
    Character_Node *getNext();
    Character *getCharacter();
};

#endif //FANTASYTOURNAMENT_CHARACTER_NODE_H
