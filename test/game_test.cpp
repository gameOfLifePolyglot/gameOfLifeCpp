#include "gtest/gtest.h"
#include "game.h"

struct GameTest : testing::Test {

    Game *game;

    GameTest() {
        game = new Game();
    }

    ~GameTest() {
        delete game;
    }
};

TEST_F(GameTest, should_game_not_be_empty_after_adding_life) {
    game->addLife(Life(0, 0));

    ASSERT_TRUE(game->isAlive(Life(0, 0)));
}


TEST_F(GameTest, should_alone_life_die_after_tick) {
    game->addLife(Life(0, 0));

    game->tick();

    ASSERT_FALSE(game->isAlive(Life(0, 0)));
}

TEST_F(GameTest, should_life_not_die_after_tick_when_it_has_two_neighbours) {
    game->addLife(Life(0, 0));
    game->addLife(Life(1, 0));
    game->addLife(Life(-1, 0));

    game->tick();

    ASSERT_TRUE(game->isAlive(Life(0, 0)));
}

TEST_F(GameTest, should_life_not_die_after_tick_when_it_has_three_neighbours) {
    game->addLife(Life(0, 0));
    game->addLife(Life(1, 0));
    game->addLife(Life(-1, 0));
    game->addLife(Life(-1, 1));

    game->tick();

    ASSERT_TRUE(game->isAlive(Life(0, 0)));
}