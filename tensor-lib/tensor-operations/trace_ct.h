//
// Created by martin on 06.01.20.
//

#ifndef UNTITELED1_TRACE_CT_H
#define UNTITELED1_TRACE_CT_H

#include "pos_nd_to_1d.h"
#include "tensor_specification.h"
#include "tuple_show.h"

template<auto T1, std::size_t value, std::size_t ...is>
constexpr auto calc_ct_position(std::index_sequence<is...>){

    return T1.data[pos_nd_to_1d((is, value)...)];
}

template<auto T1, std::size_t ...it>
constexpr auto trace_ct_i(std::index_sequence<it...>){

    auto temp = 0.0;
    ((it, temp += calc_ct_position<T1, it>(std::make_index_sequence<T1.indices_amount>{})),...);

    return temp;
}

template<auto T1>
constexpr auto trace_ct(){
    return trace_ct_i<T1>(std::make_index_sequence<DIM3>{});
}

#endif //UNTITELED1_TRACE_CT_H
