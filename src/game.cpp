#include "game.h"
#include "collection_utils.h"

bool Game::isAlive(Life life) const {
    return contains(lives, life);
}

void Game::addLife(Life life) {
    lives.insert(life);
}

void Game::tick() {
    lives.clear();
}
