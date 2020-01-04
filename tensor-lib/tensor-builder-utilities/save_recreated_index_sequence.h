//
// Created by martin on 18.12.19.
//

#ifndef UNTITELED1_SAVE_RECREATED_INDEX_SEQUENCE_H
#define UNTITELED1_SAVE_RECREATED_INDEX_SEQUENCE_H

#include "save_as_array.h"
#include "recreate_for_index_sequence.h"
#include <range/v3/view/for_each.hpp>
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/view/repeat_n.hpp>
#include "tuple_show.h"
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/common.hpp>
#include <vector>

//recreated index for every element in the cartesian product vector

template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t length, std::size_t times, typename Vec>
constexpr auto save_recreated_index_sequence(Vec&& vec){

    std::vector<decltype(recreate_for_index_sequence<offset, N, skipPos, length, times>(vec[0]))> hold = {};

    for(int i = 0; i < vec.size(); i++){

        hold.push_back(recreate_for_index_sequence<offset, N, skipPos, length, times>(vec[i]));

    }

    return hold;
}



#endif //UNTITELED1_SAVE_RECREATED_INDEX_SEQUENCE_H