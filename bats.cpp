#include "bats.h"
#include <iostream>

using std::cout;
using std::endl;

/******************************************************
** Function: Bats constructor
** Description: Makes a Bats object.
** Parameters: N/A
** Pre-conditions: N/A
** Post-conditions: A Bats object is created.
******************************************************/
Bats::Bats() {
    set_message("You hear wings flapping.");
}

/******************************************************
** Function: Bats destructor
** Description: Destroy a Bats object.
** Parameters: N/A
** Pre-conditions: Bats object exists.
** Post-conditions: A Bats object is destroyed.
******************************************************/
Bats::~Bats() {

}

/******************************************************
** Function: percept()
** Description: Print out the percept message that goes with the event.
** Parameters: N/A
** Pre-conditions: Bats object has been initialized.
** Post-conditions: The message associated with Bats is printed.
******************************************************/
void Bats::percept() {
    cout << get_message() << endl;
}