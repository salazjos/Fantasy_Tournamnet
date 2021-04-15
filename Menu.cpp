/********************************************
Program name: Project 4 - Fantasy Combat Tournament
Author: Joseph Salazar
salazjos@oregonstate.edu
Description: Menu.cpp - contains method
implementations for Menu class.
********************************************/

#include "Menu.h"
#include "InputValidation.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/************************
Class constructor
***********************/
Menu::Menu(){
    initializeStringstreamObjects();
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function initializes class
stringstream objects.
******************************************/
void Menu::initializeStringstreamObjects(){

    ss_characterSelection << "      --Character Selection -- " << endl;
    ss_characterSelection << "Press 1 for Vampire. " << endl;
    ss_characterSelection << "Press 2 for Barbarian. " << endl;
    ss_characterSelection << "Press 3 for Blue Men. " << endl;
    ss_characterSelection << "Press 4 for Medusa. " << endl;
    ss_characterSelection << "Press 5 for Harry Potter. " << endl;

    ss_invalidInput << "Invalid input." << endl;
    ss_invalidInput << "Please enter whole numbers. Ex: 1,2,3, etc.\n" << endl;

    ss_invalidSelection << "Invalid Menu Selection." << endl;
    ss_invalidSelection << "Please select appropiate number from menu choice.\n" << endl;

    ss_endMenu << endl;
    ss_endMenu << "Press 1 to play again." << endl;
    ss_endMenu << "press 2 ro exit game. " << endl;

    ss_startMenu << "Press 1 to play." << endl;
    ss_startMenu << "Press 2 to exit." << endl;

    ss_displayLosingTeam << "\nWould you like to display the losing fighters?" << endl;
    ss_displayLosingTeam << "Press 1 for yes" << endl;
    ss_displayLosingTeam << "Press 2 for no." << endl;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function displays character
selection menu and returns selection. Value
between 1 and 5 is returned.
******************************************/
int Menu::showAndGetCharacterSelect(){

    string character_choice;
    int invalidStart_index_error = 0;
    int selection = 0;
    bool isValidInteger = false;

    do{

        try{

            cout << ss_characterSelection.str();
            cin >> character_choice;
            cin.ignore();

            invalidStart_index_error = testForInvalidParameterInputs(character_choice,1, 5);

            while(invalidStart_index_error != 3){ //input was not an integer
                if(invalidStart_index_error == 1){ // not an integer
                    cout << ss_invalidInput.str();
                    cout << ss_characterSelection.str();
                    cin >> character_choice;
                    cin.ignore();
                }
                else if(invalidStart_index_error == 2){ //invalid selection
                    cout << ss_invalidSelection.str();
                    cout << ss_characterSelection.str();
                    cin >> character_choice;
                    cin.ignore();
                }
                //test for valid input
                invalidStart_index_error = testForInvalidParameterInputs(character_choice,1, 5);
            }

            selection = stoi(character_choice);
            isValidInteger = true;

        }
        catch(std::out_of_range &outrange){ //exception thrown from stoi())
            cout << "Inputted number was out of range for integer." << endl;
            isValidInteger = false;
        }
        catch(std::invalid_argument &ia){ //exception thrown from stoi()
            cout << "Number could not be converted to integer. " << endl;
            isValidInteger = false;
        }

    }while(!isValidInteger);

    return selection;

}


/******************************************
Function parameters: string for input
                     int for minimum value
                     int for maximum value
Function Return type: int
Function Description: Function determins if string
input is an integer, 1 is returned if not integer.
If string choice is integer, input is determined if
within range. 2 is returned if not within range. 3 is
returned by defualt if input is valid on both tests.
******************************************/
int Menu::testForInvalidParameterInputs(const string &input, int min, int max){
    int number = 0;
    //1: input not an integer
    //2: input not within range
    //3: good
    int error_Code = 3; //by defualt it is good

    if(!isInputInteger(input)){
        error_Code = 1;
    }
    else{ //is an integer
        number = stoi(input);
        if(!isNumberInRange(number,min,max)){
            error_Code = 2;
        }
    }
    return error_Code;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function displays end
menu selection and returns selection. 1 to
continue, 2 to exit.
******************************************/
int Menu::getEndMenuSelect(){
    string exit_choice;
    int invalidStart_index_error = 0;
    int selection = 0;
    bool isValidInteger = false;

    do{
        try{
            cout << ss_endMenu.str();
            cin >> exit_choice;
            cin.ignore();

            invalidStart_index_error = testForInvalidParameterInputs(exit_choice,1, 2);

            while(invalidStart_index_error != 3){ //input was not an integer
                if(invalidStart_index_error == 1){ // not an integer
                    cout << ss_invalidInput.str();
                    cout << ss_endMenu.str();
                    cin >> exit_choice;
                    cin.ignore();
                }
                else if(invalidStart_index_error == 2){ //invalid selection
                    cout << ss_invalidSelection.str();
                    cout << ss_endMenu.str();
                    cin >> exit_choice;
                    cin.ignore();
                }
                //test for valid input
                invalidStart_index_error = testForInvalidParameterInputs(exit_choice,1, 2);
            }

            selection = stoi(exit_choice);
            isValidInteger = true;

        }catch(std::out_of_range &outrange){ //exception thrown from stoi())
            cout << "Inputted number was out of range for integer." << endl;
            isValidInteger = false;
        }
        catch(std::invalid_argument &ia){ //exception thrown from stoi()
            cout << "Number could not be converted to integer. " << endl;
            isValidInteger = false;
        }

    }while(!isValidInteger);

    return selection;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function displays start
menu selection and returns selection. 1 to
start game, 2 to exit.
******************************************/

int Menu::getStartMenuSelect(){

    string start_choice;
    int invalidStart_index_error = 0;
    int selection = 0;
    bool isValidInteger = false;

    do{
        try{
            cout << ss_startMenu.str();
            cin >> start_choice;
            cin.ignore();

            invalidStart_index_error = testForInvalidParameterInputs(start_choice,1, 2);

            while(invalidStart_index_error != 3){ //input was not an integer
                if(invalidStart_index_error == 1){ // not an integer
                    cout << ss_invalidInput.str();
                    cout << ss_startMenu.str();
                    cin >> start_choice;
                    cin.ignore();
                }
                else if(invalidStart_index_error == 2){ //invalid selection
                    cout << ss_invalidSelection.str();
                    cout << ss_startMenu.str();
                    cin >> start_choice;
                    cin.ignore();
                }
                //test for valid input
                invalidStart_index_error = testForInvalidParameterInputs(start_choice,1, 2);
            }

            selection = stoi(start_choice);
            isValidInteger = true;

        }catch(std::out_of_range &outrange){ //exception thrown from stoi())
            cout << "Inputted number was out of range for integer." << endl;
            isValidInteger = false;
        }
        catch(std::invalid_argument &ia){ //exception thrown from stoi()
            cout << "Number could not be converted to integer. " << endl;
            isValidInteger = false;
        }

    }while(!isValidInteger);

    return selection;


}
/******************************************
Function parameters: none
Function Return type: void
Function Description: Function deisplays message
to choose an additional character.
******************************************/
void Menu::selectAnotherCharacter(){
    cout << "\nChoose one more character." << endl;
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function displays message that
characters are currently fighting.
******************************************/
void Menu::fightingMessage(){
    cout <<"\n\n";
    cout << "Characters are fighting...............\n";
}

/******************************************
Function parameters: none
Function Return type: void
Function Description: Function displays message
of exiting game.
******************************************/
void Menu::exitGameMessage(){
    cout << "\n";
    cout << "--- Exiting game ---";
}


/******************************************
Function parameters:  character *c - which character has died
Function Return type: void
Function Description: Function displays message stating
which character has died.
******************************************/
void Menu::displayCharacterDeath(Character *c){
    cout <<"\n";
    cout << c->getType() << " has died !!!" << endl;
}

/******************************************
Function parameters:  Character *attacker - attacking character
                      Character *dfender - defending character
                      int old_strength - starting strength.
Function Return type: void
Function Description: Function displays stringstream object containing
end of round info.
******************************************/
void Menu::endOfAttackInfo(Character *attacker, Character *defender, int old_strength){

    ss_endOfRoundInfo.str(""); //clear it

    ss_endOfRoundInfo << "---------------- End of turn info ---------------" << endl;
    ss_endOfRoundInfo << "Attacker Type:             " << attacker->getType() << endl;
    ss_endOfRoundInfo << "Defender Type:             " << defender->getType() << endl;
    ss_endOfRoundInfo << "Defender Armor:            " << defender->getArmor() << endl;
    ss_endOfRoundInfo << "Defender Strength Point:   " << old_strength << endl;
    ss_endOfRoundInfo << "Attacker attack dice roll: " << attacker->getTotalAttack() << endl;
    ss_endOfRoundInfo << "Defender defend dice roll: " << defender->getTotalDefense() << endl;
    ss_endOfRoundInfo << "Damage inflicted:          " << defender->getTotalDamage() << endl;
    ss_endOfRoundInfo << "Defender New Strength:     " << defender->getNewStrength() << endl;

    cout << ss_endOfRoundInfo.str();

}

/******************************************
Function parameters: none
Function Return type: string
Function Description: Function prompts input
for character name. chracter name is returned.
******************************************/
string Menu::getCharacterName(){
    string character_name;
    cout << "Enter a name for this character: " << endl;
    getline(cin, character_name);
    return character_name;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function prompts for
number of fighters for both teams. Only numbers
1 or greater are returned.
******************************************/
int Menu::getFighterAmount(){

    bool isValidInteger = false, isIntValid = false;
    string number_str;
    int number = 0;

    cout << "Enter integer for amount of fighters. Must be 1 or greater. " << endl;
    cout << "Please enter an integer: " << endl;

    do{

        try{

            cin >> number_str;
            cin.ignore();

            isIntValid = isInputInteger(number_str);
            while(!isIntValid){
                cout << "Number invalid. Re-enter number: " << endl;
                cin >> number_str;
                cin.ignore();
                isIntValid = isInputInteger(number_str);
            }
            number = stoi(number_str);
            isValidInteger = true;
        }
        catch(std::out_of_range &outrange){ //exception thrown from stoi())
            cout << "Inputted number was out of range for integer." << endl;
            cout << "Re - enter number: " << endl;
            isValidInteger = false;
        }
        catch(std::invalid_argument &ia){ //exception thrown from stoi())
            cout << "Number could not be converted to integer. " << endl;
            cout << "Re - enter number: " << endl;
            isValidInteger = false;
        }

    }while(!isValidInteger);

    return number;
}

/******************************************
Function parameters: none
Function Return type: int
Function Description: Function displays menu
for selection to display losing fighters.
1 for yes, 2 for no, is returned.
******************************************/
int Menu::getDisplayLosingTeamSelect(){

    string display_choice;
    int invalidStart_index_error = 0;
    int selection = 0;
    bool isValidInteger = false;

    do{
        try{
            cout << ss_displayLosingTeam.str();
            cin >> display_choice;
            cin.ignore();

            invalidStart_index_error = testForInvalidParameterInputs(display_choice,1, 2);

            while(invalidStart_index_error != 3){ //input was not an integer
                if(invalidStart_index_error == 1){ // not an integer
                    cout << ss_invalidInput.str();
                    cout << ss_displayLosingTeam.str();
                    cin >> display_choice;
                    cin.ignore();
                }
                else if(invalidStart_index_error == 2){ //invalid selection
                    cout << ss_invalidSelection.str();
                    cout << ss_displayLosingTeam.str();
                    cin >> display_choice;
                    cin.ignore();
                }
                //test for valid input
                invalidStart_index_error = testForInvalidParameterInputs(display_choice,1, 2);
            }

            selection = stoi(display_choice);
            isValidInteger = true;

        }catch(std::out_of_range &outrange){ //exception thrown from stoi())
            cout << "Inputted number was out of range for integer." << endl;
            isValidInteger = false;
        }
        catch(std::invalid_argument &ia){ //exception thrown from stoi()
            cout << "Number could not be converted to integer. " << endl;
            isValidInteger = false;
        }

    }while(!isValidInteger);

    return selection;
}