//
// Created by martin on 03.01.20.
//

#ifndef UNTITELED1_CONTRACTION_H
#define UNTITELED1_CONTRACTION_H

#include "tuple_show.h"
#include "tensor_specification.h"
#include "pos_nd_to_1d.h"
#include "tensor.h"
#include <tuple>

template<std::size_t t1_offset, std::size_t tensor1_N, std::size_t t1_skipPos, std::size_t t1_indice_amount,
         std::size_t t2_offset, std::size_t tensor2_N, std::size_t t2_skipPos, std::size_t t2_indice_amount,
         typename resultT, typename C1, typename T1, typename T2, typename C2>
constexpr auto contraction(C1&& t1_cartesian_vec, T1 tensor1_vec, C2&& t2_cartesian_vec, T2&& tensor2_vec){

    auto sris_tensor1 = save_recreated_index_sequence<t1_offset, tensor1_N, t1_skipPos, t1_indice_amount, DIM3>(t1_cartesian_vec);
    auto sris_tensor2 = save_recreated_index_sequence<t2_offset, tensor2_N, t2_skipPos, t2_indice_amount, DIM3>(t2_cartesian_vec);


    std::vector<resultT> result_vector = {};

    for(int i = 0; i < sris_tensor1.size(); i++){

        if(sris_tensor1.size() == 0){
            return result_vector;
        }

        if(sris_tensor1.size() == 1){
            result_vector.push_back(tensor1_vec[0] * tensor2_vec[0]);
        }

        if(sris_tensor1.size() == 1){

            auto i1 = tensor1_vec[pos_nd_to_1d<t1_indice_amount>(std::get<0>(sris_tensor1[i]))] *
                    tensor2_vec[pos_nd_to_1d<t2_indice_amount>(std::get<0>(sris_tensor2[i]))];

            auto i2 = tensor1_vec[pos_nd_to_1d<t1_indice_amount>(std::get<1>(sris_tensor1[i]))] *
                      tensor2_vec[pos_nd_to_1d<t2_indice_amount>(std::get<1>(sris_tensor2[i]))];

            auto i3 = tensor1_vec[pos_nd_to_1d<t1_indice_amount>(std::get<2>(sris_tensor1[i]))] *
                      tensor2_vec[pos_nd_to_1d<t2_indice_amount>(std::get<2>(sris_tensor2[i]))];

            result_vector.push_back(i1 + i2 + i3);
        }

        return result_vector;
    }

}

#endif //UNTITELED1_CONTRACTION_H
