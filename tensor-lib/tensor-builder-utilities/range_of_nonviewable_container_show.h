//
// Created by martin on 10.12.19.
//

#ifndef UNTITELED1_RANGE_OF_NONVIEWABLE_CONTAINER_SHOW_H
#define UNTITELED1_RANGE_OF_NONVIEWABLE_CONTAINER_SHOW_H

#include "tuple_show.h"
#include <iostream>
#include <range/v3/algorithm/for_each.hpp>


//non viewable container are tuple and pair
template<typename T>
constexpr auto range_of_nonviewable_container_show(T t){

    ranges::for_each(t, [](auto&& tuple){ std::cout << tuple << std::endl; });
}

#endif //UNTITELED1_RANGE_OF_NONVIEWABLE_CONTAINER_SHOW_H


//--------------------------------------------------
// INDEXING A CONTAINER
/* MAIN EXAMPLE CODE
 constexpr std::array<int, 9> tensor_A{100,101,102,103,104,105,106,107,108};
 constexpr std::array<int, 9> tensor_B{200,201,202,203,204,205,206,207,208};

 const auto enum_tensor_A = ranges::views::enumerate(tensor_A); //e.g search for value at index position 4
 std::cout << "-------enumerated container A-------" << std::endl;
 range_of_nonviewable_container_show(enum_tensor_A);

 auto enum_tensor_B = ranges::views::enumerate(tensor_B);
 std::cout << "------enumerated container B--------" << std::endl;
 range_of_nonviewable_container_show(enum_tensor_B);
 */
