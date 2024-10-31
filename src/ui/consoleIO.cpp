#include <ios>
#include <iostream>
#include <limits>
#include <optional>
#include <string>
#include <string_view>

// For clear screen
#ifdef _WIN32
#include <cstdlib>
#endif

#include "consoleIO.hpp"


[[maybe_unused]]
constexpr auto max_streamsize = std::numeric_limits<std::streamsize>::max();


void clearConsole() {
#if defined(__linux__)
    std::cout << "\033[2J\033[1;1H";
#elif _WIN32
    std::system("cls");
#endif
}


bool has_unextracted_input() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}


void wait_enter() {
    if (!std::cin)
        std::cin.clear();

    if (!std::cin.eof())
        std::cin.ignore(max_streamsize, '\n');

    std::cin.clear();
    std::cin.get();
}

void wait_enter(std::string_view str) {
    std::cout << str << '\n';
    wait_enter();
}


char read_char() {
    char ch{};
    std::cin >> ch;

    return ch;
}


template <class T>
std::optional<T> fallible_extraction() {
    T val{};
    std::cin >> val;

    if (!std::cin || has_unextracted_input()) {
        std::cin.clear();
        return std::nullopt;
    }

    return val;
}


std::optional<char> read_char_exact() {
    return fallible_extraction<char>();
}


std::string read_line() {
    std::string line{};
    std::getline(std::cin, line);

    return line;
}


std::optional<std::uint64_t> impl_read_signed_integer() {
    return fallible_extraction<std::uint64_t>();
}

std::optional<std::int64_t> impl_read_unsigned_integer() {
    return fallible_extraction<std::int64_t>();
}


std::optional<float> read_float() {
    return fallible_extraction<float>();
}

std::optional<double> read_double() {
    return fallible_extraction<double>();
}
