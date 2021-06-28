//
// Created by alexander on 26.06.2021.
//

#ifndef VISUTECH_TASK_DEFAULTAPPLICATION_H
#define VISUTECH_TASK_DEFAULTAPPLICATION_H

#include "application/Application.h"

namespace Application {

    class DefaultApplication final : public IRunnable {
    public:
        DefaultApplication() = default;
        ~DefaultApplication() = default;
        int run(int argc, char *argv[]) override;
    };
}


#endif //VISUTECH_TASK_DEFAULTAPPLICATION_H
