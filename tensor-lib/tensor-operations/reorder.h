//
// Created by martin on 07.01.20.
//

#ifndef UNTITELED1_REORDER_H
#define UNTITELED1_REORDER_H

#include "cartesian_product_ranges_to_vec.h"
#include "tuple_show.h"
#include "pos_nd_to_1d.h"
#include <tuple>
/*
template<std::size_t ... positions, auto T1>
constexpr auto reorder(){

    auto tensor_vec_reordered = cartesian_vec;

    for(int i = 0; i < cartesian_vec.size(); i++){

        auto oldPos = pos_nd_to_1d<sizeof...(positions)>(cartesian_vec[i]);
        //auto newPos = pos_nd_to_1d<positions...>();

        auto newPos = pos_nd_to_1d<sizeof...(positions)>(std::make_tuple((positions, std::get<positions>(tensor_vec_reordered[i]))...));

        tensor_vec_reordered[newPos] = cartesian_vec[oldPos];

        std::cout << "----------" << std::endl;
        std::cout << "OLD POS : " << oldPos << std::endl;
        std::cout << "NEW POS : " << newPos << std::endl;
        std::cout << "----------" << std::endl;
    }
    return tensor_vec_reordered;
}
*/



template<std::size_t cartesian_pos, std::size_t ... positions, typename C>
constexpr auto calculate_new(C cartesian_arr){

    auto t = std::make_tuple(std::get<positions>(cartesian_arr[cartesian_pos])...);????
    decltype(t)::foo = 1;
    //return pos_nd_to_1d<sizeof...(positions)>(std::make_tuple(std::get<positions>(cartesian_arr[cartesian_pos])...));
    return 0;
}

template<auto T1, std::size_t ... positions, std::size_t ...is>
constexpr auto reorder_i(std::index_sequence<is...>){

    auto cartesian_arr = T1.calculate_indices();

    (((calculate_new<is, positions...>(cartesian_arr))),...);

    std::array<typename decltype(T1.data)::value_type, 9> reordered_tensor{};


    return reordered_tensor;
}

template<auto T1, std::size_t ... positions>
constexpr auto reorder(){

    return reorder_i<T1, positions...>(std::make_index_sequence<T1.calculate_indices().size()>{});
}

#endif //UNTITELED1_REORDER_H

