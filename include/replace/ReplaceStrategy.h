//
// Created by alexander on 26.06.2021.
//

#ifndef VISUTECH_TASK_REPLACESTRATEGY_H
#define VISUTECH_TASK_REPLACESTRATEGY_H

#include <string>

namespace Replace {

    // data replace interface
    class IReplaceble {
    public:
        virtual void replace(std::string& str) noexcept = 0;
        virtual void setPattern([[maybe_unused]]const std::string& str) noexcept {};
        virtual ~IReplaceble() {};
    };

}

#endif //VISUTECH_TASK_REPLACESTRATEGY_H
