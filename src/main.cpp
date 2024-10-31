#include <iostream>

#include "ui/consoleIO.hpp"

int main() {
    std::cout << "Starting program...\n";

    std::cout << "enter your char: ";
    const auto foo = read_char_exact();

    if (foo)
        std::cout << "You entered: " << foo.value() << '\n';
    else
        std::cout << "An error ocurred\n";
}
