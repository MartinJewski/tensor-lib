//
// Created by martin on 29.01.20.
//

#ifndef UNTITELED1_CONTRACTION_H
#define UNTITELED1_CONTRACTION_H

#include "tensor-concepts.h"

#include "tuple_show.h"
#include "tensor_specification.h"
#include "pos_nd_to_1d.h"
#include "tensor.h"
#include <tuple>
#include <type_traits>

#include "tuple_helpers.h"


template<typename T, typename U, typename Arr, std::size_t ...is>
constexpr auto create_result_tensor(Arr array, std::index_sequence<is...>){

    tensorBase_rt<T, U> arr(static_cast<T>(array[is])...);

    return arr;
}

template<std::size_t indices1, std::size_t indices2, typename F, typename T1, typename T2, typename Tuple1, typename Tuple2, std::size_t ...is>
constexpr auto calculate_value_i(T1 tensor1, T2 tensor2, Tuple1 tup1, Tuple2 tup2, std::index_sequence<is...>){

    F add = 0.0;

    ((add += (tensor1.data[(pos_nd_to_1d_tuple<indices1>(std::get<is>(tup1)))]
              * tensor2.data[(pos_nd_to_1d_tuple<indices2>(std::get<is>(tup2)))])),...);

    return add;
}

template<std::size_t indices1, std::size_t indices2, typename F, typename T1, typename T2, typename SRIST1, typename SRIST2, std::size_t ...is>
constexpr auto calculate_value(T1 tensor1, T2 tensor2, SRIST1 sris1, SRIST2 sris2, std::index_sequence<is...>){

    auto temp = (calculate_value_i<indices1, indices2, F>(tensor1, tensor2, sris1[is], sris2[is], std::make_index_sequence<DIM3>{}),...);

    std::array<decltype(temp), sris1.size()>
            arr{calculate_value_i<indices1, indices2, F>(tensor1, tensor2, sris1[is], sris2[is], std::make_index_sequence<DIM3>{})...};

    return arr;
}

template<typename T, typename  T1, typename ArgsT1, typename T2, typename ArgsT2, std::size_t ...is>
constexpr auto contraction_1D(tensorBase_rt<T1, ArgsT1> tensor1, tensorBase_rt<T2, ArgsT2> tensor2, std::index_sequence<is...>){

    auto value = 0;
    ((value += tensor1.data[is] * tensor2.data[is]),...);

    return value;
}

template<typename Scalar, typename T2, typename ArgsT2, std::size_t ...is>
constexpr auto add_scalar(Scalar scalar, tensorBase_rt<T2, ArgsT2> tensor, std::index_sequence<is...>){

    auto copyTensor = tensor;
    ((copyTensor.data[is] = scalar *  copyTensor.data[is]),...);

    return copyTensor;
}


template<std::size_t t1_skipPos, std::size_t t2_skipPos, typename T1, typename ArgsT1, typename T2, typename ArgsT2>
constexpr auto contraction(tensorBase_rt<T1, ArgsT1> tensor1, tensorBase_rt<T2, ArgsT2> tensor2){

        if constexpr ((tensorBase_rt<T1, ArgsT1>::indices_amount == 1) && (tensorBase_rt<T2, ArgsT2>::indices_amount == 1)) {

            using type = std::common_type_t<T1, T2>;

            auto l = contraction_1D<type>(tensor1, tensor2, std::make_index_sequence<DIM3>{});

            return l;

        }else{

            remove_ith_concat_tuple<t1_skipPos, t2_skipPos, ArgsT1, ArgsT2> types;
            typename decltype(types)::type newType;

            //tensorBase_rt<std::common_type_t<T1, T2>, decltype(newType)> tensor3(static_cast<std::common_type_t<T1, T2>>(0));

            //compile time versions |static_calculate_indices
            constexpr auto ct_sris_tensor1 = save_recreated_index_sequence
                    <0, tensorBase_rt<T1, ArgsT1>::indices_amount - 1, t1_skipPos, tensorBase_rt<T1, ArgsT1>::indices_amount, DIM3>
                    (tensorBase_rt<std::common_type_t<T1, T2>, decltype(newType)>::static_calculate_indices());

            constexpr auto ct_sris_tensor2 = save_recreated_index_sequence
                    <tensorBase_rt<T1, ArgsT1>::indices_amount - 1, tensorBase_rt<T2, ArgsT2>::indices_amount - 1, t2_skipPos, tensorBase_rt<T2, ArgsT2>::indices_amount, DIM3>
                    (tensorBase_rt<std::common_type_t<T1, T2>, decltype(newType)>::static_calculate_indices());

            auto result = calculate_value<tensorBase_rt<T1, ArgsT1>::indices_amount, tensorBase_rt<T2, ArgsT2>::indices_amount,
                    std::common_type_t<T1, T2>>
                    (tensor1, tensor2, ct_sris_tensor1, ct_sris_tensor2, std::make_index_sequence<ct_sris_tensor1.size()>{});

            auto final_result = create_result_tensor
                    <std::common_type_t<T1, T2>,
                            decltype(newType)>(result, std::make_index_sequence<result.size()>{});

            return final_result;
        }
}


template<typename T1, typename T2, typename ArgsT2>
constexpr auto contraction(T1 value, tensorBase_rt<T2, ArgsT2> tensor){

        if constexpr ((tensorBase_rt<T2, ArgsT2>::indices_amount >= 1)) {
            return add_scalar(value, tensor, std::make_index_sequence<DIM3>{});
        }
}

template<typename T1, typename ArgsT1, typename T2>
constexpr auto contraction(tensorBase_rt<T1, ArgsT1> tensor, T2 value){

        if constexpr ((tensorBase_rt<T1, ArgsT1>::indices_amount >= 1)) {
            return add_scalar(value, tensor, std::make_index_sequence<DIM3>{});
        }
}

template<typename T1, typename T2>
constexpr auto contraction(T1 val1, T2 val2){

        return val1*val2;

}

#endif //UNTITELED1_CONTRACTION_H
