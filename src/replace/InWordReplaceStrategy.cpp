//
// Created by alexander on 26.06.2021.
//

#include "InWordReplaceStrategy.h"

namespace Replace {

    InWordReplaceStrategy::InWordReplaceStrategy(const std::string &replaceWord) :
        _regExTemplate(replaceWord) {}

    void InWordReplaceStrategy::replace(std::string &str) noexcept {
        str = std::move(regex_replace(str, _regExTemplate, " ").append("\n"));
    }

    void InWordReplaceStrategy::setPattern(const std::string &str) noexcept {
        _regExTemplate = str;
    }
}