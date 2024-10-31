#include <ios>
#include <iostream>
#include <limits>
#include <string_view>

// For clear screen
#ifdef _WIN32
#include <cstdlib>
#endif


constexpr auto max_streamsize = std::numeric_limits<std::streamsize>::max();


void clearConsole() {
#if defined(__linux__)
    std::cout << "\033[2J\033[1;1H";
#elif _WIN32
    std::system("cls");
#endif
}

void waitEnter(std::string_view str) {
    if (!str.empty())
        std::cout << str << '\n';

    std::cin.ignore(max_streamsize);
    std::cin.get();
}
