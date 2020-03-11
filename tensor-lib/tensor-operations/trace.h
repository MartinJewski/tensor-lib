//
// Created by martin on 29.01.20.
//

#ifndef UNTITELED1_TRACE_H
#define UNTITELED1_TRACE_H


#include "pos_nd_to_1d.h"
#include "tensor_specification.h"
#include "tuple_show.h"

/**
 * Retrive the element on a given position at run time
 * @tparam value an index position
 * @tparam is index sequence value
 * @tparam T type of the elements inside the tensor
 * @tparam Args indices of the tensor
 * @param tensor object
 * @return element inside the given tensor
 */
template<std::size_t value, std::size_t ...is, typename T, typename Args>
constexpr auto calc_position(tensorBase_rt<T,Args> tensor, std::index_sequence<is...>){

    return tensor.data[pos_nd_to_1d((is, value)...)];
}

/**
 * Calculates the trace at runtime
 * @tparam T type of the elements inside the tensor
 * @tparam Args indices of the tensor
 * @tparam it an index sequence value
 * @param tensor object
 * @return value
 */
template<typename T, typename Args, std::size_t ...it>
constexpr auto trace_i(tensorBase_rt<T, Args> tensor, std::index_sequence<it...>){

    auto temp = 0.0;
    ((it, temp += calc_position<it>(tensor, std::make_index_sequence<decltype(tensor)::indices_amount>{})),...);

    return temp;
}


/**
 * Calculates the trace for a given tensor at run time
 * @tparam T type of the elements inside the tensor
 * @tparam Args indices of the tensor
 * @param tensor object
 * @return value
 */
template<typename T, typename Args>
constexpr auto trace(tensorBase_rt<T, Args> tensor){
    return trace_i(tensor, std::make_index_sequence<DIM3>{});
}


#endif //UNTITELED1_TRACE_H
