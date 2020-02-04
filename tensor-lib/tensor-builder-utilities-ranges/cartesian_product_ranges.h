//
// Created by martin on 03.02.20.
//

#ifndef UNTITELED1_CARTESIAN_PRODUCT_RANGES_H
#define UNTITELED1_CARTESIAN_PRODUCT_RANGES_H

#include <range/v3/view/indices.hpp>
#include <range/v3/view/cartesian_product.hpp>
#include <range/v3/range/conversion.hpp>

#include "positive_natural_compiletime_pow.h"
#include <tuple>

#include "tuple_show.h"


template<std::size_t length, std::size_t... is>
constexpr auto cartesian_product_ranges_inner(std::index_sequence<is...>) {
    const auto cart_input1 = ranges::view::indices(length);
    return ranges::view::cartesian_product((is, cart_input1)...);
}

template<std::size_t length, std::size_t sets>
constexpr auto cartesian_product_ranges(){
    return cartesian_product_ranges_inner<length>(std::make_index_sequence<sets>{});
}



#endif //UNTITELED1_CARTESIAN_PRODUCT_RANGES_H