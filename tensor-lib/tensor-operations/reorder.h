//
// Created by martin on 07.01.20.
//

#ifndef UNTITELED1_REORDER_H
#define UNTITELED1_REORDER_H

#include "cartesian_product_to_vec.h"
#include "tuple_show.h"
#include "pos_nd_to_1d.h"
#include <tuple>

template<std::size_t ... positions, typename C, typename T>
constexpr auto reorder(C&& cartesian_vec, T&& tensor_vec){

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





#endif //UNTITELED1_REORDER_H

