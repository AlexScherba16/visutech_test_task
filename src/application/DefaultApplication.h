//
// Created by alexander on 26.06.2021.
//

#ifndef VISUTECH_TASK_DEFAULTAPPLICATION_H
#define VISUTECH_TASK_DEFAULTAPPLICATION_H

#include "application/Application.h"

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

    class DefaultApplication final : public IRunnable {
    public:
        DefaultApplication() = default;
        ~DefaultApplication() = default;
        int run(int argc, char *argv[]) override;
    };
}


#endif //VISUTECH_TASK_DEFAULTAPPLICATION_H
