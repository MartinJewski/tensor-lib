//
// Created by martin on 03.01.20.
//

#ifndef UNTITELED1_TENSOR_H
#define UNTITELED1_TENSOR_H

#include <iostream>

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

template <typename T, typename ...Ts>
using areT = std::conjunction<std::is_same<T,Ts>...>;

class tensorFundamental{};

template<typename T, typename Args>
class tensorBase_rt : tensorFundamental{

public:
    std::array<T, positive_natural_compiletime_pow<DIM3, std::tuple_size<Args>::value>()> data;

    using tuple_indices = Args;
    using elem_type = T;

    static constexpr std::size_t indices_amount =  std::tuple_size<Args>::value;


    template<typename ... Element>
    constexpr tensorBase_rt(Element&&... input) : data{input...} {
        static_assert(areT<T, Element...>::value , "VALUES INPUT TYPE DOESN'T MATCH TEMPLATE TYPE");
    };

    template<typename Ti, std::size_t val>
    constexpr tensorBase_rt(std::array<Ti, val> input) : data(input){
        static_assert(areT<T, Ti>::value , "ARRAY TYPE DOESN'T MATCH TEMPLATE TYPE");
    };

    constexpr tensorBase_rt(const tensorBase_rt &oldObj) = default;
    constexpr tensorBase_rt(tensorBase_rt &oldObj) = default;

    template<typename Ti, typename Argsi>
    constexpr tensorBase_rt(const tensorBase_rt<Ti, Argsi> &oldObj){
        data = oldObj.data;
    };

    template<typename Ti, typename Argsi>
    constexpr tensorBase_rt(tensorBase_rt<Ti, Argsi>& oldObj){
        data = oldObj.data;
    };

    /* move constructor */
    template<typename Ti, typename Argsi>
    constexpr tensorBase_rt(tensorBase_rt<Ti, Argsi>&& oldObj){
        data = oldObj.data;
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
class tensorBase : tensorFundamental{

    public:
        std::array<T, positive_natural_compiletime_pow<DIM3, std::tuple_size<Args>::value>()> data;

        using tuple_indices = Args;
        using elem_type = T;

        static constexpr std::size_t indices_amount =  std::tuple_size<Args>::value;

    template<typename ... Element>
    constexpr tensorBase(Element&&... input) : data{input...} {
        static_assert(areT<T, Element...>::value , "VALUES INPUT TYPE DOESN'T MATCH TEMPLATE TYPE");
    };

    template<typename Ti, std::size_t val>
    constexpr tensorBase(std::array<Ti, val> input) : data(input){
        static_assert(areT<T, Ti>::value , "ARRAY TYPE DOESN'T MATCH TEMPLATE TYPE");
    };

    template<typename Ti, typename Argsi>
    constexpr tensorBase(const tensorBase<Ti, Argsi> &oldObj){
        data = oldObj.data;
    };

    template<typename Ti, typename Argsi>
    constexpr tensorBase(tensorBase<Ti, Argsi> &oldObj){
        data = oldObj.data;
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




template<typename Ti, typename Argsi>
std::ostream& operator<<(std::ostream& os, const tensorBase_rt<Ti, Argsi>& tsr)
{
    for(int i = 0; i < tsr.data.size(); i++){

        std::cout << " " << tsr.data[i] << " ";
    }
    std::cout << " " << std::endl;
    return os;
}

template<typename Ti, typename Argsi>
std::ostream& operator<<(std::ostream& os, const tensorBase<Ti, Argsi>& tsr)
{
    for(int i = 0; i < tsr.data.size(); i++){

        std::cout << " " << tsr.data[i] << " ";
    }
    std::cout << " " << std::endl;
    return os;
}





template<typename I, std::size_t val>
class myClass{

    public:
        std::array<I, val> data;

    template<typename ...T>
    constexpr myClass(T&& ... elem) : data{elem...}{};

    constexpr myClass(const myClass &mObj) = default;
    constexpr myClass(myClass &mObj) = default;
    /*
    template<typename T, std::size_t value>
    constexpr myClass(const myClass<T, value> &mObj){
        data = mObj.data;
    }

    template<typename T, std::size_t value>
    constexpr myClass(myClass<T, value> &mObj){
        data = mObj.data;
    }
*/
};

struct myStruct{
    myClass<int, 5> aC{1,2,3,4,5};
};

template<typename I, std::size_t val>
constexpr auto myfunction(myClass<I, val> obj){
    int a = obj.data[0];
    return a;
}






#endif //UNTITELED1_TENSOR_H


