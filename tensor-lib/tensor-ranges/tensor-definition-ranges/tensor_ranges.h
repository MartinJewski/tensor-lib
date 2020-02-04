//
// Created by martin on 03.01.20.
//

#ifndef UNTITELED1_TENSOR_H
#define UNTITELED1_TENSOR_H

#include <cmath>
#include <vector>
#include <tuple>
#include "tensor_specification.h"
#include <array>
#include "positive_natural_compiletime_pow.h"
#include "cartesian_product.h"
#include <type_traits>

#include <range/v3/view/all.hpp>
#include <range/v3/view/enumerate.hpp>



template<typename T, typename Args>
class tensorBase_ranges{

public:
    std::vector<T>()> data;

    using tuple_indices = Args;
    using elem_type = T;

    static constexpr std::size_t indices_amount =  std::tuple_size<Args>::value;


    template<typename ... Element>
    constexpr tensorBase_rt(Element&&... input) : data{input...} {};

    /* copy constructor */

    template<typename Element>
    constexpr tensorBase_rt(Element &oldObj){
        this->data = oldObj.data;
    };

    constexpr auto calculate_indices() const{

        static_assert((std::tuple_size<Args>::value <= 5), "tensor has to many indices");
        return cartesian_product<DIM3, std::tuple_size<Args>::value>();
    };

    constexpr auto data_to_range() const{
        return ranges::views::all(this->data) | ranges::views::enumerate;
    }
};

template<typename T, typename ... Args>
using tensorR = tensorBase_ranges<T, std::tuple<Args...>>;



#endif //UNTITELED1_TENSOR_H
