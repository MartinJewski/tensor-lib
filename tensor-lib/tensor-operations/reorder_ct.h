//
// Created by martin on 07.01.20.
//

#ifndef UNTITELED1_REORDER_CT_H
#define UNTITELED1_REORDER_CT_H

#include "../tensor-builder-utilities-ranges/cartesian_product_ranges_to_vec.h"
#include "tuple_show.h"
#include "pos_nd_to_1d.h"
#include <tuple>
#include "tensor.h"




template<std::size_t cartesian_pos, std::size_t ... positions, typename C>
constexpr auto calculate_ct_new(C cartesian_arr){

    return pos_nd_to_1d_tuple<sizeof...(positions)>(std::make_tuple(std::get<positions>(cartesian_arr[cartesian_pos])...));

}

template<tensorBase T1, std::size_t ... positions, std::size_t ...is>
constexpr auto reorder_ct_i(std::index_sequence<is...>){

    auto cartesian_arr = T1.calculate_indices();

    std::array<typename decltype(T1)::elem_type, T1.data.size()>
        reordered_positions{
            (T1.data[static_cast<typename decltype(T1)::elem_type>(calculate_ct_new<is, positions...>(
                    cartesian_arr))])...
    };

    tensorBase<typename decltype(T1)::elem_type, typename decltype(T1)::tuple_indices> reordered_tensor(reordered_positions);
    return reordered_tensor;
}

template<tensorBase T1, std::size_t ... positions>
constexpr auto reorder(){
    return reorder_ct_i<T1, positions...>(std::make_index_sequence<T1.calculate_indices().size()>{});
}





#endif //UNTITELED1_REORDER_CT_H

