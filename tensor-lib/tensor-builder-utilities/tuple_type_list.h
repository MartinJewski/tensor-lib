//
// Created by martin on 11.03.20.
//

#ifndef UNTITELED1_TUPLE_TYPE_LIST_H
#define UNTITELED1_TUPLE_TYPE_LIST_H

#include <tuple>

template <typename Args>
struct tuple_type_list
{
    template <std::size_t N>
    using type = typename std::tuple_element<N, Args>::type;
};


#endif //UNTITELED1_TUPLE_TYPE_LIST_H
