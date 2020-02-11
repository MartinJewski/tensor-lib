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

template<std::size_t skipPos1, std::size_t skipPos2, typename T1, typename ...Args1, typename T2, typename ...Args2>
constexpr auto contraction_ranges(tensorRange<T1, Args1...> tensor1, tensorRange<T2, Args2...> tensor2){

    remove_ith_concat_tuple<skipPos1, skipPos2,
         typename decltype(tensor1)::tuple_indices, typename decltype(tensor2)::tuple_indices> tensor3_types;

    tensorBase_ranges<std::common_type_t<typename decltype(tensor1)::elem_type, typename decltype(tensor2)::elem_type>,
          typename decltype(tensor3_types)::type> tr(0);

    auto sris2 = tr.calculate_indices()
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
                                                    (tensor1, tensor2, std::get<0>(tuple), std::get<1>(tuple), std::make_index_sequence<DIM3>{});});


    std::cout << sris2 << std::endl;


    return 0;
}

#endif //UNTITELED1_CONTRACTION_RANGES_H
