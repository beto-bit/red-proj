#include <concepts>
#include <type_traits>


template <typename E>
requires std::is_enum_v<E>
constexpr auto to_underlying(E e) -> std::underlying_type_t<E> {
    return static_cast<std::underlying_type_t<E>>(e);
}

template <typename E, typename U>
requires std::is_enum_v<E> && std::same_as<U, std::underlying_type_t<E>>
constexpr auto from_underlying(U u) -> E {
    return static_cast<E>(u);
}
