//
// Created by martin on 06.01.20.
//

#ifndef UNTITELED1_TRACE_H
#define UNTITELED1_TRACE_H

#include "pos_nd_to_1d.h"
#include "tensor_specification.h"
#include "tuple_show.h"

template<std::size_t ...is, typename T>
constexpr auto trace_i(T&& tensor_vec, std::index_sequence<is...>){

    std::size_t temp = 0;

    for(int i = 0; i < DIM3; i++){

        std::cout << "----------" << std::endl;
        std::cout << "step: " << i << std::endl;
        std::cout << "temp 1: " << temp << std::endl;
        std::cout << "tuple: " << std::make_tuple((is, i)...) << std::endl;
        std::cout << "posnd: "  << pos_nd_to_1d((is, i)...) << std::endl;
        std::cout << "vector value: " << tensor_vec[pos_nd_to_1d((is, i)...)] << std::endl;
        temp += tensor_vec[pos_nd_to_1d((is, i)...)];
        std::cout << "temp 2: " << temp << std::endl;
        std::cout << "---------" << std::endl;
    }
    std::cout << "result :" << temp << std::endl;

    return temp;
}

template<std::size_t indice_amount, typename T>
constexpr auto trace(T&& tensor_vec){
    return trace_i(tensor_vec, std::make_index_sequence<indice_amount>{});
}

#endif //UNTITELED1_TRACE_H
