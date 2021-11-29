#include "room.h"
#include <iostream>
using namespace::std;

/******************************************************
** Function: Room constructor
** Description: Creates a new Room
** Parameters: N/A
** Pre-conditions: N/A
** Post-conditions: Room object is created.
******************************************************/
Room::Room() {
    which = NULL;
    eventexists = false;
}

/******************************************************
** Function: Room copy constructor
** Description: Creates a new Room based on existing_room
** Parameters: const Room& existing_room
** Pre-conditions: existing_room exists
** Post-conditions: Room object is created based on existing_room.
******************************************************/
Room::Room(const Room& existing_room) {
    if (eventstring != "") {
        delete [] this->which;
        this->which = existing_room.which;
    }
    this->eventexists = existing_room.eventexists;
    this->eventstring = existing_room.eventstring;
}

/******************************************************
** Function: Room assignment operator overload
** Description: Assigns attributes to Room based on existing_room
** Parameters: const Room& existing_room
** Pre-conditions: existing_room exists
** Post-conditions: Room object is equal to existing_room.
******************************************************/
Room& Room::operator= (const Room& existing_room) {
    if (this != &existing_room) {
        if (eventstring != "") {
            delete [] this->which;
            this->which = existing_room.which;
        }
        this->eventexists = existing_room.eventexists;
        this->eventstring = existing_room.eventstring;
    }
    return *this;
}

/******************************************************
** Function: Room destructor
** Description: Destroys a Room
** Parameters: N/A
** Pre-conditions: Room object exists
** Post-conditions: Room object is destroyed.
******************************************************/
Room::~Room() {
    delete [] which;
}

/******************************************************
** Function: get_event
** Description: Returns Event* which.
** Parameters: N/A
** Pre-conditions: N/A
** Post-conditions: Event* which is returned.
******************************************************/
Event* Room::get_event() {
    return which;
}

/******************************************************
** Function: get_string_event
** Description: Returns string eventstring.
** Parameters: N/A
** Pre-conditions: eventstring exists
** Post-conditions: eventstring is returned.
******************************************************/
string Room::get_string_event() {
    return eventstring;
}

/******************************************************
** Function: get_eventexists
** Description: Returns bool eventexists.
** Parameters: N/A
** Pre-conditions: eventexists exists
** Post-conditions: eventexists is returned.
******************************************************/
bool Room::get_eventexists() {
    return eventexists;
}

/******************************************************
** Function: set_event
** Description: Assigns an event to Room based on parameters event and eventexist
** Parameters: string event, bool eventexist
** Pre-conditions: Valid parameters
** Post-conditions: An event is assigned to which based on parameters.
******************************************************/
void Room::set_event(string event, bool eventexist) {
    delete [] which;
    if (event == "wumpus") {
        Wumpus thing;
        eventstring = "wumpus";
        Event* which = &thing;
    }
    else if (event == "gold") {
        Gold thing;
        eventstring = "gold";
        Event* which = &thing;
    }
    else if (event == "bats") {
        Bats thing;
        eventstring = "bats";
        Event* which = &thing;
    }
    else if (event == "pit") {
        Pit thing;
        eventstring = "pit";
        Event* which = &thing;
    }
    else {
        eventstring = "";
    }
    set_eventexists(eventexist);
}

/******************************************************
** Function: set_eventexists
** Description: Updates eventexists based on parameter
** Parameters: bool exists
** Pre-conditions: Valid parameter
** Post-conditions: eventexists = exists
******************************************************/
void Room::set_eventexists(bool exists) {
    eventexists = exists;
}