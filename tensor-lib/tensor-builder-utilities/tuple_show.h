//
// Created by martin on 10.12.19.
//

#ifndef UNTITELED1_TUPLE_SHOW_H
#define UNTITELED1_TUPLE_SHOW_H

#include <iostream>
#include <tuple>
#include <utility>

/**
 * Overloads << to print tuples
 * @tparam Ch
 * @tparam Tr
 * @tparam Args
 * @param os
 * @param t
 * @return
 */
template<class Ch, class Tr, class... Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& t) {
    std::apply([&os](auto&&... args) {((os << args << " "), ...);}, t);
    return os;
}

/**
 * Overload << to print  pairs
 * @tparam Ch
 * @tparam Tr
 * @tparam Args
 * @param os
 * @param t
 * @return
 */
template<class Ch, class Tr, class... Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os, std::pair<Args...> const& t) {
    std::apply([&os](auto&&... args) {((os << args << " "), ...);}, t);
    return os;
}

#endif //UNTITELED1_TUPLE_SHOW_H
