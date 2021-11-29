#include "wumpus.h"
#include <iostream>

using std::cout;
using std::endl;

/******************************************************
** Function: Wumpus constructor
** Description: Makes a Wumpus object.
** Parameters: N/A
** Pre-conditions: N/A
** Post-conditions: A Wumpus object is created.
******************************************************/
Wumpus::Wumpus() {
    set_message("You smell a terrible stench.");

}

/******************************************************
** Function: Wumpus destructor
** Description: Destroy a Wumpus object.
** Parameters: N/A
** Pre-conditions: Wumpus object exists.
** Post-conditions: A Wumpus object is destroyed.
******************************************************/
Wumpus::~Wumpus() {

}

/******************************************************
** Function: percept()
** Description: Print out the percept message that goes with the event.
** Parameters: N/A
** Pre-conditions: Wumpus object has been initialized.
** Post-conditions: The message associated with the event is printed.
******************************************************/
void Wumpus::percept() {
    cout << get_message() << endl;
}