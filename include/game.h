#ifndef GAME_OF_LIFE_CPP_GAME_H
#define GAME_OF_LIFE_CPP_GAME_H

#include <set>
#include "life.h"

class Game {
public:
    void addLife(Life life);

    bool isAlive(Life life);

private:
    std::set<Life> lives;
};

#endif
