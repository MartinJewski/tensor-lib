//
// Created by martin on 13.12.19.
//

#ifndef UNTITELED1_TUPLE_SPLIT_FROM_H
#define UNTITELED1_TUPLE_SPLIT_FROM_H

#include "make_index_sequence_from.h"
#include "tuple_split.h"

/**
 * Splits a tuple from a position start to start+N
 * @tparam start position (offset for the index sequence)
 * @tparam N length of the index sequenxe
 * @tparam T tuple type
 * @param tuple the tuple to be splitted
 * @return
 */
template<std::size_t start, std::size_t N, typename T>
constexpr auto tuple_split_from(T& tuple){
    return tuple_split_e(tuple, make_index_sequence_from<start, N>());
}


#endif //UNTITELED1_TUPLE_SPLIT_FROM_H
