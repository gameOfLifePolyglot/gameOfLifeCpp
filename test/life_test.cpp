#include "life.h"
#include "gtest/gtest.h"
#include "test_utils.h"

TEST(life_test, should_life_allows_to_store_itself_into_set) {
    std::set<Life> lives;
    ASSERT_TRUE(lives.empty());

    lives.insert(Life(0, 0));

    ASSERT_FALSE(lives.empty());
}

TEST(life_test, set_can_contains_two_different_lives) {
    std::set<Life> lives;
    ASSERT_TRUE(lives.empty());

    lives.insert(Life(0, 0));
    lives.insert(Life(1, 0));

    ASSERT_EQ(lives.size(), 2);
}

TEST(life_test, set_shouldnt_contain_two_lives_if_they_are_the_same) {
    std::set<Life> lives;
    ASSERT_TRUE(lives.empty());

    lives.insert(Life(0, 0));
    lives.insert(Life(0, 0));

    ASSERT_EQ(lives.size(), 1);
}

TEST(life_test, should_life_returns_its_possible_neighbours) {
    const Life &life = Life(0, 0);

    std::set<Life> expected;
    expected.insert(Life(-1,-1));
    expected.insert(Life(-1,0));
    expected.insert(Life(-1,1));
    expected.insert(Life(0,-1));
    expected.insert(Life(0,1));
    expected.insert(Life(1,-1));
    expected.insert(Life(1,0));
    expected.insert(Life(1,1));

    ASSERT_TRUE(containsAll(life.possibleNeighbours(), expected));
}