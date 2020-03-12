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

/**
 * Class that defines the tensors for runtime calculations
 * @tparam T data type of the tensor
 * @tparam Args tuple with indices(here: up_t, low_t)
 */
template<typename T, typename Args>
class tensorBase_rt : tensorFundamental{
private:
    /**
     * calculates a random tensor of type T, Args as provided in the class template parameters.
     * @tparam is index sequence
     * @param lowerBound min int value
     * @param upperBound max int value
     * @return tensor<T, Args>
     */
    template<std::size_t ...is>
    static constexpr auto random_tensor_rt_i(int lowerBound, int upperBound, std::index_sequence<is...>){
        tensorBase_rt<T, Args> temp((is, random_number::rand_IntRange(lowerBound, upperBound))...);
        return temp;
    }

    /**
     * calculates a random tensor of type T, Args as provided in the class template parameters.
     * @tparam is index sequence
     * @param lowerBound min float value
     * @param upperBound max float value
     * @return tensor<T, Args>
     */
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


    /**
     * Constructor that initializes the data array
     * @tparam Element
     * @param input
     */
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


    /**
     * calculates tuple indices at runtime
     * @return array of tuples
     */
    constexpr auto calculate_indices() const{

        static_assert((std::tuple_size<Args>::value <= 8), "tensor has to many indices");
        //return cartesian_product<DIM3, std::tuple_size<Args>::value>();
        return cartesian_product_adv<dim_length_n, std::tuple_size<Args>::value>();

    };

    /**
     * calculates tuple indices at compile time
     * @return array of tuples
     */
    static constexpr auto static_calculate_indices(){

        static_assert((std::tuple_size<Args>::value <= 8), "tensor has to many indices");
        //return cartesian_product<DIM3, std::tuple_size<Args>::value>();
        return cartesian_product_adv<dim_length_n, std::tuple_size<Args>::value>();

    };

    /**
     * turns the tensors data array into a range
     * @return range elements paird with its index
     */
    constexpr auto data_to_range() const{
        return ranges::views::all(this->data) | ranges::views::enumerate;
    }

    /**
     * Returns a random tensor of type tensorBase_rt<T, Args>
     * @param lowerBound min int value
     * @param upperBound max int value
     * @return tensor of type  tensorBase_rt<T, Args>
     */
    static constexpr tensorBase_rt<T, Args> random_tensor_rt(int lowerBound, int upperBound){
        return random_tensor_rt_i(lowerBound, upperBound,
                std::make_index_sequence<positive_natural_compiletime_pow<dim_length_n, std::tuple_size<Args>::value>()>{});
    }

    /**
     * Returns a random tensor of type tensorBase_rt<T, Args>
     * @param lowerBound min float value
     * @param upperBound max float value
     * @return tensor of type  tensorBase_rt<T, Args>
     */
    static constexpr tensorBase_rt<T, Args> random_tensor_rt(float lowerBound, float upperBound){
        return random_tensor_rt_i(lowerBound, upperBound,
                                  std::make_index_sequence<positive_natural_compiletime_pow<dim_length_n
                                  , std::tuple_size<Args>::value>()>{});
    }
};

template<typename T, typename ... Args>
using tensor_rt = tensorBase_rt<T, std::tuple<Args...>>;



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

    /**
     * Constructor that initializes the data array
     * @tparam Element
     * @param input
     */
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


    /**
     * calculates indices at compile time
     * @return array of tuples
     */
    constexpr auto calculate_indices() const{

        static_assert((std::tuple_size<Args>::value <= 8), "tensor has to many indices");
        //return cartesian_product<DIM3, std::tuple_size<Args>::value>();
        return cartesian_product_adv<dim_length_n, std::tuple_size<Args>::value>();
    };

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
     * Returns a runtime tensor with the data of the constexpr tensor
     * @return this thensor as run time version
     */
    constexpr auto to_runtime_tensor() const{

        tensorBase_rt<T, Args> temp_tensor(static_cast<T>(0));
        temp_tensor.data = data;

        return temp_tensor;
    }

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
 * Overload of << to print run time tensors
 * @tparam Ti data type of the tensor
 * @tparam Argsi indices of the tensor
 * @param os obj
 * @param tsr tensor
 * @return ostream
 */
template<typename Ti, typename Argsi>
std::ostream& operator<<(std::ostream& os, const tensorBase_rt<Ti, Argsi>& tsr)
{
    for(int i = 0; i < tsr.data.size(); i++){

        std::cout << " " << tsr.data[i] << " ";
    }
    std::cout << " " << std::endl;
    return os;
}

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


