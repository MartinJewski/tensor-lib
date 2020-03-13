//
// Created by martin on 29.01.20.
//

#ifndef UNTITELED1_REORDER_H
#define UNTITELED1_REORDER_H

#include "tensor.h"
#include "reorder_ct.h"
#include "tuple_type_list.h"


template<std::size_t ... positions, typename CartesianPos, typename T>
constexpr auto calculate_new(CartesianPos value, T tuple){

    return pos_nd_to_1d_tuple<sizeof...(positions)>(std::make_tuple(std::get<positions>(tuple)...));

}

/**
 * Calculates the new position at runtime
 * @tparam cartesian_pos
 * @tparam positions new positioning of the indices
 * @tparam C type of the array that holes the index tuples
 * @param cartesian_arr
 * @return new position
 */
template<std::size_t cartesian_pos, std::size_t ... positions, typename C>
constexpr auto calculate_new(C cartesian_arr){

    return pos_nd_to_1d_tuple<sizeof...(positions)>(std::make_tuple(std::get<positions>(cartesian_arr[cartesian_pos])...));

}

/**
 * Function that does the reordering(runtime)
 * @tparam positions new positioning of the indices
 * @tparam is deducted index sequence
 * @tparam T deducted tensor type
 * @tparam Args deducted tensor type
 * @param tensor object
 * @return returns a new tensor of the same type with reordered indices
 */
template<std::size_t ... positions, std::size_t ...is, typename T, typename Args>
constexpr auto reorder_i(tensorBase<T,Args> tensor, std::index_sequence<is...>){

    auto cartesian_arr = tensorBase<T,Args>::static_calculate_indices();

    std::array<typename decltype(tensor)::elem_type, tensor.data.size()>
            reordered_positions{
            (tensor.data[static_cast<typename decltype(tensor)::elem_type>(calculate_new<is, positions...>(
                    cartesian_arr))])...
    };


    using reorder_indices = std::tuple<typename
    tuple_type_list<typename decltype(tensor)::tuple_indices>::template type<positions>...>;

    tensorBase<typename decltype(tensor)::elem_type, reorder_indices>
            reordered_tensor(static_cast<decltype(tensor)::elem_type>(0));
    reordered_tensor.data = reordered_positions;

    return reordered_tensor;
}

/**
 * Reorders the indices, thus it reorders the elements inside the tensor at compile time
 * The standart positioning of the indices is 0,1,2,3...,N
 * E.g The indices of the tensor tensorBase_ranges<double, up_t, up_t, low_t> are ordered with 0,1,2
 * And an reorderin would mean an switch of the indices order, like the following:
 * up_t,up_t, low_t order 0,1,2
 * do a reorder reorder
 * 2,1,0  => low_t, up_t, up_t
 * (runtime)
 * @tparam positions new positioning of the indices
 * @tparam T deducted type of the runtime tensor
 * @tparam Args deducted type of the runtime tensor
 * @return returns a new tensor of the same type with reordered indices
 */
template<std::size_t ... positions, typename T, typename Args>
constexpr auto reorder(tensorBase<T, Args> tensor){

    return reorder_i<positions...>(tensor, std::make_index_sequence<
            tensorBase<T, Args>::static_calculate_indices().size()>{});

}
























//LEGACY CODE



/*
template<std::size_t ... positions, std::size_t ...is, typename T, typename Args>
constexpr auto reorder_i(tensorBase_rt<T,Args> tensor, std::index_sequence<is...>){

    auto cartesian_arr = tensorBase_rt<T,Args>::static_calculate_indices();

    std::array<typename decltype(tensor)::elem_type, tensor.data.size()>
            reordered_positions{
            (tensor.data[static_cast<typename decltype(tensor)::elem_type>(calculate_new<is, positions...>(
                    cartesian_arr))])...
    };


    using reorder_indices = std::tuple<typename
    tuple_type_list<typename decltype(tensor)::tuple_indices>::template type<positions>...>;

    tensorBase_rt<typename decltype(tensor)::elem_type, reorder_indices>
            reordered_tensor(static_cast<decltype(tensor)::elem_type>(0));
    reordered_tensor.data = reordered_positions;

    return reordered_tensor;
}

template<std::size_t ... positions, typename T, typename Args>
constexpr auto reorder(tensorBase_rt<T, Args> tensor){

    return reorder_i<positions...>(tensor, std::make_index_sequence<
            tensorBase_rt<T, Args>::static_calculate_indices().size()>{});

}
*/


#endif //UNTITELED1_REORDER_H
