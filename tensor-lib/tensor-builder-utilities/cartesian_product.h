//
// Created by martin on 10.12.19.
//

#ifndef UNTITELED1_CARTESIAN_PRODUCT_H
#define UNTITELED1_CARTESIAN_PRODUCT_H

#include <range/v3/view/indices.hpp>
#include <range/v3/view/cartesian_product.hpp>
#include <range/v3/range/conversion.hpp>



template<std::size_t length, std::size_t... is>
constexpr auto cartesian_product(std::index_sequence<is...>) {
    const auto cart_input1 = ranges::view::indices(length);
    return ranges::view::cartesian_product((is, cart_input1)...);
}

template<std::size_t length, std::size_t N>
constexpr auto cartesian_product(){
    return cartesian_product<length>(std::make_index_sequence<N>{});
}



#endif //UNTITELED1_CARTESIAN_PRODUCT_H


//--------------------------------------------------
//CARTESIAN PRODUCT
//MAIN EXAMPLE CODE
/*
constexpr auto cart2 = tensor_cartesian_product<4, 2>(); //cartesian product using two sets, which range from 0 to 3 (4 elements).
constexpr const auto cart4 = tensor_cartesian_product<4, 4>(); //cartesian product using four sets, which range from 0 to 3 (4 elements).
constexpr const auto cart10 = tensor_cartesian_product<4, 10>(); //cartesian product using ten sets, which range from 0 to 3 (4 elements).


std::cout << "----------2D--------------" << std::endl;
range_of_nonviewable_container_show(cart2);
std::cout << "----------4D--------------" << std::endl;
range_of_nonviewable_container_show(cart4);

//std::cout << "----------10D--------------" << std::endl;
//range_of_nonviewable_container_show(cart10);
//std::cout << "-------------------------" << std::endl;
 */
//--------------------------------------------------
