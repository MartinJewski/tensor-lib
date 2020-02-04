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
class tensorBase_rt{

public:
    std::array<T, positive_natural_compiletime_pow<DIM3, std::tuple_size<Args>::value>()> data;

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
using tensor_rt = tensorBase_rt<T, std::tuple<Args...>>;




template<typename T, typename Args>
class tensorBase{

    public:
        std::array<T, positive_natural_compiletime_pow<DIM3, std::tuple_size<Args>::value>()> data;

        Args myTypeTup;

        static constexpr std::size_t indices_amount =  std::tuple_size<Args>::value;

    template<typename ... Element>
    constexpr tensorBase(Element&&... input) : data{input...} {};

    /* copy constructor */
    template<typename Tensor>
    constexpr tensorBase(const Tensor &oldObj){
        data = oldObj.data;

        myTypeTup = oldObj.myTypeTup;

        indices_amount = oldObj.indices_amount;
    };

    constexpr auto calculate_indices() const{

        static_assert((std::tuple_size<Args>::value <= 5), "tensor has to many indices");
        return cartesian_product<DIM3, std::tuple_size<Args>::value>();
    };


    constexpr auto to_runtime_tensor() const{

        tensorBase_rt<T, Args> temp_tensor(static_cast<T>(0));
        temp_tensor.data = data;

        return temp_tensor;
    }

};

template<typename T, typename ... Args>
using tensor = tensorBase<T, std::tuple<Args...>>;



#endif //UNTITELED1_TENSOR_H
