//
// Created by ghost on 08/10/16.
//

#if !defined(LIFE_H_)
#define LIFE_H_
#include <cstdlib>

class Life {
public:
    Life(int x_, int y_);

    bool operator<(const Life &l) const;

private:
    int x, y;

    std::size_t hash() const;
};


#endif
