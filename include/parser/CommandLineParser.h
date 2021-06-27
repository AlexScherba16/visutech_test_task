//
// Created by alexander on 26.06.2021.
//

#ifndef VISUTECH_TEST_COMMANDLINEPARSER_H
#define VISUTECH_TEST_COMMANDLINEPARSER_H

#include <tuple>
#include <exception>

namespace Parser {

    class ParserException : public std::exception {
        std::string _text;
    public:
        ParserException() = delete;
        ParserException(const std::string& text){
            _text = std::string("[PARSER]\t").append(text);
        };
        const char * what() const noexcept override {
            return _text.c_str();
        }
    };

    class CommandLineParser {
    public:
        CommandLineParser() = default;
        ~CommandLineParser() = default;

        std::tuple<
            /*src*/std::string,
            /*word*/ std::string,
            /*dest*/ std::string>
            parse(int argc, char *argv[]);
    };
}

#endif //VISUTECH_TEST_COMMANDLINEPARSER_H
