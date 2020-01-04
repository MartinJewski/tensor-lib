//
// Created by martin on 03.01.20.
//

#ifndef UNTITELED1_CONTRACTION_H
#define UNTITELED1_CONTRACTION_H

#include "remove_ith_concat_tuple.h"
#include "tensor_specification.h"
#include "tensor.h"
#include <tuple>

template<t1_offset, tensor1_N, t1_skipPos, t1_indice_amount, t1_offset, tensor1_N, t1_skipPos, t1_indice_amount, typename T1, typename T2>
constexpr auto contraction(T1&& tensor1_vec, T2&& tensor2_vec){

    auto sris_tensor1 = save_recreated_index_sequence<t1_offset, tensor1_N, t1_skipPos, t1_indice_amount, DIM3>(tensor1_vec);
    auto sris_tensor2 = save_recreated_index_sequence<t2_offset, tensor2_N, t2_skipPos, t2_indice_amount, DIM3>(tensir2_vec);

    /*
    for(length of sris_t1){

        for(every tuple3){

            tempResult = 0;

            for(every tuple){

                val_t1 = take element form sris_tensor1 -> calc pos in tensor1 -> get element
                val_t2 = take element from sris_tensor2 -> calc pos in tensor2 -> get element

                tempResult += val_t1 * val_t2;

                finalTensor.push_back(tempResult);

            }
        }

    }

     */

}

#endif //UNTITELED1_CONTRACTION_H
