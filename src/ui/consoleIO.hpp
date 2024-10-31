#pragma once

#include <concepts>
#include <cstdint>
#include <string>
#include <string_view>
#include <optional>

void clearConsole();

void wait_enter();
void wait_enter(std::string_view str);

char read_char();
std::optional<char> read_char_exact();

std::string read_line();


std::optional<std::uint64_t> impl_read_signed_integer();
std::optional<std::int64_t> impl_read_unsigned_integer();


template <std::signed_integral T>
std::optional<T> read_integer() {
    return impl_read_signed_integer();
}

template <std::unsigned_integral T>
std::optional<T> read_integer() {
    return impl_read_unsigned_integer();
}

std::optional<float> read_float();
std::optional<double> read_double();