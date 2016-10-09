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

std::size_t Life::hash() const {
    std::size_t seed = 0;
    boost::hash_combine(seed, x);
    boost::hash_combine(seed, y);
    return seed;
}