#ifndef WUMPUS_H
#define WUMPUS_H
#include <string>
#include <vector>
#include "event.h"

using namespace::std;

class Wumpus : public Event {
    public:
    //constructors + destructors
    Wumpus();
    ~Wumpus();

    void percept();

};

#endif