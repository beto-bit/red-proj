#include "Profile.hpp"

#include <ostream>

std::ostream& operator<<(std::ostream& os, Profile profile) {
    switch (profile) {
        case Profile::HighSchool:
            os << "HighSchool";
            break;

        case Profile::Degree:
            os << "Degree";
            break;

        case Profile::Master:
            os << "Master";
            break;
    }

    return os;
}