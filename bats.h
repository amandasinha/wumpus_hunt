#ifndef BATS_H
#define BATS_H
#include <string>
#include "event.h"

using namespace::std;

class Bats : public Event {
    private:

    public:
    //constructors + destructors
    Bats();
    ~Bats();

    void percept();

};

#endif