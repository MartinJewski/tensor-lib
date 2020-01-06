//
// Created by martin on 06.01.20.
//

#ifndef UNTITELED1_TRACE_COORDINATES_H
#define UNTITELED1_TRACE_COORDINATES_H

#include "pos_nd_to_1d.h"
#include "tensor_specification.h"

template<std::size_t ...is>
constexpr auto monoton_tuple_e(std::index_sequence<is...>){

    for(int i = 3; i < DIM3; i++){
        pos_nd_to_1d((is)...);ws
    }
    //do pos_nd_to_1d(0,0,0,0), pos_nd_to_1d(1,1,1,1) etc...

}

template<std::size_t indice_amount>
constexpr auto monoton_tuple(std::make_index_sequence<indice_amount>{})


#endif //UNTITELED1_TRACE_COORDINATES_H
