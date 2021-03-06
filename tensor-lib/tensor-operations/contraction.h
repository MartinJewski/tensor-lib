//
// Created by martin machajewski on 29.01.20.
//

#ifndef UNTITELED1_CONTRACTION_H
#define UNTITELED1_CONTRACTION_H


#include "tuple_show.h"
#include "tensor_specification.h"
#include "pos_nd_to_1d.h"
#include "tensor.h"
#include <tuple>
#include <type_traits>
#include "tuple_type_list.h"
#include "tuple_helpers.h"




/**
 * Takes the result of the calculate_value function
 * and turns it into a new tensor(runtime)
 * @tparam T data type of the new tensor
 * @tparam U indices of the new tensor
 * @tparam Arr data array. Must have the same size as the new tensor
 * @tparam is index sequence with the same size of the given array and the new tensor
 * @param array that holds the new data
 * @return tensor after a contraction
 */
template<typename T, typename U, typename Arr, std::size_t ...is>
constexpr auto create_result_tensor(Arr array, std::index_sequence<is...>){

    tensorBase<T, U> arr(static_cast<T>(array[is])...);

    return arr;
}


/**
 * The function that takes the output of the save_recreate_index_sequence function
 * for the first and second tensor and runs the multiplication.(runtime)
 * @tparam indices1 amount of the first tensor
 * @tparam indices2 amount of the second tensor
 * @tparam F data type of the new tensor
 * @tparam T1 tensor of class tensorBase
 * @tparam T2 tensor of class tensorBase
 * @tparam Tuple1 auto deducted type of the save recreate index sequence input
 * @tparam Tuple2 auto deducted type of the save recreate index sequence input
 * @tparam is index sequence
 * @param tensor1 obj
 * @param tensor2 obj
 * @param tup1 save recreate index sequence input
 * @param tup2 save recreate index sequence input
 * @return contraction over a specific position
 */
template<std::size_t indices1, std::size_t indices2, typename F, typename T1, typename T2, typename Tuple1, typename Tuple2, std::size_t ...is>
constexpr auto calculate_value_i(T1 tensor1, T2 tensor2, Tuple1 tup1, Tuple2 tup2, std::index_sequence<is...>){

    F add = 0.0;

    ((add += (tensor1.data[(pos_nd_to_1d_tuple<indices1>(std::get<is>(tup1)))]
              * tensor2.data[(pos_nd_to_1d_tuple<indices2>(std::get<is>(tup2)))])),...);

    return add;
}



/**
 * Wrapper function that takes the output of the save_recreate_index_sequence function
 * for the first and second tensor and runs the multiplication.(runtime)
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
 * @param tensor1 obj
 * @param tensor2 obj
 * @return a tensor
 */
template<std::size_t indices1, std::size_t indices2, typename F, typename T1, typename T2, typename SRIST1, typename SRIST2, std::size_t ...is>
constexpr auto calculate_value(T1 tensor1, T2 tensor2, SRIST1 sris1, SRIST2 sris2, std::index_sequence<is...>){

    auto temp = (calculate_value_i<indices1, indices2, F>(tensor1, tensor2, sris1[is], sris2[is],
                                                          std::make_index_sequence<dim_length_n>{}),...);

    std::array<decltype(temp), sris1.size()>
            arr{calculate_value_i<indices1, indices2, F>(tensor1, tensor2, sris1[is], sris2[is],
                                                         std::make_index_sequence<dim_length_n>{})...};

    return arr;
}



/**
 * Contraction of two 1D tensors(runtime)
 * @tparam T1 data type of the first tensor
 * @tparam ArgsT1 indices type of the first tensor
 * @tparam T2 data type of the second tensor
 * @tparam ArgsT2 indices type of the second tensor
 * @tparam is index sequence
 * @param tensor1 object
 * @param tensor2 object
 * @return value
 */
template<typename  T1, typename ArgsT1, typename T2, typename ArgsT2, std::size_t ...is>
constexpr auto contraction_1D(tensorBase<T1, ArgsT1> tensor1, tensorBase<T2, ArgsT2> tensor2, std::index_sequence<is...>){

    auto value = 0;
    ((value += tensor1.data[is] * tensor2.data[is]),...);

    return value;
}

/**
 * Multiplicates a scalar with every element inside the tensor(runtime)
 * @tparam Scalar type of the value
 * @tparam T2 data type of the tensor
 * @tparam ArgsT2 indices type of the tensor
 * @tparam is index sequenxe
 * @param scalar value
 * @param tensor object
 * @return same tensor with new values
 */
template<typename Scalar, typename T2, typename ArgsT2, std::size_t ...is>
constexpr auto add_scalar(Scalar scalar, tensorBase<T2, ArgsT2> tensor, std::index_sequence<is...>){

    auto copyTensor = tensor;
    ((copyTensor.data[is] = scalar *  copyTensor.data[is]),...);

    return copyTensor;
}

/**
 * Contraction of two tensors with at least one index.(runtime)
 * @tparam t1_skipPos index of the first tensor
 * @tparam t2_skipPos index of the second tensor
 * @tparam T1 data type of the first tensor
 * @tparam ArgsT1 indices type of the first tensor
 * @tparam T2 data type of the first tensors
 * @tparam ArgsT2 indices type of the first tensor
 * @param tensor1 object
 * @param tensor2 object
 * @return new tensor
 */
template<std::size_t t1_skipPos, std::size_t t2_skipPos, typename T1, typename ArgsT1, typename T2, typename ArgsT2>
constexpr auto contraction(tensorBase<T1, ArgsT1> tensor1, tensorBase<T2, ArgsT2> tensor2){

    using skip_type_t1 = tuple_type_list<ArgsT1>::template type<t1_skipPos>;
    using skip_type_t2 = tuple_type_list<ArgsT2>::template type<t2_skipPos>;
    static_assert((std::is_same<skip_type_t1, skip_type_t2>::value == false), "Cannot contract over the same index level."
                                                                             "E.g contraction over two up_t indices is not possible!");

    if constexpr ((tensorBase<T1, ArgsT1>::indices_amount == 1) && (tensorBase<T2, ArgsT2>::indices_amount == 1)) {

        auto l = contraction_1D(tensor1, tensor2, std::make_index_sequence<dim_length_n>{});

        return l;

    }else{

        remove_ith_concat_tuple<t1_skipPos, t2_skipPos, ArgsT1, ArgsT2> types;
        typename decltype(types)::type newType;

        //compile time versions |static_calculate_indices
        constexpr auto ct_sris_tensor1 = save_recreated_index_sequence
                <0, tensorBase<T1, ArgsT1>::indices_amount - 1, t1_skipPos, tensorBase<T1, ArgsT1>::indices_amount, dim_length_n>
                (tensorBase<std::common_type_t<T1, T2>, decltype(newType)>::static_calculate_indices());

        constexpr auto ct_sris_tensor2 = save_recreated_index_sequence
                <tensorBase<T1, ArgsT1>::indices_amount - 1, tensorBase<T2, ArgsT2>::indices_amount - 1, t2_skipPos,
                        tensorBase<T2, ArgsT2>::indices_amount, dim_length_n>
                (tensorBase<std::common_type_t<T1, T2>, decltype(newType)>::static_calculate_indices());

        auto result = calculate_value<tensorBase<T1, ArgsT1>::indices_amount, tensorBase<T2, ArgsT2>::indices_amount,
                std::common_type_t<T1, T2>>
                (tensor1, tensor2, ct_sris_tensor1, ct_sris_tensor2, std::make_index_sequence<ct_sris_tensor1.size()>{});

        auto final_result = create_result_tensor
                <std::common_type_t<T1, T2>,
                        decltype(newType)>(result, std::make_index_sequence<result.size()>{});

        return final_result;
    }
}

/**
 * Contraction of a scalar and a tensor(runtime)
 * @tparam T1 values type
 * @tparam ArgsT2 deducted indices type
 * @tparam T2 deducted data type of the tensor
 * @param tensor object
 * @param value a value
 * @return
 */
template<typename T1, typename T2, typename ArgsT2>
constexpr auto contraction(T1 value, tensorBase<T2, ArgsT2> tensor){

    if constexpr ((tensorBase<T2, ArgsT2>::indices_amount >= 1)) {
        return add_scalar(value, tensor, std::make_index_sequence<decltype(tensor)::data_count>{});
    }
}

/**
 * Contraction of a scalar and a tensor(runtime)
 * @tparam T1 deducted data type of the tensor
 * @tparam ArgsT1 deducted indices type
 * @tparam T2 deducted value type
 * @param tensor object
 * @param value a value
 * @return
 */
template<typename T1, typename ArgsT1, typename T2>
constexpr auto contraction(tensorBase<T1, ArgsT1> tensor, T2 value){

    if constexpr ((tensorBase<T1, ArgsT1>::indices_amount >= 1)) {
        return add_scalar(value, tensor, std::make_index_sequence<decltype(tensor)::data_count>{});
    }
}

template<typename T1, typename T2>
constexpr auto contraction(T1 val1, T2 val2){

    return val1*val2;

}



















//LEGACY CODE




/*

template<typename  T1, typename ArgsT1, typename T2, typename ArgsT2, std::size_t ...is>
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

    using skip_type_t1 = tuple_type_list<ArgsT1>::template type<t1_skipPos>;
    using skip_type_t2 = tuple_type_list<ArgsT2>::template type<t2_skipPos>;
    static_assert((std::is_same<skip_type_t1, skip_type_t2>::value == false), "Cannot contract over the same index level."
                                                                             "E.g contraction over two up_t indices is not possible!");

        if constexpr ((tensorBase_rt<T1, ArgsT1>::indices_amount == 1) && (tensorBase_rt<T2, ArgsT2>::indices_amount == 1)) {

            using type = std::common_type_t<T1, T2>;

            auto l = contraction_1D(tensor1, tensor2, std::make_index_sequence<dim_length_n>{});

            return l;

        }else{

            remove_ith_concat_tuple<t1_skipPos, t2_skipPos, ArgsT1, ArgsT2> types;
            typename decltype(types)::type newType;

            //tensorBase_rt<std::common_type_t<T1, T2>, decltype(newType)> tensor3(static_cast<std::common_type_t<T1, T2>>(0));

            //compile time versions |static_calculate_indices
            constexpr auto ct_sris_tensor1 = save_recreated_index_sequence
                    <0, tensorBase_rt<T1, ArgsT1>::indices_amount - 1, t1_skipPos, tensorBase_rt<T1, ArgsT1>::indices_amount, dim_length_n>
                    (tensorBase_rt<std::common_type_t<T1, T2>, decltype(newType)>::static_calculate_indices());

            constexpr auto ct_sris_tensor2 = save_recreated_index_sequence
                    <tensorBase_rt<T1, ArgsT1>::indices_amount - 1, tensorBase_rt<T2, ArgsT2>::indices_amount - 1, t2_skipPos,
                    tensorBase_rt<T2, ArgsT2>::indices_amount, dim_length_n>
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
            return add_scalar(value, tensor, std::make_index_sequence<decltype(tensor)::data_count>{});
        }
}


template<typename T1, typename ArgsT1, typename T2>
constexpr auto contraction(tensorBase_rt<T1, ArgsT1> tensor, T2 value){

        if constexpr ((tensorBase_rt<T1, ArgsT1>::indices_amount >= 1)) {
            return add_scalar(value, tensor, std::make_index_sequence<decltype(tensor)::data_count>{});
        }
}


template<typename T1, typename T2>
constexpr auto contraction(T1 val1, T2 val2){

        return val1*val2;

}
*/

#endif //UNTITELED1_CONTRACTION_H
