//
// Created by martin on 18.12.19.
//

#ifndef UNTITELED1_SAVE_RECREATED_INDEX_SEQUENCE_H
#define UNTITELED1_SAVE_RECREATED_INDEX_SEQUENCE_H


#include "recreate_for_index_sequence.h"
#include <range/v3/view/for_each.hpp>
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/view/repeat_n.hpp>
#include "tuple_show.h"
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/common.hpp>
#include <vector>
/*
//recreated index for every element in the cartesian product vector
template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t length, std::size_t times, typename Vec>
constexpr auto save_recreated_index_sequence_original(Vec&& vec){

    std::vector<decltype(recreate_for_index_sequence<offset, N, skipPos, length, times>(vec[0]))> hold = {};
    for(int i = 0; i < vec.size(); i++){

        hold.push_back(recreate_for_index_sequence<offset, N, skipPos, length, times>(vec[i]));

    }

    return hold;
}
*/

/**
 * Saves the recreated indices inside a array
 * @tparam offset where to start the tuple split
 * @tparam N how many elements to split (offset+N)
 * @tparam skipPos position where the old index was
 * @tparam length length of the new tuple (N+1)
 * @tparam times length of the index (usually DIM3. E.g (00)(01)(02) skipPos 1 and times 3)
 * @tparam Arr array
 * @tparam is index sequence
 * @param arr obj
 * @return array of tuple
 */
template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t length, std::size_t times,
        typename Arr, std::size_t ...is>
constexpr auto save_recreated_index_sequence_i(Arr&& arr, std::index_sequence<is...>){

    //fills an array at compile time with tuples
    std::array<decltype(recreate_for_index_sequence
            <offset, N, skipPos, length, times>(arr[0])), arr.size()>
                hold{(is, recreate_for_index_sequence<offset, N, skipPos, length, times>(arr[is]))...};
    return hold;
}

/**
 * Saves the recreated indices inside a array
 * @tparam offset where to start the tuple split
 * @tparam N how many elements to split (offset+N)
 * @tparam skipPos position where the old index was
 * @tparam length length of the new tuple (N+1)
 * @tparam times length of the index (usually DIM3. E.g (00)(01)(02) skipPos 1 and times 3)
 * @tparam Arr array
 * @param arr obj
 * @return array of tuple
 */
template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t length, std::size_t times, typename Arr>
constexpr auto save_recreated_index_sequence(Arr&& arr){

    return save_recreated_index_sequence_i<offset, N, skipPos, length, times>(arr, std::make_index_sequence<arr.size()>{});
}

#endif //UNTITELED1_SAVE_RECREATED_INDEX_SEQUENCE_H
