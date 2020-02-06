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


#include "cartesian_product_ranges.h"

#include <range/v3/range/conversion.hpp>

#include <tuple>

auto fun_rule = [](auto i) -> int {
    return 3;
};

template<typename T1>
constexpr auto trace_ranges(T1 tensor1){

    std::vector<int> myvector = {1,2,3,4,5,6,7,8};
    auto myvec_range = ranges::views::all(myvector);

    auto start = tensor1.data_to_range();
    auto indices = tensor1.calculate_indices() | ranges::to<std::vector>();

   for ( auto i : start
            | ranges::views::transform([=](auto d){return std::make_tuple(indices[std::get<0>(d)], std::get<1>(d));})
            | ranges::to<std::vector>())
    { }

   auto l = start
           | ranges::views::transform([=](auto d){return std::make_tuple(indices[std::get<0>(d)], std::get<1>(d));})
           | ranges::to<std::vector>();


   auto e = ranges::views::all(tensor1.data)
           | ranges::views::enumerate
           | ranges::views::transform([=](auto d){return std::make_tuple(indices[std::get<0>(d)], std::get<1>(d));});

   std::cout << e << std::endl;

    return start;
}

#endif //UNTITELED1_TRACE_RANGES_H
