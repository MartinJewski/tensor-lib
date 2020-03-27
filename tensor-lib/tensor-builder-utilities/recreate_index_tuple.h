//
// Created by martin on 13.12.19.
//

#ifndef UNTITELED1_RECREATE_INDEX_TUPLE_H
#define UNTITELED1_RECREATE_INDEX_TUPLE_H

#include "tuple_split_from.h"

/**
 * Creates a new tuple and inserts a value at the skip pos
 * @tparam offset where to start the tuple split
 * @tparam N how many elements to split (offset+N)
 * @tparam skipPos position where the old index was
 * @tparam Number that is placed at the skipPos
 * @tparam T tuple type
 * @tparam is the number inserted inside the new tuple
 * @param tuple obj
 * @return
 */
template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t Number, typename T, std::size_t ... is>
constexpr auto recreate_index_tuple_i(T& tuple, std::index_sequence<is...>){

    auto splitted_tuple = tuple_split_from<offset, N>(tuple);

    return std::make_tuple((is,

            [splitted_tuple](auto&& elem){ if constexpr (is == skipPos) { return Number; }
                if constexpr (is < skipPos ) { return std::get<is>(splitted_tuple); }
                if constexpr (is > skipPos ) { return std::get<is-1>(splitted_tuple);}}(is))

                ...);
}


/**
 * Function that runs the creation of a new tuple and inserts a value at the skip pos
 * @tparam offset where to start the tuple split
 * @tparam N how many elements to split (offset+N)
 * @tparam skipPos position where the old index was
 * @tparam Number that is placed at the skipPos
 * @tparam length length of the index (usually DIM3. E.g (00)(01)(02) skipPos 1 and times 3)
 * @tparam T tuple type
 * @param tuple obj
 * @return
 */
template<std::size_t offset, std::size_t N, std::size_t skipPos, std::size_t Number, std::size_t length, typename T>
constexpr auto recreate_index_tuple(T& tuple){

    return recreate_index_tuple_i<offset, N, skipPos, Number>(tuple, std::make_index_sequence<length>{});

}





// for two indices
template<std::size_t pos1, std::size_t pos2, std::size_t Number, typename T, std::size_t ... is>
constexpr auto recreate_double_index_tuple_i(T& tuple, std::index_sequence<is...>){

    static_assert((pos1 != pos2), "Pos1 and Pos2 must be different!");
    auto working_tuple = tuple;

    auto tup = std::make_tuple((is,

            [working_tuple](auto&& elem){ if constexpr ((is == pos1) || (is == pos2)) { return Number; }
                if constexpr ((is < pos1) && (is < pos2) ) { return std::get<is>(working_tuple);}
                if constexpr ((is > pos1) && (is > pos2) ) { return std::get<is-2>(working_tuple);}
                if constexpr ((is > pos1) && (is < pos2) ) { return std::get<is-1>(working_tuple);}
    }(is))

                                   ...);
    return tup;
}

//length always origintuple.size() + 2
template<std::size_t pos1, std::size_t pos2, std::size_t Number, std::size_t length, typename T>
constexpr auto recreate_index_tuple(T& tuple){

    return recreate_double_index_tuple_i<pos1, pos2, Number>(tuple, std::make_index_sequence<length>{});

}


#endif //UNTITELED1_RECREATE_INDEX_TUPLE_H
