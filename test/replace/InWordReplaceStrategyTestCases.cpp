//
// Created by alexander on 27.06.2021.
//

#include "replace/InWordReplaceStrategy.h"
#include <gtest/gtest.h>

TEST(InWordReplaceStrategyClassTest, SingleCharStringTemplate) {
    // arrange
    std::string srcFileString("test");
    std::string expectedFileString(" es \n");
    std::string word("t");
    Replace::InWordReplaceStrategy replaceStrategy(word);

    // act
    replaceStrategy.replace(srcFileString);

    // assert
    ASSERT_STREQ(srcFileString.c_str(), expectedFileString.c_str());
}

TEST(InWordReplaceStrategyClassTest, WordStringTemplate) {
    // arrange
    std::string srcFileString("abctestabc");
    std::string expectedFileString("abc abc\n");
    std::string word("test");
    Replace::InWordReplaceStrategy replaceStrategy(word);

    // act
    replaceStrategy.replace(srcFileString);

    // assert
    ASSERT_STREQ(srcFileString.c_str(), expectedFileString.c_str());
}

TEST(InWordReplaceStrategyClassTest, DoubleWordStringTemplate) {
    // arrange
    std::string srcFileString("***abctestabctest***");
    std::string expectedFileString("***abc abc ***\n");
    std::string word("test");
    Replace::InWordReplaceStrategy replaceStrategy(word);

    // act
    replaceStrategy.replace(srcFileString);

    // assert
    ASSERT_STREQ(srcFileString.c_str(), expectedFileString.c_str());
}

TEST(InWordReplaceStrategyClassTest, NoMatchStringTemplate) {
    // arrange
    std::string srcFileString("***abctestabctest***");
    std::string expectedFileString("***abctestabctest***\n");
    std::string word("rainbow");
    Replace::InWordReplaceStrategy replaceStrategy(word);

    // act
    replaceStrategy.replace(srcFileString);

    // assert
    ASSERT_STREQ(srcFileString.c_str(), expectedFileString.c_str());
}