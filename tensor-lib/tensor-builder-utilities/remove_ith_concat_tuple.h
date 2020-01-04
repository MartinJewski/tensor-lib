//
// Created by martin on 04.01.20.
//

#ifndef UNTITELED1_REMOVE_ITH_CONCAT_TUPLE_H
#define UNTITELED1_REMOVE_ITH_CONCAT_TUPLE_H

#include "remove_ith_tuple_element.h"

template<std::size_t pos1, std::size_t pos2, typename T1, typename T2>
struct remove_ith_concat_tuple{};

template<std::size_t pos1, typename... T1,std::size_t pos2, typename... T2>
struct remove_ith_concat_tuple<pos1, pos2 ,std::tuple<T1...>, std::tuple<T2...>>{
    using rem_t1 = typename remove_ith_tuple_element<pos1, std::tuple<T1...>>::type;
    using rem_t2 = typename remove_ith_tuple_element<pos2, std::tuple<T2...>>::type;

    typedef decltype(
        std::tuple_cat(rem_t1(), rem_t2())
        ) type;

};


#endif //UNTITELED1_REMOVE_ITH_CONCAT_TUPLE_H
