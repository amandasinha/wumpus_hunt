#ifndef ROOM_H
#define ROOM_H
#include "event.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include <string>

using std::string;

class Room {
    private:
    Event* which;
    bool eventexists;
    string eventstring;

    public:
    //constructors + destructors
    Room();
    Room(const Room& existing_room);
    Room& operator= (const Room& existing_room);
    ~Room();

    Event* get_event();
    string get_string_event();
    bool get_eventexists();
    void set_event(string event, bool eventexist);
    void set_eventexists(bool exists);
    bool encounter();

};

#endif