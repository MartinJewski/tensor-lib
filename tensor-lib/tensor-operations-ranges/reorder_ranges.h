//
// Created by martin on 04.02.20.
//

#ifndef UNTITELED1_REORDER_RANGES_H
#define UNTITELED1_REORDER_RANGES_H

#include "reorder.h"
#include <range/v3/view/transform.hpp>
#include <range/v3/view/map.hpp>
#include "pos_nd_to_1d.h"
#include "tensor_range.h"
#include <utility>



template<std::size_t ...positions, typename T>
constexpr auto reorder_ranges(T tensor){

    auto reordered = tensor.data_to_range_positionsND()
            | ranges::views::transform([tensor](auto tuple){ return std::make_pair(std::get<0>(tuple), tensor.data[
                    static_cast<typename decltype(tensor)::elem_type>(calculate_new<positions...>
                            (pos_nd_to_1d_tuple<sizeof...(positions)>(std::get<0>(tuple)), std::get<0>(tuple)))]);
            })
            | ranges::views::values
            | ranges::to<std::vector>();

    tensorRange<T::elem_type, T::tuple_indices> tensor2(reordered);

    return tensor2;
}


#endif //UNTITELED1_REORDER_RANGES_H
