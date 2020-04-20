//
// Created by martin machajewski on 03.01.20.
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
#include "cartesian_product_adv.h"
#include <type_traits>

#include <range/v3/view/all.hpp>
#include <range/v3/view/enumerate.hpp>

#include "random_number.h"

////////////////////this c++ file contains code provided by/////////////
//@author: TartanLlama
//reference: Stackoverflow
//URL: https://stackoverflow.com/a/31533533/7091177
////////////////////////////////////////////////////////////////////////
/**
 * checks if all types are the same
 */
template <typename T, typename ...Ts>
using areT = std::conjunction<std::is_same<T,Ts>...>;

//-----------------------------------------------------------------------------------------



////////////////////this c++ file contains code provided by/////////////
//@author: NathanOliver
//reference: Stackoverflow
//URL: https://stackoverflow.com/a/60670375/7091177
////////////////////////////////////////////////////////////////////////

/**
 * Base class for tensors
 */
class tensorFundamental{};


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


