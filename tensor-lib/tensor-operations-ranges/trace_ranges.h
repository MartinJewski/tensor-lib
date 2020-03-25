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

/**
 * Compares two values and determines if they are equal
 * @tparam is a value if size_t, only used to run on parameter packs
 * @tparam Val1 value type
 * @tparam Val2 value type
 * @param value1 value
 * @param value2
 * @return true if the values are equal, false if not
 */
template<std::size_t is, typename Val1, typename Val2>
constexpr auto checker(Val1 value1, Val2 value2){

    if(value1 != value2){
        return false;
    }else{
        return true;
    }
};
/**
 *  Checks if all elements are equal
 * @tparam T tuple type
 * @tparam is index sequence from 0 to ... N, where N is tuple size
 * @param tuple object
 * @return true if all elements are equal, false if not
 */
template<typename T, std::size_t ...is>
constexpr bool tuple_values_equal_i(T tuple, std::index_sequence<is...>){
    auto compare_tuple = std::get<0>(tuple);

    auto boolval = true;
    ((boolval = checker<is>(std::get<0>(compare_tuple), std::get<is>(compare_tuple))),...);

    return boolval;
}

/**
 * Runs the check function to check if all elements inside the tuple are equal
 * @tparam T tuple type
 * @param tuple object
 * @return if all elements are equal, it returns true, else fals
 */
template<typename T>
constexpr bool get_indices(T tuple){
    return tuple_values_equal_i(tuple, std::make_index_sequence<std::tuple_size<T>::value>{});
}

/**
 * Calculates the trace of a given range tensor
 * @tparam T1 type of the data inside the tensor
 * @tparam Args1 index positioning (e.g up_t, low_t)
 * @param tensor1 tensor object
 * @return trace
 */
template<typename T1, typename Args1>
constexpr auto trace_ranges(tensorBase_ranges<T1, Args1> tensor1){

    return ranges::accumulate(
            tensor1.data_to_range_positionsND()
                | ranges::view::remove_if([=](auto i) {if (get_indices(i) == false){return true;}else{return false;}})
                | ranges::view::transform([](auto i){return std::get<1>(i);})
                ,0);
}

#endif //UNTITELED1_TRACE_RANGES_H
