#include "event.h"
#include <iostream>

using std::cout;
using std::endl;

/******************************************************
** Function: Event constructor
** Description: Makes a basic Event object.
** Parameters: N/A
** Pre-conditions: N/A
** Post-conditions: An Event object is created.
******************************************************/
Event::Event() {

}

/******************************************************
** Function: Event copy constructor
** Description: Makes a basic Event object based on existing_event.
** Parameters: const Event& existing_event
** Pre-conditions: existing_event exists
** Post-conditions: An Event object is created.
******************************************************/
Event::Event(const Event& existing_event) {
    this->message = existing_event.message;
}

/******************************************************
** Function: Event assignment operator overload
** Description: Makes a basic Event object based on existing_event.
** Parameters: const Event& existing_event
** Pre-conditions: existing_event exists.
** Post-conditions: The attributes of existing_event are assigned to the current object.
******************************************************/
Event& Event::operator= (const Event& existing_event) {
    if (this != &existing_event) {
        this->message = existing_event.message;
    }
    return *this;
}

/******************************************************
** Function: Event destructor
** Description: Destroys an Event object
** Parameters: N/A
** Pre-conditions: Event object exists.
** Post-conditions: Event object is destroyed.
******************************************************/
Event::~Event() {

}

/******************************************************
** Function: get_message()
** Description: Returns the message associated with the event.
** Parameters: N/A
** Pre-conditions: Message has been assigned.
** Post-conditions: Message is returned.
******************************************************/
string Event::get_message() {
    return message;
}

/******************************************************
** Function: set_message()
** Description: Sets the message to be the parameter message
** Parameters: string message
** Pre-conditions: N/A
** Post-conditions: message is equal to the parameter message
******************************************************/
void Event::set_message(string message) {
    this->message = message;
}
