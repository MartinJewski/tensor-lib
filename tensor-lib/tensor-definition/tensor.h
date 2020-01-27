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

template<typename T, typename Args>
class tensorBase{

    public:
        std::array<T, positive_natural_compiletime_pow<DIM3, std::tuple_size<Args>::value>()> data;

        Args myTypeTup;

        std::size_t indices_amount =  std::tuple_size<Args>::value;


    template<typename ... Element>
    constexpr tensorBase(Element&&... input) : data{input...} {};

    /* copy constructor */
    template<typename Tensor>
    constexpr tensorBase(const Tensor &oldObj){

        data = oldObj.data;

        myTypeTup = oldObj.myTypeTup;

        indices_amount = oldObj.indices_amount;

    }

    constexpr auto calculate_indices() const{

        static_assert((std::tuple_size<Args>::value <= 5), "tensor has to many indices");
        return cartesian_product<DIM3, std::tuple_size<Args>::value>();
    };

};

template<typename T, typename ... Args>
using tensor = tensorBase<T, std::tuple<Args...>>;


#endif //UNTITELED1_TENSOR_H
