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
#include "cartesian_product_ranges.h"
#include <range/v3/range/conversion.hpp>

template<typename T1>
constexpr auto trace_ranges(T1 tensor1){

    auto cp = cartesian_product_ranges<3,2>();
    auto mynewrange = ranges::views::all(tensor1.data) | ranges::views::enumerate;
    auto rnd = mynewrange | ranges::views::stride(3) | ranges::views::enumerate | ranges::to<std::vector>();

    return cp;
}

#endif //UNTITELED1_TRACE_RANGES_H
