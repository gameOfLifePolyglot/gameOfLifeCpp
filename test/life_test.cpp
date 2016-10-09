#include "life.h"
#include "gtest/gtest.h"

TEST(life_test, should_create_life) {
    Life *life = new Life(0, 0);
    delete life;
}

TEST(life_test, should_life_has_x_and_y) {
    Life *life = new Life(1, 2);
    delete life;
}

TEST(life_test, should_put_life_into_set) {
    std::set<Life> lives;
    ASSERT_TRUE(lives.empty());

    lives.insert(Life(0, 0));

    ASSERT_FALSE(lives.empty());
}

TEST(life_test, should_put_two_lives) {
    std::set<Life> lives;
    ASSERT_TRUE(lives.empty());

    lives.insert(Life(0, 0));
    lives.insert(Life(1, 0));

    ASSERT_EQ(lives.size(), 2);
}

TEST(life_test, should_not_put_two_the_same_lives) {
    std::set<Life> lives;
    ASSERT_TRUE(lives.empty());

    lives.insert(Life(0, 0));
    lives.insert(Life(0, 0));

    ASSERT_EQ(lives.size(), 1);
}

TEST(life_test, equality) {
    ASSERT_TRUE(Life(0,0) < Life(0,1));
}