#include "pit.h"
#include <iostream>

using std::cout;
using std::endl;

/******************************************************
** Function: Pit constructor
** Description: Makes a Pit object.
** Parameters: N/A
** Pre-conditions: N/A
** Post-conditions: A Pit object is created.
******************************************************/
Pit::Pit() {
    set_message("You feel a breeze.");
}

/******************************************************
** Function: Pit destructor
** Description: Destroy a Pit object.
** Parameters: N/A
** Pre-conditions: Pit object exists.
** Post-conditions: A Pit object is destroyed.
******************************************************/
Pit::~Pit() {

}

/******************************************************
** Function: percept()
** Description: Print out the percept message that goes with the event.
** Parameters: N/A
** Pre-conditions: Pit object has been initialized.
** Post-conditions: The message associated with the event is printed.
******************************************************/
void Pit::percept() {
    cout << get_message() << endl;
}