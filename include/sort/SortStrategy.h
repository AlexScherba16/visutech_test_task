//
// Created by alexander on 27.06.2021.
//

#ifndef VISUTECH_TASK_SORTSTRATEGY_H
#define VISUTECH_TASK_SORTSTRATEGY_H

#include <vector>
#include <string>

namespace Sort {

    // data replace interface
    class ISortable {
    public:
        virtual void sort(std::vector<std::string>& storage) noexcept = 0;
        virtual ~ISortable() {};
    };
}

#endif //VISUTECH_TASK_SORTSTRATEGY_H
