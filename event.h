#ifndef EVENT_H
#define EVENT_H
#include <string>

using namespace::std;

class Event {
    private:
    string message;

    public:
    //constructors + destructors
    Event();
    Event(const Event& existing_event);
    Event& operator= (const Event& existing_event);
    ~Event();

    string get_message();
    void set_message(string message);

    virtual void percept() = 0;

};

#endif