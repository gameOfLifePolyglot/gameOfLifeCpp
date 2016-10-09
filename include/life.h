//
// Created by ghost on 08/10/16.
//

#if !defined(LIFE_H_)
#define LIFE_H_

#include <cstdlib>
#include <set>

class Life {
public:
    Life(int x_, int y_);

    bool operator<(const Life &l) const;

    bool operator==(const Life &l) const;

    friend std::ostream &operator<<(std::ostream &strm, const Life &life);

    std::set<Life> possibleNeighbours() const;

private:
    int x, y;

    std::size_t hash() const;
};


#endif
