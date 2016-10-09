#ifndef GAME_OF_LIFE_CPP_GAME_H
#define GAME_OF_LIFE_CPP_GAME_H

#include <set>
#include "life.h"

class Game {
public:
    void addLife(Life life);

    bool isAlive(Life life) const;

    void tick();

private:
    std::set<Life> lives;

    bool shouldSurvive(Life life) const;

    std::set<Life> getRealNeighbours(Life life) const;
};

#endif
