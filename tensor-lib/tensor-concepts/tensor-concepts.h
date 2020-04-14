//
// Created by martin machajewski on 12.01.20.
//

#ifndef UNTITELED1_TENSOR_CONCEPTS_H
#define UNTITELED1_TENSOR_CONCEPTS_H

#include <type_traits>
#include "tensor.h"

//concept tests, not a part of the bachelor thesis

template <typename T>
concept constexpr bool Integral(){

    return std::is_integral<T>::value;

}


template <typename T>
concept constexpr bool IntegerIntegral(){

    return std::is_integral<T>::value && std::numeric_limits<T>::is_integer && !(std::is_same<bool, T>::value);

}

template<typename T>
concept constexpr bool Floatingpoint(){
    return std::is_floating_point<T>::value;
}

template<auto val>
concept constexpr bool Floatingpoint(){
    return std::is_floating_point<decltype(val)>::value;
}

template<typename B>
concept isTensor =  std::is_base_of<tensorFundamental, B>::value;


template<typename T>
concept isFundamental = std::is_fundamental<T>::value;


template<typename T>
concept notFundamental = !std::is_fundamental<T>::value;


#endif //UNTITELED1_TENSOR_CONCEPTS_H
