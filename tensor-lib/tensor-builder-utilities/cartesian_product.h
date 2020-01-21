//
// Created by martin on 10.12.19.
//

#ifndef UNTITELED1_CARTESIAN_PRODUCT_H
#define UNTITELED1_CARTESIAN_PRODUCT_H

#include <range/v3/view/indices.hpp>
#include <range/v3/view/cartesian_product.hpp>
#include <range/v3/range/conversion.hpp>

#include "positive_natural_compiletime_pow.h"
#include <tuple>

#include "tuple_show.h"

/*
 * cartesian product using the ranges library
 *
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
constexpr auto cartesian_product_ranges(){

    return cartesian_product_new_i<range, sets>(std::make_index_sequence<sets>{});

}
*/

//--------------------------------------------------

template<typename T, std::size_t ...is>
constexpr auto flatten_tuple_i(T tuple, std::index_sequence<is...>) {

    return std::tuple_cat(std::get<is>(tuple)...);

}

template<typename T>
constexpr auto flatten_tuple(T tuple) {
    return flatten_tuple_i(tuple, std::make_index_sequence<std::tuple_size<T>::value>{});
}

template<std::size_t depth, typename T>
constexpr auto recursive_flatten_tuple(T tuple){

    if constexpr(depth <= 1){
        return tuple;
    }else{
        return recursive_flatten_tuple<depth-1>(flatten_tuple(tuple));
    }

}

template<std::size_t depth, typename T, std::size_t ...is>
constexpr auto wdh(T&& tuple, std::index_sequence<is...>){

    if constexpr (depth == 0) {
        return tuple;
    }else{
        //return (wdh<depth-1>(std::tuple_cat(tuple, std::make_tuple(is)),std::make_index_sequence<sizeof...(is)>{})...);
        return std::make_tuple(wdh<depth-1>(std::tuple_cat(tuple, std::make_tuple(is)), std::make_index_sequence<sizeof...(is)>{})...);
    }
}

template<std::size_t sets, typename T, std::size_t ...is>
constexpr auto to_array(T tuple, std::index_sequence<is...>){

    if constexpr (sets == 0){
        std::array<T, 1> arr = {tuple};
        return arr;
    }else{
        auto t = ((std::get<is>(tuple)),...);
        std::array<decltype(t), sizeof...(is)> arr = {std::get<is>(tuple)...};
        return arr;
    }
}

template<std::size_t sets, std::size_t ...is>
constexpr auto ct_i(std::index_sequence<is...>){

    if constexpr (sets == 0){
        auto u = std::tuple_cat(wdh<sets>(std::make_tuple(is), std::make_index_sequence<sizeof...(is)>{})...);
        auto arr = to_array<sets>(u, std::make_index_sequence<std::tuple_size<decltype(u)>::value>{});

        return arr;
    }else {


        auto u = std::tuple_cat(wdh<sets>(std::make_tuple(is), std::make_index_sequence<sizeof...(is)>{})...);

        auto r = recursive_flatten_tuple<sets>(u);

        auto d = to_array<sets>(r, std::make_index_sequence<std::tuple_size<decltype(r)>::value>{});

        //decltype(d)::foo = 1;

        return d;
    }
    //return std::make_tuple(wdh<sets>(std::make_tuple(is), std::make_index_sequence<sizeof...(is)>{})...);
}

template<std::size_t range, std::size_t sets>
constexpr auto cartesian_product(){

    static_assert( (range > 0), "lowest input is be cartesian<1,1>" );
    static_assert( (sets > 0), "lowest input is be cartesian<1,1>" );
    return ct_i<sets-1>(std::make_index_sequence<range>{});
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
