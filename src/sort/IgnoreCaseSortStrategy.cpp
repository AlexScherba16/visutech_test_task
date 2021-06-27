//
// Created by alexander on 27.06.2021.
//

#include <algorithm>
#include "IgnoreCaseSortStrategy.h"

namespace Sort {
    void IgnoreCaseSortStrategy::sort(std::vector<std::string> &storage) noexcept {

        auto charComparatorLambda = [](const char &char1, const char &char2) {
            return tolower(char1) < tolower(char2);
        };

        auto stringComparatorLambda = [charComparatorLambda](const std::string &str1, const std::string &str2) {
            return lexicographical_compare(
                    begin(str1), end(str1),
                    begin(str2), end(str2),
                    charComparatorLambda);
        };

        std::sort(begin(storage), end(storage), stringComparatorLambda);
    }
}