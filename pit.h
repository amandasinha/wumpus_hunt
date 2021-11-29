#ifndef PIT_H
#define PIT_H
#include <string>
#include "event.h"

using namespace::std;

class Pit : public Event {
    private:

    public:
    //constructors + destructors
    Pit();
    ~Pit();

    void percept();

};

#endif