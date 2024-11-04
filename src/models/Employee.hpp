#pragma once

#include <cstdint>
#include <string>
#include <iosfwd>

#include "Profile.hpp"


struct Employee {
    std::string name{};
    std::uint16_t age{};
    std::string job{};
    Profile profile{};
};

std::ostream& operator<<(std::ostream& os, const Employee& emp);