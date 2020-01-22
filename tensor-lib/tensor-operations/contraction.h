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

#include "tuple_helpers.h"

/*
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
*/


template<typename T1, typename T2, std::size_t ...is>
constexpr void calculate_value_i(T1 tuple1, T2 tuple2, std::index_sequence<is...>){

    ((pos_nd_to_1d_tuple<std::tuple_size<T1>::value-1>(std::get<is>(tuple1))),...);
    ((pos_nd_to_1d_tuple<std::tuple_size<T2>::value-1>(std::get<is>(tuple2))),...);

}

template<typename SRIST1, typename SRIST2, std::size_t ...is>
constexpr void calculate_value(SRIST1 sris1, SRIST2 sris2, std::index_sequence<is...>){

    (calculate_value_i(sris1[is], sris2[is], std::make_index_sequence<DIM3>{}),...);

}

template<std::size_t t1_skipPos, std::size_t t2_skipPos, auto T1, auto T2>
constexpr auto contraction(){

    remove_ith_concat_tuple<t1_skipPos, t2_skipPos, decltype(T1.myTypeTup), decltype(T2.myTypeTup)> types;
    typename decltype(types)::type newType;

    tensorBase<double, decltype(newType)> tensor3{};
    auto t3_indices = tensor3.calculate_indices();
    //decltype(t3_indices)::foo = 1;

    auto sris_tensor1 = save_recreated_index_sequence
            <0, T1.indices_amount-1, t1_skipPos, T1.indices_amount, DIM3>(t3_indices);
    auto sris_tensor2 = save_recreated_index_sequence
            <T1.indices_amount-1, T2.indices_amount-1, t2_skipPos, T2.indices_amount, DIM3>(t3_indices);

    calculate_value(sris_tensor1, sris_tensor2, std::make_index_sequence<sris_tensor1.size()>{});


    return sris_tensor1;
}


#endif //UNTITELED1_CONTRACTION_H
