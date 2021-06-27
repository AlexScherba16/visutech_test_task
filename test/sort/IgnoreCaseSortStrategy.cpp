//
// Created by alexander on 27.06.2021.
//

#include "sort/IgnoreCaseSortStrategy.h"
#include <gtest/gtest.h>

TEST(IgnoreCaseSortStrategyClassTest, StringWithEmptyStringCase) {
    // arrange
    std::vector<std::string> srcStringVector{"artist", " "};
    std::vector<std::string> expectedStringVector{" ", "artist"};
    Sort::IgnoreCaseSortStrategy sortStrategy;

    // act
    sortStrategy.sort(srcStringVector);
    bool result = std::equal(srcStringVector.begin(), srcStringVector.end(), expectedStringVector.begin());

    //assert
    ASSERT_TRUE(result);
}

TEST(IgnoreCaseSortStrategyClassTest, AlphabeticalOrderCase) {
    // arrange
    std::vector<std::string> srcStringVector{"cat", "boeing", "artist"};
    std::vector<std::string> expectedStringVector{"artist", "boeing", "cat"};
    Sort::IgnoreCaseSortStrategy sortStrategy;

    // act
    sortStrategy.sort(srcStringVector);
    bool result = std::equal(srcStringVector.begin(), srcStringVector.end(), expectedStringVector.begin());

    //assert
    ASSERT_TRUE(result);
}

TEST(IgnoreCaseSortStrategyClassTest, AlphabeticalOrderIgnoreCase) {
    // arrange
    std::vector<std::string> srcStringVector{"Boeing", "cat", "Artist", "boeing", "Cat", "artist"};
    std::vector<std::string> expectedStringVector{"Artist", "artist", "Boeing", "boeing", "cat", "Cat"};
    Sort::IgnoreCaseSortStrategy sortStrategy;

    // act
    sortStrategy.sort(srcStringVector);
    bool result = std::equal(srcStringVector.begin(), srcStringVector.end(), expectedStringVector.begin());

    //assert
    ASSERT_TRUE(result);
}