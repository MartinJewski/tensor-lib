//
// Created by martin on 03.01.20.
//

#ifndef UNTITELED1_CONTRACTION_H
#define UNTITELED1_CONTRACTION_H

#include "tensor-builder-utilities/save_recreated_index_sequence.h"

template<std::size_t skipPos1, std::size_t skipPos2, typename T1, typename T2>
constexpr auto contraction(T1&& tensor1, T2&& tensor2){

    auto std::vector<TENSOR_DATATYPE> finalTensor = {};

    auto sris_tensor1 = save_recreated_index_sequence<offset, N, skipPos1, length, times>(cartesian_product finalTensor);
    auto sris_tensor2 = save_recreated_index_sequence<offset, N, skipPos2, length, times>(cartesian_product finalTensor);

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

}

#endif //UNTITELED1_CONTRACTION_H
