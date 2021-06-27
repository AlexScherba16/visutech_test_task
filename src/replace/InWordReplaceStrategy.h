//
// Created by alexander on 26.06.2021.
//

#ifndef VISUTECH_TASK_INWORDREPLACESTRATEGY_H
#define VISUTECH_TASK_INWORDREPLACESTRATEGY_H

#include "replace/ReplaceStrategy.h"
#include <regex>

namespace Replace {

    class InWordReplaceStrategy final : public IReplaceble {
        std::regex _regExTemplate;

    public:
        InWordReplaceStrategy(const std::string& replaceWord);
        InWordReplaceStrategy() = delete;
        ~InWordReplaceStrategy() = default;

        void replace(std::string& str) noexcept override;

        void setPattern(const std::string& str) noexcept override;
    };
}

#endif //VISUTECH_TASK_INWORDREPLACESTRATEGY_H
