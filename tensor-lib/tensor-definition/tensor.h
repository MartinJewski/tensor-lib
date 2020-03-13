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

/**
 * checks if all types are the same
 */
template <typename T, typename ...Ts>
using areT = std::conjunction<std::is_same<T,Ts>...>;

/**
 * Base class for tensors
 */
class tensorFundamental{};

/*
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
    std::array<T, positive_natural_compiletime_pow<dim_length_n, std::tuple_size<Args>::value>()> data;

    using tuple_indices = Args;
    using elem_type = T;

    static constexpr std::size_t indices_amount =  std::tuple_size<Args>::value;
    static constexpr std::size_t data_count =
            positive_natural_compiletime_pow<dim_length_n, std::tuple_size<Args>::value>();


    template<typename ... Element, std::enable_if_t<(std::is_same_v<std::decay_t<Element>, T> && ...), bool> = true>
    constexpr tensorBase_rt(Element&&... input) : data{input...} {};

    template<typename Ti, std::size_t val, std::enable_if_t<std::is_same_v<std::decay_t<Ti>, T>, bool> = true>
    constexpr tensorBase_rt(std::array<Ti, val> input) : data(input){
        static_assert(areT<T, Ti>::value , "ARRAY TYPE DOESN'T MATCH TEMPLATE TYPE");
    };



    static constexpr auto static_calculate_indices(){

        static_assert((std::tuple_size<Args>::value <= 8), "tensor has to many indices");
        return cartesian_product_adv<dim_length_n, std::tuple_size<Args>::value>();

    };


    static constexpr tensorBase_rt<T, Args> random_tensor_rt(int lowerBound, int upperBound){
        return random_tensor_rt_i(lowerBound, upperBound,
                std::make_index_sequence<positive_natural_compiletime_pow<dim_length_n, std::tuple_size<Args>::value>()>{});
    }


    static constexpr tensorBase_rt<T, Args> random_tensor_rt(float lowerBound, float upperBound){
        return random_tensor_rt_i(lowerBound, upperBound,
                                  std::make_index_sequence<positive_natural_compiletime_pow<dim_length_n
                                  , std::tuple_size<Args>::value>()>{});
    }
};


template<typename T, typename ... Args>
using tensor_rt = tensorBase_rt<T, std::tuple<Args...>>;
*/


/**
 * Class that defines the tensors for constexpr calculations
 * @tparam T data type of the tensor
 * @tparam Args tuple with indices(here: up_t, low_t)
 */
template<typename T, typename Args>
class tensorBase : tensorFundamental{

    private:

        /**
         * creates random tensor of type tensorBase<t, Args> at compile time
         * @tparam is index sequence
         * @param lowerBound min T value
         * @param upperBound max T value
         * @return object of type tensorBase<t, Args>
         */
        template<std::size_t ...is>
        static constexpr auto random_tensor_i(T lowerBound, T upperBound, std::index_sequence<is...>){

            tensorBase<T, Args> temp{(is, uniform_distribution<T>(lowerBound, upperBound))...};
            return temp;
        }

    public:
        std::array<T, positive_natural_compiletime_pow<dim_length_n, std::tuple_size<Args>::value>()> data;

        using tuple_indices = Args;
        using elem_type = T;

        static constexpr std::size_t indices_amount =  std::tuple_size<Args>::value;
        static constexpr std::size_t data_count =
                positive_natural_compiletime_pow<dim_length_n, std::tuple_size<Args>::value>();


    template<typename ... Element, std::enable_if_t<(std::is_same_v<std::decay_t<Element>, T> && ...), bool> = true>
    constexpr tensorBase(Element&&... input) : data{input...} {
        static_assert(areT<T, Element...>::value , "VALUES INPUT TYPE DOESN'T MATCH TEMPLATE TYPE");
    };

    template<typename Ti, std::size_t val>
    constexpr tensorBase(std::array<Ti, val> input) : data(input){
        static_assert(areT<T, Ti>::value , "ARRAY TYPE DOESN'T MATCH TEMPLATE TYPE");
    };

    /**
 * Constructor that initializes the data array
 * @tparam Element
 * @param input
 */
//    template<typename ... Element>
//    constexpr tensorBase(Element&&... input) : data{input...} {
//        static_assert(areT<T, Element...>::value , "VALUES INPUT TYPE DOESN'T MATCH TEMPLATE TYPE");
//    };


//    template<typename Ti, typename Argsi>
//    constexpr tensorBase(const tensorBase<Ti, Argsi> &oldObj){
//        data = oldObj.data;
//    };



    /**
     * calculates indices at compile time
     * @return array of tuples
     */
    static constexpr auto static_calculate_indices(){

        static_assert((std::tuple_size<Args>::value <= 8), "tensor has to many indices");
        //return cartesian_product<DIM3, std::tuple_size<Args>::value>();
        return cartesian_product_adv<dim_length_n, std::tuple_size<Args>::value>();
    };

    /**
     * Random tensor of type tensorBase<T, Args> at compile time
     * @param lowerBound min T value
     * @param upperBound max T min
     * @return random tensor of type tensorBase<T, Args>
     */
    static constexpr tensorBase<T, Args> random_tensor_ct(T lowerBound, T upperBound){
        return random_tensor_i(lowerBound, upperBound,
                                  std::make_index_sequence<positive_natural_compiletime_pow<dim_length_n,
                                  std::tuple_size<Args>::value>()>{});
    }

};

template<typename T, typename ... Args>
using tensor = tensorBase<T, std::tuple<Args...>>;






/**
 * Overload of << to print compile time tensors
 * @tparam Ti data type of the tensor
 * @tparam Argsi indices of the tensor
 * @param os obj
 * @param tsr tensor
 * @return ostream
 */
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


