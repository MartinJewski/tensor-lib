//
// Created by martin on 12.01.20.
//

#ifndef UNTITELED1_TENSOR_CONCEPTS_H
#define UNTITELED1_TENSOR_CONCEPTS_H

#include <type_traits>

// concept
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


//function to test the concept
template<typename T> requires Floatingpoint<T>()
constexpr auto f(){

    return 0;

}


//function to test the concept
template<auto val> requires Floatingpoint<val>()
constexpr auto myFUNCTION(){

    return 0;

}


#endif //UNTITELED1_TENSOR_CONCEPTS_H
