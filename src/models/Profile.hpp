#pragma once

#include <optional>
#include <iosfwd>

enum Profile : char {
    HighSchool = '_',
    Degree = '<',
    Master = '>'
};

[[nodiscard]]
constexpr std::optional<Profile> profile_from_char(char ch) {
    switch (ch) {
        case '_':   return Profile::HighSchool;
        case '<':   return Profile::Degree;
        case '>':   return Profile::Master;
        default:    return {};
    }
}

std::ostream& operator<<(std::ostream& os, Profile profile);