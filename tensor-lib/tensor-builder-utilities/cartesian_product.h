//
// Created by martin machajewski on 10.12.19.
//

#ifndef UNTITELED1_CARTESIAN_PRODUCT_H
#define UNTITELED1_CARTESIAN_PRODUCT_H



#include <tuple>
#include "tuple_show.h"


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
        auto t = (std::make_tuple(std::get<is>(tuple)),...);
        std::array<decltype(t), sizeof...(is)> arr = {std::make_tuple(std::get<is>(tuple))...};
        //decltype(arr)::foo = 1;
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

}

template<std::size_t range, std::size_t sets>
constexpr auto cartesian_product(){

    static_assert( (range > 0), "lowest input must be cartesian<1,1>" );
    static_assert( (sets > 0), "lowest input must be cartesian<1,1>" );
    return ct_i<sets-1>(std::make_index_sequence<range>{});
}



#endif //UNTITELED1_CARTESIAN_PRODUCT_H
