//
// Created by martin machajewski on 04.02.20.
//

#ifndef UNTITELED1_REORDER_RANGES_H
#define UNTITELED1_REORDER_RANGES_H

#include "reorder.h"
#include "tuple_type_list.h"
#include <range/v3/view/transform.hpp>
#include <range/v3/view/map.hpp>
#include "pos_nd_to_1d.h"
#include "tensor_range.h"
#include <utility>


/**
 * Reorders the indices, thus it reorders the elements inside the tensor.
 * The standart positioning of the indices is 0,1,2,3...,N
 * E.g The indices of the tensor tensorBase_ranges<double, up_t, up_t, low_t> are ordered with 0,1,2
 * And an reorderin would mean an switch of the indices order, like the following:
 * up_t,up_t, low_t order 0,1,2
 * do a reorder reorder
 * 2,1,0  => low_t, up_t, up_t
 * @tparam positions new positioning of the indices
 * @tparam T1 type of the elements inside the tensor
 * @tparam Args1 indices of the tensor
 * @param tensor tensor object
 * @return returns a new tensor of the same type with reordered indices
 */
template<std::size_t ...positions, typename T1, typename Args1>
constexpr auto reorder_ranges(tensorBase_ranges<T1, Args1> tensor){

    auto reordered = tensor.data_to_range_positionsND()
            | ranges::views::transform([tensor](auto tuple){
                return tensor.data[static_cast<typename decltype(tensor)::elem_type>(
                calculate_new<positions...>
                (pos_nd_to_1d_tuple<sizeof...(positions)>(std::get<0>(tuple)), std::get<0>(tuple)))]; })
            | ranges::to<std::vector>();

    using reorder_indices = std::tuple<typename
            tuple_type_list<typename decltype(tensor)::tuple_indices>::template type<positions>...>;

    tensorRange<typename decltype(tensor)::elem_type, reorder_indices> tensor2(reordered);

    return tensor2;
}


#endif //UNTITELED1_REORDER_RANGES_H
