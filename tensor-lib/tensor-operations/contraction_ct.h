//
// Created by martin on 03.01.20.
//

#ifndef UNTITELED1_CONTRACTION_CT_H
#define UNTITELED1_CONTRACTION_CT_H

#include "tuple_show.h"
#include "tensor_specification.h"
#include "pos_nd_to_1d.h"
#include "tensor.h"
#include <tuple>
#include <type_traits>
#include "tuple_type_list.h"

#include "tuple_helpers.h"

/**
 * Takes the result of the calculate_value_ct function
 * and turns it into a new tensor
 * @tparam T data type of the new tensor
 * @tparam U indices of the new tensor
 * @tparam Arr data array. Must have the same size as the new tensor
 * @tparam is index sequence with the same size of the given array and the new tensor
 * @param array that holds the new data
 * @return tensor after a contraction
 */
template<typename T, typename U, typename Arr, std::size_t ...is>
constexpr auto create_result_tensor_ct(Arr array, std::index_sequence<is...>){

    tensorBase<T, U> arr(static_cast<T>(array[is])...);

    return arr;
}

/**
 * The function that takes the output of the save_recreate_index_sequence function
 * for the first and second tensor and runs the multiplication.
 * @tparam indices1 amount of the first tensor
 * @tparam indices2 amount of the second tensor
 * @tparam F data type of the new tensor
 * @tparam T1 tensor of class tensorBase
 * @tparam T2 tensor of class tensorBase
 * @tparam Tuple1 auto deducted type of the save recreate index sequence input
 * @tparam Tuple2 auto deducted type of the save recreate index sequence input
 * @tparam is index sequence
 * @param tup1 save recreate index sequence input
 * @param tup2 save recreate index sequence input
 * @return contraction over a specific position
 */
template<std::size_t indices1, std::size_t indices2, typename F, tensorBase T1, tensorBase T2,
        typename Tuple1, typename Tuple2, std::size_t ...is>
constexpr auto calculate_value_i_ct(Tuple1 tup1, Tuple2 tup2, std::index_sequence<is...>){

    F add = 0.0;
    ((add += (T1.data[(pos_nd_to_1d_tuple<indices1>(std::get<is>(tup1)))]
              * T2.data[(pos_nd_to_1d_tuple<indices2>(std::get<is>(tup2)))])),...);
    return add;
}
/**
 * Wrapper function that takes the output of the save_recreate_index_sequence function
 * for the first and second tensor and runs the multiplication.
 * @tparam indices1 amount of the first tensor
 * @tparam indices2 amount of the second tensor
 * @tparam F data type of the new tensor
 * @tparam T1 tensor of class tensorBase
 * @tparam T2 tensor of class tensorBase
 * @tparam SRIST1 auto deducted type of the save recreate index sequence input
 * @tparam SRIST2 auto deducted type of the save recreate index sequence input
 * @tparam is index sequence
 * @param sris1 tuple of tuples
 * @param sris2 tuple of tuples
 * @return a new tensor
 */
template<std::size_t indices1, std::size_t indices2, typename F, tensorBase T1, tensorBase T2, typename SRIST1, typename SRIST2, std::size_t ...is>
constexpr auto calculate_value_ct(SRIST1 sris1, SRIST2 sris2, std::index_sequence<is...>){

    auto temp = (calculate_value_i_ct<indices1, indices2, F, T1, T2>(sris1[is], sris2[is], std::make_index_sequence<dim_length_n>{}),...);

    std::array<decltype(temp), sris1.size()>
            arr{calculate_value_i_ct<indices1, indices2, F, T1, T2>(sris1[is], sris2[is], std::make_index_sequence<dim_length_n>{})...};

    return arr;
}

/**
 * The contraction over two 1D arrays.
 * @tparam T1 tensor of class tensorBase
 * @tparam T2 tensor of class tensorBase
 * @tparam is index sequence
 * @return value
 */
template<tensorBase T1, tensorBase T2, std::size_t ...is>
constexpr auto contraction_ct_1D(std::index_sequence<is...>){

    auto value = 0;
    ((value += T1.data[is] * T2.data[is]),...);

    return value;
}

/**
 * Contraction of two tensors with at least one index.
 * @tparam t1_skipPos index of the first tensor
 * @tparam t2_skipPos index of the second tensor
 * @tparam T1 tensor of class tensorBase
 * @tparam T2 tensor of class tensorBase
 * @return new tensor
 */
template<std::size_t t1_skipPos, std::size_t t2_skipPos, tensorBase T1, tensorBase T2>
constexpr auto contraction(){
    /*
    using skip_type_t1 = tuple_type_list<typename decltype(T1)::tuple_indices>::template type<t1_skipPos>;
    using skip_type_t2 = tuple_type_list<typename decltype(T2)::tuple_indices>::template type<t2_skipPos>;
    static_assert((std::is_same<skip_type_t1, skip_type_t2>::value == false), "Cannot contract over the same index level."
                                                                             "E.g contraction over two up_t indices is not possible!");
     */

    if constexpr ((T1.indices_amount == 1) && (T2.indices_amount == 1)){
        //1D contraction results in a value
        auto value = contraction_ct_1D<T1, T2>(std::make_index_sequence<dim_length_n>{});

        return value;

    }else{

        //recreates the indices
        remove_ith_concat_tuple<t1_skipPos, t2_skipPos, typename decltype(T1)::tuple_indices, typename decltype(T2)::tuple_indices> types;
        typename decltype(types)::type newType;

        //creates the final tensor
        tensorBase<std::common_type_t<typename decltype(T1)::elem_type, typename decltype(T2)::elem_type>,
            decltype(newType)>
            tensor3(static_cast<std::common_type_t<typename decltype(T1)::elem_type, typename decltype(T2)::elem_type>>(0));

        //a tuple that holds all the indices of the first tensor that must be used for a successful contraction
        auto sris_tensor1 = save_recreated_index_sequence
                <0, T1.indices_amount - 1, t1_skipPos, T1.indices_amount, dim_length_n>(decltype(tensor3)::static_calculate_indices());

        //a tuple that holds all the indices of the second tensor that must be used for a successful contraction
        auto sris_tensor2 = save_recreated_index_sequence
                <T1.indices_amount - 1, T2.indices_amount - 1, t2_skipPos, T2.indices_amount, dim_length_n>(decltype(tensor3)::static_calculate_indices());

        //does the multiplication over the indices
        auto result = calculate_value_ct<T1.indices_amount, T2.indices_amount,
                std::common_type_t<typename decltype(T1)::elem_type, typename decltype(T2)::elem_type>,
                T1, T2>(sris_tensor1, sris_tensor2, std::make_index_sequence<sris_tensor1.size()>{});

        //creates the final tensor
        auto final_result = create_result_tensor_ct
                <std::common_type_t<typename decltype(T1)::elem_type, typename decltype(T2)::elem_type>,
                        decltype(newType)>(result, std::make_index_sequence<result.size()>{});

        return final_result;
    }
}

/**
 * Multiplicates a scalar with every element inside the tensor
 * @tparam T1 scalar
 * @tparam T2 tensor of class tensorBase
 * @tparam is index sequence
 * @return tensor multiplicated with the scalar
 */
template<std::size_t T1, tensorBase T2, std::size_t ...is>
constexpr auto add_scalar_ct(std::index_sequence<is...>){

    auto copyTensor = T2;
    ((copyTensor.data[is] = T1 *  copyTensor.data[is]),...);

    return copyTensor;
}



/**
 * Contracts a scalar with a tensor, which results in multiplicating
 * every tensor element with the scalar.
 * If T1 and T2 are scalars, a simple multiplication is executed.
 * @tparam T1 tensor or scalar
 * @tparam T2 tensor or scalar
 * @return tensor multiplicated with scalar or a value
 */
template<auto T1, auto T2>
constexpr auto contraction(){

    if constexpr ((std::is_fundamental<decltype(T1)>::value) && !(std::is_fundamental<decltype(T2)>::value)) {

        if constexpr ((std::is_fundamental<decltype(T1)>::value) && (T2.indices_amount >= 1)) {

            return add_scalar_ct<T1, T2>(std::make_index_sequence<decltype(T2)::data_count>{});

        }
    }

    if constexpr ((std::is_fundamental<decltype(T2)>::value) && !(std::is_fundamental<decltype(T1)>::value)) {

        if constexpr ((std::is_fundamental<decltype(T2)>::value) && (T1.indices_amount >= 1)) {

            return add_scalar_ct<T2, T1>(std::make_index_sequence<decltype(T1)::data_count>{});

        }
    }

    if constexpr ((std::is_fundamental<decltype(T1)>::value) && (std::is_fundamental<decltype(T2)>::value)) {

        return  T1*T2;

    }
}





/*
(((T1.indices_amount == 1) && (T2.indices_amount > 1)) ||
((T1.indices_amount > 1) && (T2.indices_amount == 1))||
((T1.indices_amount > 1) && (T2.indices_amount > 1)) )
*/

#endif //UNTITELED1_CONTRACTION_CT_H
