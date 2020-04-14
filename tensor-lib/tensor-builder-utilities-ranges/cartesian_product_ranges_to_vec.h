//
// Created by martin machajewski on 02.01.20.
//

#ifndef UNTITELED1_CARTESIAN_PRODUCT_RANGES_TO_VEC_H
#define UNTITELED1_CARTESIAN_PRODUCT_RANGES_TO_VEC_H

#include <range/v3/view/indices.hpp>
#include <range/v3/view/cartesian_product.hpp>
#include <range/v3/range/conversion.hpp>

//pack expansion


/**
 * Calculates the cartesian product and puts it into an vector
 * @tparam length indices length (e.g length 5 -> 0,1,2,3,4)
 * @tparam is index sequence of length N
 * @return cartesian product inside a vector
 */
template<std::size_t length, std::size_t... is>
constexpr auto cartesian_product_v(std::index_sequence<is...>) {
    const auto cart_input1 = ranges::view::indices(length);
    return ranges::view::cartesian_product((is, cart_input1)...) | ranges::to<std::vector>();
}

/**
 * Calculates the indices and returns it inside a vector
 * @tparam length indices length (e.g length 5 -> 0,1,2,3,4)
 * @tparam N how many sets of "length" indices
 * @return cartesian product inside a vector
 */
template<std::size_t length, std::size_t N>
constexpr auto cartesian_product_ranges_to_vec(){
    return cartesian_product_v<length>(std::make_index_sequence<N>{});
}

#endif //UNTITELED1_CARTESIAN_PRODUCT_RANGES_TO_VEC_H
