#include "Employee.hpp"

#include <ostream>

std::ostream& operator<<(std::ostream& os, const Employee& emp) {
    os 
        << "Name: " << emp.name
        << "\nAge: " << emp.age
        << "\nJob: " << emp.job
        << "\nProfile: " << emp.profile;

    return os;
}