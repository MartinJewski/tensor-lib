//
// Created by martin on 29.01.20.
//

#ifndef UNTITELED1_REORDER_H
#define UNTITELED1_REORDER_H

#include "tensor.h"

template<std::size_t ... positions, typename CartesianPos, typename T>
constexpr auto calculate_new(CartesianPos value, T tuple){

    return pos_nd_to_1d_tuple<sizeof...(positions)>(std::make_tuple(std::get<positions>(tuple)...));

}

template<std::size_t cartesian_pos, std::size_t ... positions, typename C>
constexpr auto calculate_new(C cartesian_arr){

    return pos_nd_to_1d_tuple<sizeof...(positions)>(std::make_tuple(std::get<positions>(cartesian_arr[cartesian_pos])...));

}

template<std::size_t ... positions, std::size_t ...is, typename T, typename Args>
constexpr auto reorder_i(tensorBase_rt<T,Args> tensor, std::index_sequence<is...>){

    auto cartesian_arr = tensor.calculate_indices();

    std::array<typename decltype(tensor)::elem_type, tensor.data.size()>
            reordered_positions{
            (tensor.data[static_cast<typename decltype(tensor)::elem_type>(calculate_new<is, positions...>(
                    cartesian_arr))])...
    };

    tensorBase_rt<typename decltype(tensor)::elem_type, typename decltype(tensor)::tuple_indices>
            reordered_tensor(static_cast<decltype(tensor)::elem_type>(0));
    reordered_tensor.data = reordered_positions;

    return reordered_tensor;
}

template<std::size_t ... positions, typename T, typename Args>
constexpr auto reorder(tensorBase_rt<T, Args> tensor){

    return reorder_i<positions...>(tensor, std::make_index_sequence<tensor.calculate_indices().size()>{});

}








#endif //UNTITELED1_REORDER_H
