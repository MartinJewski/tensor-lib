//
// Created by martin on 03.01.20.
//

#ifndef UNTITELED1_TENSOR_H
#define UNTITELED1_TENSOR_H

#include <vector>
#include <tuple>
#include "tensor_specification.h"
#include <array>
#include "compiletime_pow.h"

template<typename T, typename ... Args>
class tensorBase{

    private:

    std::array<T, compiletime_pow<DIM3, sizeof...(Args)+1>()> myarray;
    public:

    std::tuple<Args...> myTypeTup;

    using indices_tup = std::tuple<Args...>;

    const std::size_t indices_amount = sizeof...(Args);

    template<typename ... Element>
    constexpr tensorBase(Element&&... input) : myarray{input...} {};

    constexpr auto calculate_indices(){
        return cartesian_product_to_vec<DIM3, sizeof...(Args)>();
    };

};

template<typename T, typename ... Args>
using tensor = tensorBase<T, std::tuple<Args...>>;


#endif //UNTITELED1_TENSOR_H
