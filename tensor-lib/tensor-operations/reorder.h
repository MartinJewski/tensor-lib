//
// Created by martin on 29.01.20.
//

#ifndef UNTITELED1_REORDER_H
#define UNTITELED1_REORDER_H

#include "tensor.h"
/*
template<std::size_t cartesian_pos, std::size_t ... positions, typename C>
constexpr auto calculate_new(C cartesian_arr){

    return pos_nd_to_1d_tuple<sizeof...(positions)>(std::make_tuple(std::get<positions>(cartesian_arr[cartesian_pos])...));

}
*/

template<typename T, std::size_t ...is>
constexpr auto reorder_i(T tensor, std::index_sequence<is...>){

    auto cartesian_arr = tensor.calculate_indices();
/*
    std::array<typename decltype(tensor.data)::value_type, tensor.data.size()>
            reordered_positions{
            (tensor.data[static_cast<typename decltype(tensor.data)::value_type>(calculate_new<is, positions...>(
                    cartesian_arr))])...
    };

    tensorBase<typename decltype(tensor.data)::value_type, decltype(tensor.myTypeTup)> reordered_tensor(reordered_positions);
    return reordered_tensor;
*/
    return 0;
}

template<std::size_t ... positions, typename T>
constexpr auto reorder(T tensor){

    return reorder_i(tensor, std::make_index_sequence<T::indices_amount>{});

}




#endif //UNTITELED1_REORDER_H
