//
// Created by martin on 11.12.19.
//

#ifndef UNTITELED1_TENSOR_ENUMERATE_RANGE_H
#define UNTITELED1_TENSOR_ENUMERATE_RANGE_H

#include <range/v3/view/enumerate.hpp>

template<typename T>
constexpr auto tensor_enumerate_range(const T& container){

    return ranges::views::enumerate(container); //e.g search for value at index position 4

}


#endif //UNTITELED1_TENSOR_ENUMERATE_RANGE_H
