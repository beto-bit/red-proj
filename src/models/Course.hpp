#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "Profile.hpp"


struct Schedule {
    std::uint16_t start{};
    std::uint16_t end{};
};


struct Course {
    std::string name{};
    Profile profile{};
    std::vector<Schedule> schedules{};
};