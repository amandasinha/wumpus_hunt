/******************************************************
** Program: wumpus.cpp
** Author: Amanda Sinha
** Date: 05/25/2021
** Description: Allows the user to play wumpus hunt
** Input: The user should input command line arguments (grid size and true/false)
**      then use WASD and 1 and 2 in order to control their "player"
** Output: The game should print the game board (based on whether or not the player
**      is in debug mode) as well as text information regarding the player's surroundings
******************************************************/

#include <iostream>
#include <vector>
#include "bats.h"
#include "event.h"
#include "game.h"
#include "gold.h"
#include "pit.h"
#include "room.h"
#include "wumpus.h"
#include <stdlib.h> 
#include <string>

using namespace::std;

int main(int argc, char *argv[]) {
    bool ending = false;
    bool debug = true;
    int gridsize = 0;
    
    //initializing command line arguments
    if (argc > 2) {
        if (*argv[2] == 'f') {   debug = false;   }
        else {   debug = true;   }
        gridsize = atoi(argv[1]);
    }

    //handling debug (just once)
    if (argc < 2) {
        string de = "";
        cout << "Debug mode on (true or false)? ";
        cin >> de;
        if (de == "false") {   debug = false;   }
        else {   debug = true;   }
        cin.clear();
        cin.ignore(10000,'\n');
    }

    //more handling (for grid size)
    while (gridsize <= 3 || gridsize > 10) {
        cout << "How large of caves? ";
        cin >> gridsize;
        cin.clear();
        cin.ignore(10000,'\n');
    }

    //make the game
    Game thing(debug, gridsize);
    
    //run the game
    while (!ending){
        thing.turn();
        ending = thing.endgame();
    }

    return 0;

}