//
// Created by martin on 04.02.20.
//

#ifndef UNTITELED1_CONTRACTION_RANGES_H
#define UNTITELED1_CONTRACTION_RANGES_H

#include "tensor-concepts.h"

#include "tensor_range.h"
#include "tuple_helpers.h"
#include <type_traits>
#include <tuple>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/transform.hpp>
#include "recreate_for_index_sequence.h"
#include "contraction.h"

/**
 * Calculates the contraction between two given tensors
 * @tparam skipPos1 the index you want to iterate over of the first tensor
 * @tparam skipPos2 the index you want to iterate over of the second tensor
 * @tparam T1 type of the elements inside tensor1
 * @tparam Args1 indices of tensor1
 * @tparam T2 type of the elements inside tensor2
 * @tparam Args2 indices of tensor2
 * @param tensor1 tensor object
 * @param tensor2 tensor object
 * @return a new tensor with the common type and removed indices
 */
template<std::size_t skipPos1, std::size_t skipPos2, typename T1, typename Args1, typename T2, typename Args2>
constexpr auto contraction_ranges(tensorBase_ranges<T1, Args1> tensor1, tensorBase_ranges<T2, Args2> tensor2){

    /*
    using skip_type_t1 = tuple_type_list<Args1>::template type<skipPos1>;
    using skip_type_t2 = tuple_type_list<Args2>::template type<skipPos2>;
    static_assert((std::is_same<skip_type_t1, skip_type_t2>::value == false), "Cannot contract over the same index level. "
                                                                             "E.g contraction over two up_t indices is not possible!");
    */
    remove_ith_concat_tuple<skipPos1, skipPos2,
         typename decltype(tensor1)::tuple_indices, typename decltype(tensor2)::tuple_indices> tensor3_types;

    tensorBase_ranges<std::common_type_t<typename decltype(tensor1)::elem_type, typename decltype(tensor2)::elem_type>,
          typename decltype(tensor3_types)::type>
          result_tensor3(static_cast<std::common_type_t<typename decltype(tensor1)::elem_type, typename decltype(tensor2)::elem_type>>(0));

    //if both tensors are 1D vectors
    if constexpr ((tensorBase_ranges<T1, Args1>::indices_amount == 1) && (tensorBase_ranges<T2, Args2>::indices_amount == 1)) {

        auto local_val = ranges::accumulate(tensor1.data_to_range_positions1D()
                                | ranges::views::transform([=](auto tuple){ return std::get<1>(tuple) *
                                                                                    tensor2.data[std::get<0>(tuple)];}), 0);
        return local_val;

        //if both tensors have more than 1 index
    }else{
        //recreate the indices from the contracted index tuple
        auto sris = result_tensor3.calculate_indices()
                    | ranges::views::transform([tensor1, tensor2](auto tuple)
                                               {return std::make_tuple(
                                                       recreate_for_index_sequence
                                                               <0, decltype(tensor1)::indices_amount - 1, skipPos1, decltype(tensor1)::indices_amount, dim_length_n>(tuple),

                                                       recreate_for_index_sequence
                                                               <decltype(tensor1)::indices_amount - 1, decltype(tensor2)::indices_amount - 1, skipPos2,
                                                                       decltype(tensor2)::indices_amount, dim_length_n>(tuple));})
                    | ranges::views::transform([tensor1, tensor2](auto tuple){return
                    //calculates the final value with the given indice tuples before the contraction
                    calculate_value_i<
                        decltype(tensor1)::indices_amount,
                        decltype(tensor2)::indices_amount,
                        std::common_type_t<typename decltype(tensor1)::elem_type, typename decltype(tensor2)::elem_type>>
                        (tensor1, tensor2, std::get<0>(tuple), std::get<1>(tuple), std::make_index_sequence<dim_length_n>{});})
                    | ranges::to<std::vector>();

        result_tensor3.data = sris;
        return result_tensor3;
    }
}

/**
 * Overload that contracts a scalar with a tensor
 * @tparam Scalar type of val
 * @tparam T1 type of elements inside tensor
 * @tparam ArgsT1 indices of the tensor
 * @param val scalar value
 * @param tensor tensor object
 * @return the same tensor, but all elements where multiplicated with an value val
 */
template<typename Scalar, typename T1, typename ArgsT1> requires isFundamental<Scalar> && isTensor<tensorBase_ranges<T1, ArgsT1>>
constexpr auto contraction_ranges(Scalar val, tensorBase_ranges<T1, ArgsT1> tensor){

    static_assert((tensorBase_ranges<T1, ArgsT1>::indices_amount >= 1), "1 OR MORE INDICES ARE NEEDED");
        if constexpr ((tensorBase_ranges<T1, ArgsT1>::indices_amount >= 1)) {
            auto copyTensor = tensor;
            copyTensor.data = copyTensor.data | ranges::views::transform([=](auto i){return i * val;})| ranges::to<std::vector>();

            return copyTensor;
        }
}

/**
 * Overload that contracts a scalar with a tensor
 * @tparam Scalar type of val
 * @tparam T1 type of elements inside tensor
 * @tparam ArgsT1 indices of the tensor
 * @param val scalar value
 * @param tensor tensor object
 * @return the same tensor, but all elements where multiplicated with an value val
 */
template<typename Scalar, typename T1, typename ArgsT1> requires isFundamental<Scalar> && isTensor<tensorBase_ranges<T1, ArgsT1>>
constexpr auto contraction_ranges(tensorBase_ranges<T1, ArgsT1> tensor, Scalar val){

    static_assert((tensorBase_ranges<T1, ArgsT1>::indices_amount >= 1), "1 OR MORE INDICES ARE NEEDED");
        if constexpr ((tensorBase_ranges<T1, ArgsT1>::indices_amount >= 1)) {
            auto copyTensor = tensor;
            copyTensor.data = copyTensor.data | ranges::views::transform([=](auto i){return i * val;})| ranges::to<std::vector>();

            return copyTensor;
        }
}

#endif //UNTITELED1_CONTRACTION_RANGES_H
