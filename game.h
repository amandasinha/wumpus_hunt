#ifndef GAME_H
#define GAME_H
#include <vector>
#include "room.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"

using namespace::std;

class Game {
    private:
    bool gold_get;
    bool wump_kill;
    int numrooms;
    vector<vector<Room> > grid;
    int xpos;
    int ypos;
    int escx;
    int escy;
    bool debugging;
    int arrows;

    public:
    //constructors + destructors
    Game(bool debugging, int numrooms);
    Game(const Game& existing_game);
    Game& operator= (const Game& existing_game);
    ~Game();

    //setters
    void set_gold_get(bool gold_get);
    void set_wump_kill(bool wump_kill);
    void set_grid(int rooms);

    //assorted functions
    void setup_event(string event);
    void setup();
    void print_rooms();
    void print_rooms_debug();
    void print_event(int x, int y);
    bool valid_direction(char dir);
    void do_precept(int x, int y);
    void fire_precepts();
    void turn();
    void fire();
    bool wumpus_killed(char dir);
    void move_wumpus(int x, int y);
    void move();
    void update_pos(char dir);
    void bats_move();
    bool endgame();

};

#endif