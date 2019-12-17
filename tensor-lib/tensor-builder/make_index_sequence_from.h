//
// Created by martin on 12.12.19.
//

#ifndef UNTITELED1_MAKE_INDEX_SEQUENCE_FROM_H
#define UNTITELED1_MAKE_INDEX_SEQUENCE_FROM_H

#include <iostream>
#include <utility>

template <std::size_t O, std::size_t ... Is>
constexpr std::index_sequence<(O + Is)...> add_offset(std::index_sequence<Is...>)
{
    return {};
}

template <std::size_t O, std::size_t N>
constexpr auto make_index_sequence_from()
{
    return add_offset<O>(std::make_index_sequence<N>{});
}

template <std::size_t ... Is>
void print(std::index_sequence<Is...>)
{
    for (auto i : {Is...}) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}



#endif //UNTITELED1_MAKE_INDEX_SEQUENCE_FROM_H
