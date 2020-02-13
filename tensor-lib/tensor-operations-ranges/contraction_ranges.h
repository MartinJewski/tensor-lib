//
// Created by martin on 04.02.20.
//

#ifndef UNTITELED1_CONTRACTION_RANGES_H
#define UNTITELED1_CONTRACTION_RANGES_H

#include "tensor_range.h"
#include "tuple_helpers.h"
#include <type_traits>
#include <tuple>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/transform.hpp>
#include "recreate_for_index_sequence.h"
#include "contraction.h"

template<std::size_t skipPos1, std::size_t skipPos2, typename T1, typename Args1, typename T2, typename Args2>
constexpr auto contraction_ranges(tensorBase_ranges<T1, Args1> tensor1, tensorBase_ranges<T2, Args2> tensor2){

    remove_ith_concat_tuple<skipPos1, skipPos2,
         typename decltype(tensor1)::tuple_indices, typename decltype(tensor2)::tuple_indices> tensor3_types;

    tensorBase_ranges<std::common_type_t<typename decltype(tensor1)::elem_type, typename decltype(tensor2)::elem_type>,
          typename decltype(tensor3_types)::type> tensor3(0);

    if constexpr ((tensorBase_ranges<T1, Args1>::indices_amount == 1) && (tensorBase_ranges<T2, Args2>::indices_amount == 1)) {

        auto local_val = ranges::accumulate(tensor1.data_to_range_positions1D()
                                | ranges::views::transform([=](auto tuple){ return std::get<1>(tuple) *
                                                                                    tensor2.data[std::get<0>(tuple)];}), 0);
        return local_val;
    }

    if constexpr (((tensorBase_rt<T1, Args1>::indices_amount == 1) && (tensorBase_rt<T2, Args2>::indices_amount > 1)) ||
                  ((tensorBase_rt<T1, Args1>::indices_amount > 1) && (tensorBase_rt<T2, Args2>::indices_amount == 1)) ||
                  ((tensorBase_rt<T1, Args1>::indices_amount > 1) && (tensorBase_rt<T2, Args2>::indices_amount > 1))) {

        auto sris = tensor3.calculate_indices()
                    | ranges::views::transform([tensor1, tensor2](auto tuple)
                                               {return std::make_tuple(
                                                       recreate_for_index_sequence
                                                               <0, decltype(tensor1)::indices_amount - 1, skipPos1, decltype(tensor1)::indices_amount, DIM3>(tuple),

                                                       recreate_for_index_sequence
                                                               <decltype(tensor1)::indices_amount - 1, decltype(tensor2)::indices_amount - 1, skipPos2,
                                                                       decltype(tensor1)::indices_amount, DIM3>(tuple));})
                    | ranges::views::transform([tensor1, tensor2](auto tuple){return
                calculate_value_i<
                        decltype(tensor1)::indices_amount,
                        decltype(tensor2)::indices_amount,
                        std::common_type_t<typename decltype(tensor1)::elem_type, typename decltype(tensor2)::elem_type>>
                        (tensor1, tensor2, std::get<0>(tuple), std::get<1>(tuple), std::make_index_sequence<DIM3>{});})
                    | ranges::to<std::vector>();

        tensor3.data = sris;
        return tensor3;
    }
}

template<typename Scalar, typename T1, typename ArgsT1> requires isFundamental<Scalar> && isTensor<tensorBase_ranges<T1, ArgsT1>>
constexpr auto contraction_ranges(Scalar val, tensorBase_ranges<T1, ArgsT1> tensor){

    static_assert((tensorBase_ranges<T1, ArgsT1>::indices_amount >= 1), "1 OR MORE INDICES ARE NEEDED");
        if constexpr ((tensorBase_ranges<T1, ArgsT1>::indices_amount >= 1)) {
            auto copyTensor = tensor;
            copyTensor.data = copyTensor.data | ranges::views::transform([=](auto i){return i * val;})| ranges::to<std::vector>();

            return copyTensor;
        }
}

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
