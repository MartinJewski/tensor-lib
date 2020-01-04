//
// Created by martin on 11.12.19.
//

#ifndef UNTITELED1_TUPLE_SPLIT_H
#define UNTITELED1_TUPLE_SPLIT_H


template<std::size_t ... is, typename T>
constexpr auto tuple_split_e(T& tuple, std::index_sequence<is...>){

    return std::make_tuple((is, std::get<is>(tuple))...);
}

template<std::size_t N, typename T>
constexpr auto tuple_split(T& tuple){
    return tuple_split_e(tuple, std::make_index_sequence<N>{});
}





#endif //UNTITELED1_TUPLE_SPLIT_H