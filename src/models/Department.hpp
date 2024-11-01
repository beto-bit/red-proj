#pragma once

#include <string>
#include <vector>

#include "Area.hpp"


struct Department {
    std::string name{};
    std::vector<Area> areas{};
};