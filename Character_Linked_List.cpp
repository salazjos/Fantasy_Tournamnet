/*****************************************
Program*** name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: Character_Linked_List.hpp - contains
method implementations for Character_Linked_List class.
********************************************/

#include "Character_Linked_List.h"
#include "Character_Node.h"
#include "Character.h"
#include <iostream>
using std::cout;
using std::endl;

/******
class constructor
*****/
Character_Linked_List::Character_Linked_List(){

    amount = 0;
    first = nullptr;
    last = nullptr;

}
/******************************************
Function parameters: Character *c - value to be added to list
Function Return type: void
Function Description: Function adds *c to
the front of the list.
******************************************/
void Character_Linked_List::insert_front(Character *c){

    Character_Node *node = new Character_Node();
    node->setCharacter(c);

    if(isEmpty()){
        first = last = node;
    }
    else{
        node->setNext(first);
        first->setPrevious(node);
        first = node;
    }
    amount++;
}

/******************************************
Function parameters: Character *c - value to be added to list
Function Return type: void
Function Description: Function adds *c to
the back of the list.
******************************************/
void Character_Linked_List::insert_back(Character *c){

    Character_Node *c_node = new  Character_Node();
    c_node->setCharacter(c);

    if(isEmpty()){
        first = last = c_node;
    }
    else{
        last->setNext(c_node);
        c_node->setPrevious(last);
        last = c_node;
    }
    amount++;
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function removes node
from front of list.
******************************************/
void Character_Linked_List::pop_front() {

    if (first != nullptr) {

        Character_Node *node_temp = first;
        first = first->getNext();

        if (first == nullptr) {
            last = nullptr;
        } else {
            first->setPrevious(nullptr);
        }

        delete node_temp;
        amount--;
    }
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function removes node
from back of list.
******************************************/
void Character_Linked_List::pop_back(){

    if(last != nullptr){

        Character_Node *node_temp = last;
        last = last->getPrevious();

        if(last == nullptr){
            first = nullptr;
        }
        else{
            last->setNext(nullptr);
        }

        delete node_temp;
        amount--;

    }
}

/******************************************
Function parameters: none
Function Return type: bool
Function Description: Function determines if
list is empty
******************************************/
bool Character_Linked_List::isEmpty(){
    return amount <= 0;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function returns the
amount of contents in the list.
******************************************/
int Character_Linked_List::getAmount(){
    return amount;
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function prints list
from front to back
******************************************/
void Character_Linked_List::traverse_forward(){

    Character_Node *temp = first;
    for(int i = 0; i < getAmount(); i++){
        cout << temp->getCharacter()->getType() << " - " <<
                temp->getCharacter()->getFighterName() << endl;
        temp = temp->getNext();
    }
    //delete temp;
}

/******************************************
Class destructor - removes everything from list.
******************************************/
Character_Linked_List::~Character_Linked_List(){
    while(!isEmpty()){
        pop_back();
    }
}
