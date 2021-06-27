//
// Created by alexander on 27.06.2021.
//

#include "application/DefaultApplication.h"
#include <gtest/gtest.h>

TEST(DefaultApplicationClassTest, InvalidSrcPath) {
    // arrange
    int argc = 4;
    char *argv[] = {
            const_cast<char*>("programm_name"),
            const_cast<char*>("--src=test"),
            const_cast<char*>("--word=word"),
            const_cast<char*>("--dest=dest")
    };
    Application::DefaultApplication app;

    // act and exception assert
    EXPECT_THROW(
            app.run(argc, argv),
            Application::ApplicationException);

    // assert message string
    try {
        app.run(argc, argv);
    }
    catch(Application::ApplicationException& ex){
        std::string message = "[APPLICATION]\tCan't open source file\ttest";
        ASSERT_STREQ(ex.what(), message.c_str());
    }
}