//
// Created by martin on 03.02.20.
//

#ifndef UNTITELED1_TRACE_RANGES_H
#define UNTITELED1_TRACE_RANGES_H

#include <range/v3/view/all.hpp>
#include <range/v3/view/replace_if.hpp>
#include <range/v3/view/zip.hpp>
#include <range/v3/view/stride.hpp>
#include <range/v3/view/enumerate.hpp>
#include <range/v3/view/transform.hpp>

#include <range/v3/view/for_each.hpp>
#include <range/v3/view/remove_if.hpp>
#include <range/v3/numeric/accumulate.hpp>

#include "cartesian_product_ranges.h"
#include "tensor_range.h"

#include <range/v3/range/conversion.hpp>

#include <tuple>

template<std::size_t is, typename Val1, typename Val2>
constexpr auto functiono(Val1 value1, Val2 value2){

    if(value1 != value2){
        return false;
    }else{
        return true;
    }
};

template<typename T, std::size_t ...is>
constexpr bool tuple_values_equal_i(T tuple, std::index_sequence<is...>){
    auto compare_tuple = std::get<0>(tuple);

    auto boolval = true;
    ((boolval = functiono<is>(std::get<0>(compare_tuple), std::get<is>(compare_tuple))),...);

    return boolval;
}

template<typename T>
constexpr bool get_indices(T tuple){
    return tuple_values_equal_i(tuple, std::make_index_sequence<std::tuple_size<T>::value>{});
}

template<typename T1>
constexpr auto trace_ranges(T1 tensor1){

    return ranges::accumulate(
            tensor1.data_to_range_positionsND()
                | ranges::view::remove_if([=](auto i) {if (get_indices(i) == false){return true;}else{return false;}})
                | ranges::view::transform([](auto i){return std::get<1>(i);})
                ,0);
}

#endif //UNTITELED1_TRACE_RANGES_H
