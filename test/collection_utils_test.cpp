#include "gtest/gtest.h"
#include "collection_utils.h"

TEST(collection_utils_test, set_should_contian_element) {
    std::set<int> set;

    set.insert(1);

    ASSERT_TRUE(contains(set, 1));
}

TEST(collection_utils_test, set_should_not_contian_element) {
    std::set<int> set;

    set.insert(2);

    ASSERT_FALSE(contains(set, 1));
}

TEST(collection_utils_test, set_should_constain_all_elements) {
    std::set<int> set;

    set.insert(2);
    set.insert(3);

    std::set<int> otherSet;
    otherSet.insert(2);
    otherSet.insert(3);

    ASSERT_TRUE(containsAll(set, otherSet));
}

TEST(collection_utils_test, set_should_not_constain_all_elements) {
    std::set<int> set;

    set.insert(3);

    std::set<int> otherSet;
    otherSet.insert(2);
    otherSet.insert(3);

    ASSERT_FALSE(containsAll(set, otherSet));
}