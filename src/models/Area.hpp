#pragma once

#include <string>
#include <vector>


struct Workstation {
    std::string name{};
};


struct Area {
    std::string name{};
    std::vector<Workstation> workstations{};
};