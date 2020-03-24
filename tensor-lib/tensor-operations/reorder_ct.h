//
// Created by martin on 07.01.20.
//

#ifndef UNTITELED1_REORDER_CT_H
#define UNTITELED1_REORDER_CT_H

#include "tuple_show.h"
#include "pos_nd_to_1d.h"
#include <tuple>
#include "tensor.h"
#include "tuple_type_list.h"



/**
 * Calculates the new position at compile time
 * @tparam cartesian_pos position to look at inside the tuple
 * @tparam positions new positioning of the indices
 * @tparam C type of the array that holes the index tuples
 * @param cartesian_arr array
 * @return new position
 */
template<std::size_t cartesian_pos, std::size_t ... positions, typename C>
constexpr auto calculate_ct_new_position(C cartesian_arr){

    return pos_nd_to_1d_tuple<sizeof...(positions)>(std::make_tuple(std::get<positions>(cartesian_arr[cartesian_pos])...));

}

/**
 * Reorders the indices and switches the elements of the tensor at compile time
 * @tparam T1 constexpr tensor
 * @tparam positions new positioning of the indices
 * @tparam is index sequence values
 * @return returns a new tensor of the same type with reordered indices
 */
template<tensorBase T1, std::size_t ... positions, std::size_t ...is>
constexpr auto reorder_ct_i(std::index_sequence<is...>){

    auto cartesian_arr = decltype(T1)::static_calculate_indices();

    std::array<typename decltype(T1)::elem_type, T1.data.size()>
            reordered_positions{
            (T1.data[static_cast<typename decltype(T1)::elem_type>(calculate_ct_new_position<is, positions...>(
                    cartesian_arr))])...
    };

    using reorder_indices = std::tuple<typename
            tuple_type_list<typename decltype(T1)::tuple_indices>::template type<positions>...>;

    tensorBase<typename decltype(T1)::elem_type, reorder_indices> reordered_tensor{reordered_positions};
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
 * @tparam T1 constexpr tensor
 * @tparam positions new positioning of the indices
 * @return returns a new tensor of the same type with reordered indices
 */
template<tensorBase T1, std::size_t ... positions>
constexpr auto reorder(){
    return reorder_ct_i<T1, positions...>(std::make_index_sequence<decltype(T1)::static_calculate_indices().size()>{});
}


#endif //UNTITELED1_REORDER_CT_H

