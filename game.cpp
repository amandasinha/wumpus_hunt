#include "game.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <exception>

using namespace::std;

/******************************************************
** Function: Game constructor
** Description: Makes a basic Game object.
** Parameters: N/A
** Pre-conditions: N/A
** Post-conditions: A Game object is created.
******************************************************/
Game::Game(bool debugging, int numrooms) {
    srand(time(NULL));
    gold_get = false;
    wump_kill = false;
    this->numrooms = numrooms;
    escx = rand() % numrooms;
    escy = rand() % numrooms;
    xpos = escx;
    ypos = escy;
    set_grid(numrooms);
    arrows = 3;
    this->debugging = debugging;
    setup();
}

/******************************************************
** Function: Game copy constructor
** Description: Makes an Game object based on existing_game.
** Parameters: const Game& existing_game
** Pre-conditions: existing_game exists
** Post-conditions: Game is created based on existing_game
******************************************************/
Game::Game(const Game& existing_game) {
    this->gold_get = existing_game.gold_get;
    this->wump_kill = existing_game.wump_kill;
    this->numrooms = existing_game.numrooms;
    this->grid = existing_game.grid;
    this->xpos = existing_game.xpos;
    this->ypos = existing_game.ypos;
    this->escx = existing_game.escx;
    this->escx = existing_game.escy;
    this->debugging = existing_game.debugging;
    this->arrows = existing_game.arrows;
}

/******************************************************
** Function: Game assignment operator overload
** Description: Assigns attributes of existing_game to this Game
** Parameters: const Game& existing_game
** Pre-conditions: existing_game exists
** Post-conditions: Game = existing_game
******************************************************/
Game& Game::operator= (const Game& existing_game) {
    if(this != &existing_game) {
        this->gold_get = existing_game.gold_get;
        this->wump_kill = existing_game.wump_kill;
        this->numrooms = existing_game.numrooms;
        this->grid = existing_game.grid;
        this->xpos = existing_game.xpos;
        this->ypos = existing_game.ypos;
        this->escx = existing_game.escx;
        this->escx = existing_game.escy;
        this->debugging = existing_game.debugging;
        this->arrows = existing_game.arrows;
    }
    return *this;
}

/******************************************************
** Function: Game destructor
** Description: Destroys this Game
** Parameters: N/A
** Pre-conditions: Game exists
** Post-conditions: Game is destroyed
******************************************************/
Game::~Game() {

}

/******************************************************
** Function: set_gold_get
** Description: Sets gold_get to parameter gold_get
** Parameters: bool gold_get
** Pre-conditions: Valid parameter
** Post-conditions: gold_get is equal to parameter gold_get
******************************************************/
void Game::set_gold_get(bool gold_get) {
    this->gold_get = gold_get;
}

/******************************************************
** Function: set_wump_kill
** Description: Sets wump_kill to parameter wump_kill
** Parameters: bool wump_kill
** Pre-conditions: Valid parameter
** Post-conditions: wump_kill is equal to parameter wump_kill
******************************************************/
void Game::set_wump_kill(bool wump_kill) {
    this->wump_kill = wump_kill;
}
    
/******************************************************
** Function: set_grid
** Description: Makes a 2D vector based on rooms
** Parameters: int rooms
** Pre-conditions: Valid parameter
** Post-conditions: 2D array with rooms 'rows' and rooms 'columns' is created
******************************************************/
void Game::set_grid(int rooms) {
    grid.resize(rooms);
    for (int i = 0; i < rooms; i++) {
        grid[i].resize(rooms);
        for (int j = 0; j < rooms; j++) {
            Room thing;
            thing.set_event("", false);
            grid[i][j] = thing;
        }
    }
}

/******************************************************
** Function: setup_event
** Description: Assigns an event based on string randomly throughout the caves
** Parameters: string event
** Pre-conditions: grid, numroom exists
** Post-conditions: A room in grid has an event based on string event
******************************************************/
void Game::setup_event(string event) {
    int x = rand() % numrooms;
    int y = rand() % numrooms;
    while (grid[x][y].get_eventexists() || x == xpos || y == ypos) {
        x = rand() % numrooms;
        y = rand() % numrooms;
    }
    grid[x][y].set_event(event, true);
}

/******************************************************
** Function: setup
** Description: Assigns events randomly throughout the caves
** Parameters: N/A
** Pre-conditions: grid exists
** Post-conditions: The rooms in the 2D vector array have 1 Wumpus, 1 Gold, 2 Bats, and
**      2 Pit events in the entire grid.
******************************************************/
void Game::setup() {
    setup_event("wumpus");
    
    setup_event("gold");

    for (int i = 0; i < 2; i++) {
        setup_event("bats");
    }

    for (int i = 0; i < 2; i++) {
        setup_event("pit");
    }
}

/******************************************************
** Function: print_rooms
** Description: Prints the rooms of the caves
** Parameters: N/A
** Pre-conditions: grid exists
** Post-conditions: grid is printed with the player * displayed
******************************************************/
void Game::print_rooms() {
    for (int i = 0; i < numrooms; i++) {
        //horizontal dividers
        for (int c = 0; c < numrooms; c++) {
            cout << "+-----";
        }
        cout << "+" << endl;

        //vertical dividers
        for (int j = 0; j < 3; j++) {
            for (int r = 0; r < numrooms; r++) {
                if (r != xpos || i != ypos || j != 1) {
                    cout << "|     ";
                }
                else {
                    cout << "|  *  ";
                }
            }
            cout << "|" << endl;
        }
    }

    for (int c = 0; c < numrooms; c++) {
        cout << "+-----";
    }
    cout << "+" << endl;
}

/******************************************************
** Function: print_rooms_debug
** Description: Prints the rooms of the caves with all event info displayed
** Parameters: N/A
** Pre-conditions: grid exists
** Post-conditions: grid is printed with the player * AND all other events displayed
******************************************************/
void Game::print_rooms_debug() {
    for (int i = 0; i < numrooms; i++) {
        //horizontal dividers
        for (int c = 0; c < numrooms; c++) {
            cout << "+-----";
        }
        cout << "+" << endl;

        //vertical dividers
        for (int j = 0; j < 4; j++) {
            for (int r = 0; r < numrooms; r++) {
                //event printing
                if (i == ypos && r == xpos && j == 1) {
                    cout << "|  *  ";
                }
                else if (j == 2) {
                    print_event(r, i);
                }
                else {
                    cout << "|     ";
                }
            }
            cout << "|" << endl;
        }
    }

    for (int c = 0; c < numrooms; c++) {
        cout << "+-----";
    }
    cout << "+" << endl;
}

/******************************************************
** Function: print_event
** Description: Specifically prints event markers for the debug room printing
** Parameters: int x, int y
** Pre-conditions: grid, escx, escy exist, valid parameters
** Post-conditions: A part corresponding to an event is printed.
******************************************************/
void Game::print_event(int x, int y) {
    if (grid[x][y].get_string_event() == "wumpus") {
        cout << "|  W  ";
    }
    else if (grid[x][y].get_string_event() == "gold") {
        cout << "|  G  ";
    }
    else if (grid[x][y].get_string_event() == "bats") {
        cout << "|  B  ";
    }
    else if (grid[x][y].get_string_event() == "pit") {
        cout << "|  P  ";
    }
    else if (x == escx && y == escy) {
        cout << "|  E  ";
    }
    else {
        cout << "|     ";
    }
}

/******************************************************
** Function: valid_direction
** Description: Checks if there is an empty space in some direction
** Parameters: char dir
** Pre-conditions: xpos and ypos have been initialized, valid parameters
** Post-conditions: returns a bool so long as both xpos and ypos remain in-bounds
**      based on dir(ection)
******************************************************/
bool Game::valid_direction(char dir) {
    if (dir == 'w' || dir == 'W') {
        if (ypos != 0) {
            return true;
        }
    }
    else if (dir == 's' || dir == 'S') {
        if (ypos != numrooms-1) {
            return true;
        }
    }
    else if (dir == 'a' || dir == 'A') {
        if (xpos != 0) {
            return true;
        }
    }
    else if (dir == 'd' || dir == 'D') {
        if (xpos != numrooms-1) {
            return true;
        }
    }
    else {
        return false;
    }
}

/******************************************************
** Function: do_precept
** Description: Runs the precept of a room
** Parameters: int x, int y
** Pre-conditions: x and y correspond to a Room in grid
** Post-conditions: runs the percept() function of the corresponding Event type
******************************************************/
void Game::do_precept(int x, int y) {
    if (grid[x][y].get_string_event() == "bats") {
        Bats bat;
        bat.percept();
    }
    else if (grid[x][y].get_string_event() == "gold") {
        Gold au;
        au.percept();
    }
    else if (grid[x][y].get_string_event() == "pit") {
        Pit p;
        p.percept();
    }
    else if (grid[x][y].get_string_event() == "wumpus") {
        Wumpus wump;
        wump.percept();
    }
}

/******************************************************
** Function: fire_precepts
** Description: Scans rooms surrounding the player for events
** Parameters: N/A
** Pre-conditions: grid, xpos, and ypos have been initialized
** Post-conditions: Calls do_precept() if there is an event with a precept in the Room
******************************************************/
void Game::fire_precepts() {
    if (ypos - 1 >= 0) {
        if ((grid[xpos][ypos-1]).get_eventexists()) {
            do_precept(xpos, ypos-1);
        }
    }
    if (xpos + 1 < numrooms) {
        if ((grid[xpos+1][ypos]).get_eventexists()) {
            do_precept(xpos+1, ypos);
        }
    }
    if (ypos + 1 < numrooms) {
        if ((grid[xpos][ypos+1]).get_eventexists()) {
            do_precept(xpos, ypos+1);
        }
    }
    if (xpos - 1 >= 0) {
        if ((grid[xpos-1][ypos]).get_eventexists()) {
            do_precept(xpos-1, ypos);
        }
    }
    cout << "-----------------------------------" << endl;
}

/******************************************************
** Function: turn
** Description: Goes through one turn of play
** Parameters: N/A
** Pre-conditions: grid has been initialized
** Post-conditions: Asks the user to choose to do something (move/fire)
**      based on printed info
******************************************************/
void Game::turn() {
    int choice;
    //print pre info
    if (debugging == true) { print_rooms_debug(); }
    else { print_rooms(); }
    fire_precepts();
    if (gold_get) { cout << "GOLD: got :)     "; }
    else { cout << "GOLD: no :(     "; }
    if (!wump_kill) { cout << "WUMPUS: alive     "; }
    else { cout << "WUMPUS: dead     "; }
    cout << "ARROWS LEFT: " << arrows << endl;

    //user choice
    do {
        cout << "What do you want to do (1 to fire an arrow, 2 to move)? ";
        cin >> choice;
    } while (choice != 1 && choice != 2);

    if (choice == 1) {
        if (arrows == 0) {
            cout << "Not enough arrows! You gotta move!" << endl;
        }
        else {
            fire();
        }
    }
    else if (choice == 2) {
        move();
    }
}

/******************************************************
** Function: fire
** Description: Fires an arrow up to 3 spaces in some direction
** Parameters: N/A
** Pre-conditions: grid has been initialized
** Post-conditions: The Wumpus is either killed or moved
******************************************************/
void Game::fire() {
    char dir = 'l';
    do {
        cout << "What direction? ";
        cin >> dir;
    } while (!valid_direction(dir));
    arrows--;
    wumpus_killed(dir);
}

/******************************************************
** Function: wumpus_killed
** Description: Checks the rooms in the direction of dir for a Wumpus event; if
**      there is a Wumpus event, kills it; otherwise calls move_wumpus()
** Parameters: char dir
** Pre-conditions: grid, xpos, ypos have been initialized
** Post-conditions: The Wumpus is either killed or moved
******************************************************/
bool Game::wumpus_killed(char dir) {
    int i = 1;
    int x = xpos;
    int y = ypos;
    while (i < 4 && x < numrooms && x >= 0 && y < numrooms && y >= 0) {
        if ((dir == 'w' || dir == 'W') && y-1 >= 0) {
            y--;
        }
        else if ((dir == 's' || dir == 'S') && y+1 < numrooms) {
            y++;
        }
        else if ((dir == 'a' || dir == 'A') && x-1 >= 0) {
            x--;
        }
        else if ((dir == 'd' || dir == 'D') && x+1 < numrooms) {
            x++;
        }

        if (grid[x][y].get_string_event() == "wumpus") {
            set_wump_kill(true);
            cout << "There is a cut-off roar in the distance." << endl;
            break;
        }
        i++;
    }
    move_wumpus(x, y);
}

/******************************************************
** Function: move_wumpus
** Description: Moves the Wumpus to a random empty Room
** Parameters: int x, int y
** Pre-conditions: grid has been initialized, valid parameters
** Post-conditions: The original room the Wumpus was in no longer has an event;
**      based on wump_kill, either set another random room to have a Wumpus or
**      do nothing else (just delete original wumpus room)
******************************************************/
void Game::move_wumpus(int x, int y) {
    int chance = rand() % 101;
    for (int c = 0; c < numrooms; c++) {
        for (int r = 0; r < numrooms; r++) {
            if (grid[c][r].get_string_event() == "wumpus") {
                grid[c][r].set_event("", false);
                break;
            }
        }
    }

    if (chance <= 75) {
        if (wump_kill == false) {
            do {
                x = rand() % numrooms;
                y = rand() % numrooms;
            } while (grid[x][y].get_eventexists() || (x == xpos && y == ypos));
            grid[x][y].set_event("wumpus", true);
            cout << "There's a loud shuffling." << endl;
        }
    }
    else if (chance > 75 && wump_kill == false) { 
        cout << "Nothing seems to have happened..." << endl; 
    }
}

/******************************************************
** Function: move
** Description: Moves the player in a direction, and accounts for bat movement
** Parameters: N/A
** Pre-conditions: grid, xpos, ypos have been initialized
** Post-conditions: The user is moved in a direction and/or randomly by bats
******************************************************/
void Game::move() {
    char dir = 'l';
    do {
        cout << "What direction? ";
        cin >> dir;
    } while (!valid_direction(dir));

    update_pos(dir);
    if (grid[xpos][ypos].get_string_event() == "bats") {
        bats_move();
    }
}

/******************************************************
** Function: update_oos
** Description: "Moves" the player in a direction by updating either xpos or ypos
** Parameters: char dir
** Pre-conditions: xpos, ypos have been initialized, valid parameter
** Post-conditions: The user is moved in a direction
******************************************************/
void Game::update_pos(char dir) {
    if (dir == 'w' || dir == 'W') {
        ypos--;
    }
    else if (dir == 's' || dir == 'S') {
        ypos++;
    }
    else if (dir == 'a' || dir == 'A') {
        xpos--;
    }
    else if (dir == 'd' || dir == 'D') {
        xpos++;
    }
}

/******************************************************
** Function: bats_move
** Description: "Moves" the player in a direction by updating xpos and ypos randomly
** Parameters: N/A
** Pre-conditions: xpos, ypos have been initialized
** Post-conditions: The user is moved to a random room
******************************************************/
void Game::bats_move() {
    cout << "The bats have moved you!" << endl;
    int x = rand() % numrooms;
    int y = rand() % numrooms;
    xpos = x;
    ypos = y;
}

/******************************************************
** Function: endgame
** Description: Returns a boolean based on whether or not an end condition has 
**      been met; may also print update messages
** Parameters: N/A
** Pre-conditions: grid, xpos, ypos, escx, and escy have been initialized
** Post-conditions: A boolean is returned based on whether an end condition
**      is met.
******************************************************/
bool Game::endgame() {
    if (grid[xpos][ypos].get_string_event() == "wumpus") {
        cout << "The wumpus killed you!" << endl;
        return true;
    }
    else if (grid[xpos][ypos].get_string_event() == "gold") {
        cout << "You have the gold!" << endl;
        set_gold_get(true);
        grid[xpos][ypos].set_event("got", false);
        return false;
    }
    else if (grid[xpos][ypos].get_string_event() == "pit") {
        cout << "You fell in a pit and died!" << endl;
        return true;
    }
    else if (xpos == escx && ypos == escy && gold_get == true) {
        cout << "You escaped!" << endl;
        return true;
    }
    else {
        return false;
    }
}