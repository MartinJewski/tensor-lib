//
// Created by martin on 04.01.20.
//

#ifndef UNTITELED1_POS_ND_TO_1D_H
#define UNTITELED1_POS_ND_TO_1D_H

#include <tuple>
#include "tensor_specification.h"

template <auto ... as>
auto constexpr pos_nd_to_1d ()
{
    std::size_t  i { 0u };

    (((i *= DIM3, i += as), ...));

    return i;
}

template <typename ...Values>
auto constexpr pos_nd_to_1d (Values&& ... is)
{
    std::size_t  i { 0u };

    (((i *= DIM3, i += is), ...));

    return i;
}



template <typename ... Args>
auto constexpr pos_nd_to_1d_calc (Args... values)
{
    std::size_t  i { 0u };

    (((i *= DIM3, i += values), ...));

    return i;
}


template<typename T, std::size_t ... is>
constexpr auto pos_calc(T tuple, std::index_sequence<is...>){

    return pos_nd_to_1d_calc ((is, std::get<is>(tuple))...);

}


template<std::size_t indice_amount, typename T>
constexpr auto pos_nd_to_1d_tuple(T tuple){
    return pos_calc(tuple, std::make_index_sequence<indice_amount>{});
}



#endif //UNTITELED1_POS_ND_TO_1D_H
