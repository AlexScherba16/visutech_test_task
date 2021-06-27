//
// Created by alexander on 26.06.2021.
//

#ifndef VISUTECH_TASK_APPLICATION_H
#define VISUTECH_TASK_APPLICATION_H


#include <tuple>
#include <iostream>

namespace Application {

    // run application interface
    class IRunnable {
    public:
        virtual int run(int argc, char *argv[]) = 0;
        virtual ~IRunnable() {};
    };

}

#endif //VISUTECH_TASK_APPLICATION_H
