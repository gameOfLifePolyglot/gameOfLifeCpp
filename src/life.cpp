//
// Created by ghost on 08/10/16.
//

#include <functional>
#include "life.h"
#include <boost/functional/hash.hpp>

Life::Life(int x_, int y_) : x(x_), y(y_) {}

bool Life::operator<(const Life &l) const {
    bool result = true;
    if (hash() <= l.hash()) {
        result = false;
    }
    return result;
}

bool Life::operator==(const Life &l) const {
    return x == l.x && y == l.y;
}

std::size_t Life::hash() const {
    std::size_t seed = 0;
    boost::hash_combine(seed, x);
    boost::hash_combine(seed, y);
    return seed;
}

std::set<Life> Life::possibleNeighbours() const {
    std::set<Life> results;
    for (int i = x - 1; i < 2; i++) {
        for (int j = y - 1; j < 2; j++) {
            if (i == x && j == y) {
                continue;
            } else {
                results.insert(Life(i, j));
            }
        }
    }
    return results;
}

std::ostream &operator<<(std::ostream &strm, const Life &life) {
    return strm << "Life(x:" << life.x << ", y:" << life.y << ")";
}