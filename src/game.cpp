#include "game.h"
#include "collection_utils.h"

bool Game::isAlive(Life life) {
    return contains(lives, life);
}

void Game::addLife(Life life) {
    lives.insert(life);
}
