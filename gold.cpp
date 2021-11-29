#include "gold.h"
#include <iostream>

using std::cout;
using std::endl;

/******************************************************
** Function: Gold constructor
** Description: Makes a Gold object.
** Parameters: N/A
** Pre-conditions: N/A
** Post-conditions: A Gold object is created.
******************************************************/
Gold::Gold() {
    set_message("You see a glimmer nearby.");
}

/******************************************************
** Function: Gold destructor
** Description: Destroy a Gold object.
** Parameters: N/A
** Pre-conditions: Gold object exists.
** Post-conditions: A Gold object is destroyed.
******************************************************/
Gold::~Gold() {

}

/******************************************************
** Function: percept()
** Description: Print out the percept message that goes with the event.
** Parameters: N/A
** Pre-conditions: Gold object has been initialized.
** Post-conditions: The message associated with the event is printed.
******************************************************/
void Gold::percept() {
    cout << get_message() << endl;
}