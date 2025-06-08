#include "GameUtil.h"

const bool Util::equalIngnoreCase(std::string& first, std::string&& second)
{
    return std::equal(first.begin(), first.end(), second.begin(), second.end(),
        [](char a, char b) {
            return std::tolower(a) == std::tolower(b);
        });
}
