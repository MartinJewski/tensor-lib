//
// Created by martin machajewski on 28.03.20.
//

#ifndef UNTITELED1_TRACE_CONTRACTION_RANGES_H
#define UNTITELED1_TRACE_CONTRACTION_RANGES_H


#include "tensor.h"
#include "trace_ranges.h"
#include "recreate_for_index_sequence.h"
#include <tuple>
#include <range/v3/view/transform.hpp>


template<std::size_t indices1, typename F, typename T, typename Args,
        typename Tuple1, std::size_t ...is>
constexpr auto calculate_value_i_trace(tensorBase_ranges<T, Args> T1, Tuple1 tup1, std::index_sequence<is...>){

    F add = 0.0;
    ((add += (T1.data[(pos_nd_to_1d_tuple<indices1>(std::get<is>(tup1)))])),...);
    return add;
}



template<std::size_t pos1, std::size_t pos2, typename T, typename Args>
constexpr auto trace_contraction_ranges(tensorBase_ranges<T, Args> tensor){

    static_assert((tensor.indices_amount > 1), "You need at least 2 indices!");
    using skip_type_t1 = tuple_type_list<Args>::template type<pos1>;
    using skip_type_t2 = tuple_type_list<Args>::template type<pos2>;
    static_assert((std::is_same<skip_type_t1, skip_type_t2>::value == false), "Cannot contract over the same index level."
                                                              "E.g contraction over two up_t indices is not possible!");


    if constexpr (tensor.indices_amount == 2){
        return trace_ranges(tensor);
    }else {
        using contracted_types = remove_ith_jth_concat_tuple<pos1, pos2, typename decltype(tensor)::tuple_indices>::type;

        tensorBase_ranges<typename decltype(tensor)::elem_type,
                contracted_types>
                result_tensor3(static_cast<typename decltype(tensor)::elem_type>(0));

        auto tensor_data = result_tensor3.calculate_indices()
                           | ranges::views::transform([=](auto&& tuple)
                                                      {return recreate_for_index_sequence<pos1, pos2,
                                                              tensor.indices_amount ,dim_length_n>(tuple);})
                            | ranges::views::transform([=](auto tuple){
                                return calculate_value_i_trace
                                        <tensor.indices_amount, typename decltype(tensor)::elem_type>
                                        (tensor, tuple,std::make_index_sequence<dim_length_n>{}); })
                            |ranges::to<std::vector>();

        result_tensor3.data = tensor_data;
        return result_tensor3;
    }
}

#endif //UNTITELED1_TRACE_CONTRACTION_RANGES_H
