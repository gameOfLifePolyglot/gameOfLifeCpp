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
    auto emergedUnflatten = map(lives, [](Life life) { return life.possibleNeighbours(); });
    std::set<Life> possibleToEmerge;
    for (auto &sub : emergedUnflatten) {
        for (auto &emergedLife : sub) {
            possibleToEmerge.insert(emergedLife);
        }
    }
    auto emerged = filter(possibleToEmerge, [this](Life life) { return this->shouldEmerge(life); });
    lives.clear();
    lives.insert(survived.begin(), survived.end());
    lives.insert(emerged.begin(), emerged.end());
}

bool Game::shouldSurvive(Life life) const {
    unsigned long neighboursCount = getRealNeighbours(life).size();
    return neighboursCount == 2 || neighboursCount == 3;
}

bool Game::shouldEmerge(Life life) const {
    return getRealNeighbours(life).size() == 3;
}

std::set<Life> Game::getRealNeighbours(Life life) const {
    std::set<Life> intersection;
    const std::set<Life> possibleNeighbours = life.possibleNeighbours();
    std::set_intersection(lives.begin(), lives.end(),
                          possibleNeighbours.begin(), possibleNeighbours.end(),
                          std::inserter(intersection, intersection.end()));
    return intersection;
}
//
//template<typename Collection, typename Operation, typename Results>
//Results map(Collection col, Operation op) {
//    Results results;
//    std::transform(col.begin(), col.end(), std::inserter(results, results.end()), op);
//    return results;
//}
