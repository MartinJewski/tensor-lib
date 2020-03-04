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

#include "random_number.h"

template <typename T, typename ...Ts>
using areT = std::conjunction<std::is_same<T,Ts>...>;

class tensorFundamental{};

template<typename T, typename Args>
class tensorBase_rt : tensorFundamental{
private:
    template<std::size_t ...is>
    static constexpr auto random_tensor_rt_i(int lowerBound, int upperBound, std::index_sequence<is...>){
        tensorBase_rt<T, Args> temp((is, random_number::rand_IntRange(lowerBound, upperBound))...);
        return temp;
    }

    template<std::size_t ...is>
    static constexpr auto random_tensor_rt_i(float lowerBound, float upperBound, std::index_sequence<is...>){
        tensorBase_rt<T, Args> temp((is, random_number::rand_FloatRange(lowerBound, upperBound))...);
        return temp;
    }

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

    static constexpr auto static_calculate_indices(){

        static_assert((std::tuple_size<Args>::value <= 5), "tensor has to many indices");
        return cartesian_product<DIM3, std::tuple_size<Args>::value>();

    };

    constexpr auto data_to_range() const{
        return ranges::views::all(this->data) | ranges::views::enumerate;
    }

    static constexpr tensorBase_rt<T, Args> random_tensor_rt(int lowerBound, int upperBound){
        return random_tensor_rt_i(lowerBound, upperBound,
                std::make_index_sequence<positive_natural_compiletime_pow<DIM3, std::tuple_size<Args>::value>()>{});
    }

    static constexpr tensorBase_rt<T, Args> random_tensor_rt(float lowerBound, float upperBound){
        return random_tensor_rt_i(lowerBound, upperBound,
                                  std::make_index_sequence<positive_natural_compiletime_pow<DIM3, std::tuple_size<Args>::value>()>{});
    }
};

template<typename T, typename ... Args>
using tensor_rt = tensorBase_rt<T, std::tuple<Args...>>;




template<typename T, typename Args>
class tensorBase : tensorFundamental{

    private:

        template<std::size_t ...is>
        static constexpr auto random_tensor_i(T lowerBound, T upperBound, std::index_sequence<is...>){

            tensorBase<T, Args> temp{(is, uniform_distribution<T>(lowerBound, upperBound))...};
            return temp;
        }

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

    static constexpr tensorBase<T, Args> random_tensor_ct(T lowerBound, T upperBound){
        return random_tensor_i(lowerBound, upperBound,
                                  std::make_index_sequence<positive_natural_compiletime_pow<DIM3, std::tuple_size<Args>::value>()>{});
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







#endif //UNTITELED1_TENSOR_H


