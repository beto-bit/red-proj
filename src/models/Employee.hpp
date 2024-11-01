#pragma once

#include <cstdint>
#include <string>

#include "Profile.hpp"


struct Employee {
    std::string name{};
    std::uint16_t age{};
    std::string job{};
    Profile profile{};
};