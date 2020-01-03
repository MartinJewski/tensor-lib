//
// Created by martin on 13.12.19.
//

#ifndef UNTITELED1_RECREATE_INDEX_TUPLE_H
#define UNTITELED1_RECREATE_INDEX_TUPLE_H

#include "tuple_split_from.h"

template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t Number, typename T, std::size_t ... is>
constexpr auto recreate_index_tuple_i(T& tuple, std::index_sequence<is...>){

    auto splitted_tuple = tuple_split_from<offset, N>(tuple);

    return std::make_tuple((is,

            [splitted_tuple](auto&& elem){ if constexpr (is == skipPos) { return Number; }
                if constexpr (is < skipPos ) { return std::get<is>(splitted_tuple); }
                if constexpr (is > skipPos ) { return std::get<is-1>(splitted_tuple);}}(is))

                ...);
}

template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t Number, std::size_t length, typename T>
constexpr auto recreate_index_tuple(T& tuple){

    return recreate_index_tuple_i<offset, N, skipPos, Number>(tuple, std::make_index_sequence<length>{});

}


#endif //UNTITELED1_RECREATE_INDEX_TUPLE_H
