//
// Created by alexander on 26.06.2021.
//

#include "parser/CommandLineParser.h"
#include <gtest/gtest.h>

/* invalid argc param tests */
TEST(ParserClassTest, InvalidArgc) {
    // arrange
    int argc = 0;
    char *argv[] = {const_cast<char*>("programm_name")};
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\targc <= 0";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}


/* invalid argv param tests */
TEST(ParserClassTest, InvalidArgv) {
    // arrange
    int argc = 1;
    char **argv = nullptr;
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\targv == nullptr";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}


/* no params tests */
TEST(ParserClassTest, NoParams) {
    // arrange
    int argc = 1;
    char *argv[] = {const_cast<char*>("programm_name")};
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe option '--dest' is required but missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}


/* HELP parameter tests */
TEST(ParserClassTest, LongHelpParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--help")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tprint --help parameter";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, ShortHelpParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("-h")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tprint --help parameter";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, ErrorHelpParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("-has")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tunrecognised option '-has'";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}


/* SRC parameter tests */
TEST(ParserClassTest, LongEmptySrcParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe required argument for option '--src' is missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, ShortEmptySrcParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("-s")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe required argument for option '--src' is missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, LongSrcParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe option '--dest' is required but missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, ShortSrcParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--s=test")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe option '--dest' is required but missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, LongErrorSrcParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--srcs=test")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tunrecognised option '--srcs=test'";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, ShortErrorSrcParam) {
    // arrange
    int argc = 2;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--a=test")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tunrecognised option '--a=test'";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}


/* WORD parameter tests */
TEST(ParserClassTest, LongEmptyWordParam) {
    // arrange
    int argc = 3;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--word")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe required argument for option '--word' is missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, ShortEmptyWordParam) {
    // arrange
    int argc = 3;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("-w")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe required argument for option '--word' is missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, LongWordParam) {
    // arrange
    int argc = 3;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--word=test")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe option '--dest' is required but missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, ShortWordParam) {
    // arrange
    int argc = 3;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--w=test")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe option '--dest' is required but missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, LongErrorWordParam) {
    // arrange
    int argc = 3;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--wordd=test")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tunrecognised option '--wordd=test'";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, ShortErrorWordParam) {
    // arrange
    int argc = 3;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--d=test")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe option '--word' is required but missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}


/* DEST parameter tests */
TEST(ParserClassTest, LongEmptyDestParam) {
    // arrange
    int argc = 4;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--word=test"),
            const_cast<char*>("--dest")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe required argument for option '--dest' is missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, ShortEmptyDestParam) {
    // arrange
    int argc = 4;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--word=test"),
            const_cast<char*>("--d")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tthe required argument for option '--dest' is missing";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, LongDestParam) {
    // arrange
    int argc = 4;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--word=word"),
            const_cast<char*>("--dest=dest")
    };
    Parser::CommandLineParser parser;

    // act
    auto [src, word, dest] = parser.parse(argc, argv);

    // assert
    ASSERT_STREQ(src.c_str(), "test");
    ASSERT_STREQ(word.c_str(), "word");
    ASSERT_STREQ(dest.c_str(), "dest");
}

TEST(ParserClassTest, ShortDestParam) {
    // arrange
    int argc = 4;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--word=word"),
            const_cast<char*>("--d=dest")
    };
    Parser::CommandLineParser parser;

    // act
    auto [src, word, dest] = parser.parse(argc, argv);

    // assert
    ASSERT_STREQ(src.c_str(), "test");
    ASSERT_STREQ(word.c_str(), "word");
    ASSERT_STREQ(dest.c_str(), "dest");
}

TEST(ParserClassTest, LongErrorDestParam) {
    // arrange
    int argc = 4;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--word=word"),
            const_cast<char*>("--destt=dest")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tunrecognised option '--destt=dest'";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, ShortErrorDestParam) {
    // arrange
    int argc = 4;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--word=word"),
            const_cast<char*>("--a=dest")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\tunrecognised option '--a=dest'";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}


/* Doublicate params */
TEST(ParserClassTest, DoubleLongSrcParam) {
    // arrange
    int argc = 5;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--src=double_test"),
            const_cast<char*>("--word=test"),
            const_cast<char*>("--dest=dest")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\toption '--src' cannot be specified more than once";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, DoubleShortSrcParam) {
    // arrange
    int argc = 5;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--s=test"),
            const_cast<char*>("--s=double_test"),
            const_cast<char*>("--word=test"),
            const_cast<char*>("--dest=dest")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\toption '--src' cannot be specified more than once";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}

TEST(ParserClassTest, LongShortSrcParam) {
    // arrange
    int argc = 5;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--s=double_test"),
            const_cast<char*>("--word=test"),
            const_cast<char*>("--dest=dest")
    };
    Parser::CommandLineParser parser;

    // act and exception assert
    EXPECT_THROW(
            parser.parse(argc, argv),
            Parser::ParserException);

    // assert message string
    try {
        parser.parse(argc, argv);
    }
    catch(Parser::ParserException& ex){
        std::string message = "[PARSER]\toption '--src' cannot be specified more than once";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}