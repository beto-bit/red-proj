#pragma once

#include "Department.hpp"

#include <string>
#include <vector>


struct Company {
    std::string name{};
    std::vector<Department> departments{};
};