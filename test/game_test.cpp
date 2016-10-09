#include "gtest/gtest.h"
#include "game.h"

struct GameTest : testing::Test {

    Game *game;

    GameTest() {
        game = new Game();
        createSingleLife(0, 0);
    }

    void createSingleLife(int x, int y) {
        game->addLife(Life(x, y));
    }

    void assertIsAlive() {
        ASSERT_TRUE(game->isAlive(Life(0, 0)));
    }

    void assertIsDead() {
        ASSERT_FALSE(game->isAlive(Life(0, 0)));
    }

    void addTwoNeighbours() {
        createSingleLife(1, 0);
        createSingleLife(-1, 0);
    }

    void addThreeNeighbours() {
        addTwoNeighbours();
        createSingleLife(-1, 1);
    }

    void addFourNeighbours() {
        addThreeNeighbours();
        createSingleLife(1, 1);
    }

    ~GameTest() {
        delete game;
    }
};

TEST_F(GameTest, should_game_not_be_empty_after_adding_life) {
    assertIsAlive();
}


TEST_F(GameTest, should_alone_life_die_after_tick) {
    game->tick();

    assertIsDead();
}

TEST_F(GameTest, should_life_not_die_after_tick_when_it_has_two_neighbours) {
    addTwoNeighbours();

    game->tick();

    assertIsAlive();
}

TEST_F(GameTest, should_life_not_die_after_tick_when_it_has_three_neighbours) {
    addThreeNeighbours();

    game->tick();

    assertIsAlive();
}

TEST_F(GameTest, should_life_die_after_tick_when_it_has_more_then_three_neighbours) {
    addFourNeighbours();

    game->tick();

    assertIsDead();
}