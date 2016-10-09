#include "gtest/gtest.h"
#include "game.h"

TEST(game_test, should_game_not_be_empty_after_adding_life) {
    Game game;

    game.addLife(Life(0, 0));

    ASSERT_TRUE(game.isAlive(Life(0, 0)));
}


