#ifndef GOLD_H
#define GOLD_H
#include <string>
#include "event.h"

using namespace::std;

class Gold : public Event {
    private:

    public:
    //constructors + destructors
    Gold();
    ~Gold();

    void percept();

};

#endif