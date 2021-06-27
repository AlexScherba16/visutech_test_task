//
// Created by alexander on 27.06.2021.
//

#ifndef VISUTECH_TASK_IGNORECASESORTSTRATEGY_H
#define VISUTECH_TASK_IGNORECASESORTSTRATEGY_H

#include "sort/SortStrategy.h"

namespace Sort {

    class IgnoreCaseSortStrategy final : public ISortable {
    public:
        IgnoreCaseSortStrategy() = default;
        ~IgnoreCaseSortStrategy() = default;

        void sort(std::vector<std::string>& storage) noexcept override;
    };
}

#endif //VISUTECH_TASK_IGNORECASESORTSTRATEGY_H
