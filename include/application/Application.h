//
// Created by alexander on 26.06.2021.
//

#ifndef VISUTECH_TASK_APPLICATION_H
#define VISUTECH_TASK_APPLICATION_H


#include <tuple>
#include <iostream>

namespace Application {

    class ApplicationException : public std::exception {
        std::string _text;
    public:
        ApplicationException() = delete;
        ApplicationException(const std::string& text){
            _text = std::string("[APPLICATION]\t").append(text);
        };
        const char * what() const noexcept override {
            return _text.c_str();
        }
    };

    // run application interface
    class IRunnable {
    public:
        virtual int run(int argc, char *argv[]) = 0;
        virtual ~IRunnable() {};
    };

}

#endif //VISUTECH_TASK_APPLICATION_H
