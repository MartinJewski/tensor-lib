//
// Created by martin on 16.12.19.
//

#ifndef UNTITELED1_RECREATE_FOR_INDEX_SEQUENCE_H
#define UNTITELED1_RECREATE_FOR_INDEX_SEQUENCE_H

#include "recreate_index_tuple.h"

template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t length, std::size_t ...times, typename T>
constexpr auto recreate_for_index_sequence_i(T& tuple, std::index_sequence<times...>){

    //tuple of tuples that hold the indices with the skip position being increased a given amount of "times".
    return std::make_tuple((times, recreate_index_tuple<offset, N, skipPos, times, length>(tuple))...);
}

template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t length, std::size_t times, typename T>
constexpr auto recreate_for_index_sequence(T& tuple){

    return recreate_for_index_sequence_i<offset, N, skipPos, length>(tuple,std::make_index_sequence<times>{});

}
#endif //UNTITELED1_RECREATE_FOR_INDEX_SEQUENCE_H
