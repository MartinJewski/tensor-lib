//
// Created by martin on 03.01.20.
//

#ifndef UNTITELED1_TENSOR_H
#define UNTITELED1_TENSOR_H

#include <vector>
#include <tuple>
#include "tensor_specification.h"
#include <array>
#include "positive_natural_compiletime_pow.h"
#include "cartesian_product.h"

template<typename T, typename ... Args>
class tensorBase{

    private:
        std::array<T, positive_natural_compiletime_pow<DIM3, sizeof...(Args)+1>()> data;

    public:
        //std::vector<T> data = {};

        std::tuple<Args...> myTypeTup;

        using indices_tup = std::tuple<Args...>;

        const std::size_t indices_amount = sizeof...(Args);

    template<typename ... Element>
    constexpr tensorBase(Element&&... input) : data{input...} {};

    template<typename Arr>
    constexpr tensorBase(Arr&& array) {
        data = array;
    };

    constexpr auto calculate_indices(){

        return cartesian_product<DIM3, sizeof...(Args)>();
        //return cartesian_product_to_vec<DIM3, sizeof...(Args)+1>();
    };

    template<typename D>
    constexpr auto get_element(D&& val){
        return data[val];
    };

};

template<typename T, typename ... Args>
using tensor = tensorBase<T, std::tuple<Args...>>;


#endif //UNTITELED1_TENSOR_H
