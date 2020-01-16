//
// Created by martin on 10.12.19.
//

#ifndef UNTITELED1_CARTESIAN_PRODUCT_H
#define UNTITELED1_CARTESIAN_PRODUCT_H

#include <range/v3/view/indices.hpp>
#include <range/v3/view/cartesian_product.hpp>
#include <range/v3/range/conversion.hpp>

#include <tuple>

#include "tuple_show.h"


template<std::size_t length, std::size_t... is>
constexpr auto cartesian_product_inner(std::index_sequence<is...>) {
    const auto cart_input1 = ranges::view::indices(length);
    return ranges::view::cartesian_product((is, cart_input1)...);
}

template<std::size_t length, std::size_t N>
constexpr auto cartesian_product(){
    return cartesian_product_inner<length>(std::make_index_sequence<N>{});
}

//------------------------------------------------------------------------

template<std::size_t range, std::size_t ...is>
constexpr auto cartesian_product_new_ii(std::index_sequence<is...>){

    std::array<std::size_t, range> arr = {(is)...};
    return arr;

}

template<std::size_t range, std::size_t sets, std::size_t ...is>
constexpr auto cartesian_product_new_i(std::index_sequence<is...>){

    std::array<decltype(cartesian_product_new_ii<range>(std::make_index_sequence<range>{})), sets>
    arr = {(is, cartesian_product_new_ii<range>(std::make_index_sequence<range>{}))...};



    return arr;
}

template<std::size_t range, std::size_t sets>
constexpr auto cartesian_product_new(){

    return cartesian_product_new_i<range, sets>(std::make_index_sequence<sets>{});

}


//--------------------------------------------------

template<std::size_t depth, typename T, std::size_t ...is>
constexpr auto wdh(T&& tuple, std::index_sequence<is...>){

    if constexpr (depth == 0) {
        return tuple;
    }else{
        return std::make_tuple(wdh<depth-1>(std::tuple_cat(tuple, std::make_tuple(is)),std::make_index_sequence<sizeof...(is)>{})...);
    }

}


template<std::size_t sets, std::size_t ...is>
constexpr auto ct_i(std::index_sequence<is...>){

    //0 -> 0 1 2
    //1 -> 0 0  0 1  0 2   1 0  1 1  1 2   2 0  2 1  2 2
    return std::make_tuple(wdh<sets>(std::make_tuple(is), std::make_index_sequence<sizeof...(is)>{})...);

}

template<std::size_t range, std::size_t sets>
constexpr auto ct(){

    return ct_i<sets>(std::make_index_sequence<range+1>{});

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
