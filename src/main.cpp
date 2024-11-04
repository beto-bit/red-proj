#include <iostream>

#include "models/Employee.hpp"

int main() {
    Employee emp{
        "Jonathan rivas",
        20,
        "Ni pura verga",
        Profile::Degree
    };

    std::cout << emp << '\n';
}