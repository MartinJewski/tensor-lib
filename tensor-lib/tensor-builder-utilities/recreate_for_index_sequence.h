//
// Created by martin on 16.12.19.
//

#ifndef UNTITELED1_RECREATE_FOR_INDEX_SEQUENCE_H
#define UNTITELED1_RECREATE_FOR_INDEX_SEQUENCE_H

#include "recreate_index_tuple.h"

/**
 * Runs the recreation over the index sequence 0,...,times-1
 * @tparam offset where to start the tuple split
 * @tparam N how many elements to split (offset+N)
 * @tparam skipPos position where the old index was
 * @tparam length of old tuple (N+1)
 * @tparam times length of the index (usually DIM3. E.g (00)(01)(02) skipPos 1 and times 3)
 * @tparam T type of the tuple
 * @param tuple obj
 * @return
 */
template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t length, std::size_t ...times, typename T>
constexpr auto recreate_for_index_sequence_i(T& tuple, std::index_sequence<times...>){

    //tuple of tuples that hold the indices with the skip position being increased a given amount of "times".
    return std::make_tuple((times, recreate_index_tuple<offset, N, skipPos, times, length>(tuple))...);
}

/**
 * Recreates the indices from an contracted index tuple
 * @tparam offset where to start the tuple split
 * @tparam N how many elements to split (offset+N)
 * @tparam skipPos position where the old index was
 * @tparam length of old tuple (N+1)
 * @tparam times length of the index (usually DIM3. E.g (00)(01)(02) skipPos 1 and times 3)
 * @tparam T type of the tuple
 * @param tuple obj
 * @return reacted indices and saves them inside a tuple
 */
template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t length, std::size_t times, typename T>
constexpr auto recreate_for_index_sequence(T& tuple){

    return recreate_for_index_sequence_i<offset, N, skipPos, length>(tuple,std::make_index_sequence<times>{});

}




template<std::size_t pos1, std::size_t pos2, std::size_t length, std::size_t ...times, typename T>
constexpr auto recreate_for_index_sequence_i(T& tuple, std::index_sequence<times...>){

    //tuple of tuples that hold the indices with the skip position being increased a given amount of "times".
    return std::make_tuple((times, recreate_index_tuple<pos1, pos2, times, length>(tuple))...);
}


template<std::size_t pos1, std::size_t pos2, std::size_t length, std::size_t times, typename T>
constexpr auto recreate_for_index_sequence(T& tuple){

    static_assert((pos1 != pos2), "Pos1 and Pos2 must be different!");
    return recreate_for_index_sequence_i<pos1, pos2, length>(tuple,std::make_index_sequence<times>{});

}



#endif //UNTITELED1_RECREATE_FOR_INDEX_SEQUENCE_H
