#include <vector>
#include "game.h"
#include "collection_utils.h"

bool Game::isAlive(Life life) const {
    return contains(lives, life);
}

void Game::addLife(Life life) {
    lives.insert(life);
}

void Game::tick() {
    auto survived = filter(lives, [this](Life life) { return this->shouldSurvive(life); });
    lives.clear();
    lives.insert(survived.begin(), survived.end());
}

bool Game::shouldSurvive(Life life) const {
    unsigned long neighboursCount = getRealNeighbours(life).size();
    return neighboursCount == 2 || neighboursCount == 3;
}

std::set<Life> Game::getRealNeighbours(Life life) const {
    std::set<Life> intersection;
    const std::set<Life> possibleNeighbours = life.possibleNeighbours();
    std::set_intersection(lives.begin(), lives.end(),
                          possibleNeighbours.begin(), possibleNeighbours.end(),
                          std::inserter(intersection, intersection.end()));
    return intersection;
}