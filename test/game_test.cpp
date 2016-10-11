#include "gtest/gtest.h"
#include "game.h"

struct GameTest : testing::Test {

    Game *game;

    GameTest() {
        game = new Game();
    }

    void createLife(int x = 0, int y = 0) {
        game->addLife(Life(x, y));
    }

    void assertIsAlive() {
        ASSERT_TRUE(game->isAlive(Life(0, 0)));
    }

    void assertIsDead() {
        ASSERT_FALSE(game->isAlive(Life(0, 0)));
    }

    void addTwoNeighbours() {
        createLife(1, 0);
        createLife(-1, 0);
    }

    void addThreeNeighbours() {
        addTwoNeighbours();
        createLife(-1, 1);
    }

    void addFourNeighbours() {
        addThreeNeighbours();
        createLife(1, 1);
    }

    ~GameTest() {
        delete game;
    }
};

TEST_F(GameTest, should_game_not_be_empty_after_adding_life) {
    createLife();

    assertIsAlive();
}


TEST_F(GameTest, should_alone_life_die_after_tick) {
    createLife();

    game->tick();

    assertIsDead();
}

TEST_F(GameTest, should_life_not_die_after_tick_when_it_has_two_neighbours) {
    createLife();
    addTwoNeighbours();

    game->tick();

    assertIsAlive();
}

TEST_F(GameTest, should_life_not_die_after_tick_when_it_has_three_neighbours) {
    createLife();
    addThreeNeighbours();

    game->tick();

    assertIsAlive();
}

TEST_F(GameTest, should_life_die_after_tick_when_it_has_more_then_three_neighbours) {
    createLife();
    addFourNeighbours();

    game->tick();

    assertIsDead();
}

TEST_F(GameTest, should_life_emerge_after_tick_when_it_has_three_neighbours) {
    addThreeNeighbours();

    game->tick();

    assertIsAlive();
}