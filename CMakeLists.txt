cmake_minimum_required(VERSION 3.16)
project(visutech_task)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include_directories(include src test)

# build application
add_executable(visutech_task
        src/main.cpp
        src/parser/CommandLineParser.cpp
        include/application/Application.h
        src/application/DefaultApplication.h
        src/application/DefaultApplication.cpp
        include/replace/ReplaceStrategy.h
        src/replace/InWordReplaceStrategy.cpp
        src/replace/InWordReplaceStrategy.h
        include/sort/SortStrategy.h
        src/sort/IgnoreCaseSortStrategy.cpp
        src/sort/IgnoreCaseSortStrategy.h)
target_link_libraries(visutech_task
        pthread
        boost_thread
        boost_program_options)

# tests build
add_executable(visutech_task_tests
        test/main.cpp
        src/parser/CommandLineParser.cpp
        include/application/Application.h
        src/application/DefaultApplication.h
        src/application/DefaultApplication.cpp
        include/replace/ReplaceStrategy.h
        src/replace/InWordReplaceStrategy.cpp
        src/replace/InWordReplaceStrategy.h
        include/sort/SortStrategy.h
        src/sort/IgnoreCaseSortStrategy.cpp
        src/sort/IgnoreCaseSortStrategy.h
        test/parser/ParserTestCases.cpp
        test/application/DefaultApplicationTestCases.cpp
        test/replace/InWordReplaceStrategyTestCases.cpp
        test/sort/IgnoreCaseSortStrategy.cpp)

target_link_libraries(visutech_task_tests
        gtest
        gtest_main
        pthread
        boost_thread
        boost_program_options)
