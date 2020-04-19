//
// Created by martin machajewski on 27.03.20.
//

#ifndef UNTITELED1_TRACE_CONTRACTION_CT_H
#define UNTITELED1_TRACE_CONTRACTION_CT_H

#include <array>
#include "pos_nd_to_1d.h"
#include "tensor.h"
#include "trace_ct.h"


template<typename T, typename U, typename Arr, std::size_t ...is>
constexpr auto create_result_tensor_trace_ct(Arr array, std::index_sequence<is...>){

    tensorBase<T, U> arr(static_cast<T>(array[is])...);

    return arr;
}


template<std::size_t indices1, typename F, tensorBase T1,
        typename Tuple1, std::size_t ...is>
constexpr auto calculate_value_i_trace_ct(Tuple1 tup1, std::index_sequence<is...>){

    F add = 0.0;
    ((add += (T1.data[(pos_nd_to_1d_tuple<indices1>(std::get<is>(tup1)))])),...);
    return add;
}

//indices1 T1.indices_amount
template<std::size_t indices1, typename F, tensorBase T1, typename SRIST1, std::size_t ...is>
constexpr auto calculate_value_trace_ct(SRIST1 sris1, std::index_sequence<is...>){

    auto temp = (calculate_value_i_trace_ct<indices1, F, T1>(sris1[is], std::make_index_sequence<dim_length_n>{}),...);

    std::array<decltype(temp), sris1.size()>
            arr{calculate_value_i_trace_ct<indices1, F, T1>(sris1[is], std::make_index_sequence<dim_length_n>{})...};

    return arr;
}


template<tensorBase T1, std::size_t pos1, std::size_t pos2>
constexpr auto trace_contraction_i_ct(){

    static_assert((T1.indices_amount > 1), "You need at least 2 indices!");
    using skip_type_t1 = tuple_type_list<typename decltype(T1)::tuple_indices>::template type<pos1>;
    using skip_type_t2 = tuple_type_list<typename decltype(T1)::tuple_indices>::template type<pos2>;
    static_assert((std::is_same<skip_type_t1, skip_type_t2>::value == false), "Cannot contract over the same index level."
                                                                             "E.g contraction over two up_t indices is not possible!");

    if constexpr (T1.indices_amount == 2){
        return trace<T1>();
    }else {
        using contracted_types = remove_ith_jth_concat_tuple<pos1, pos2, typename decltype(T1)::tuple_indices>::type;

        constexpr tensor<typename decltype(T1)::elem_type, contracted_types> tensor3;

        auto sris_tensor1 = save_recreated_index_sequence<pos1, pos2, T1.indices_amount, dim_length_n>
                (tensor3.static_calculate_indices());

        //does the multiplication over the indices
        auto result = calculate_value_trace_ct<T1.indices_amount, typename decltype(T1)::elem_type,
                T1>(sris_tensor1, std::make_index_sequence<sris_tensor1.size()>{});

        //creates the final tensor
        auto final_result = create_result_tensor_trace_ct
                <typename decltype(T1)::elem_type,
                        contracted_types>(result, std::make_index_sequence<result.size()>{});

        return final_result;
    }
}

template<tensorBase T1, std::size_t pos1, std::size_t pos2>
constexpr auto trace_contraction(){

    return trace_contraction_i_ct<T1, pos1, pos2>();

}


#endif //UNTITELED1_TRACE_CONTRACTION_CT_H
