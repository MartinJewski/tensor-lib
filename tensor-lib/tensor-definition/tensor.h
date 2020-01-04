//
// Created by martin on 03.01.20.
//

#ifndef UNTITELED1_TENSOR_H
#define UNTITELED1_TENSOR_H

#include <vector>
#include <tuple>
#include "tensor_specification.h"

template<typename T, typename ... Args>
class tensorBase{

    private:

    std::vector<T> elements = {};

    public:

    using type = std::tuple<Args...>;
    std::size_t indices_amount = sizeof...(Args);

    template<typename ... Element>
    constexpr tensorBase(Element&&... input) : elements{input...} {};

    constexpr auto calculate_indices(){
        return cartesian_product_to_vec<DIM3, sizeof...(Args)>();
    };

};

template<typename T, typename ... Args>
using tensor = tensorBase<T, std::tuple<Args...>>;


#endif //UNTITELED1_TENSOR_H
