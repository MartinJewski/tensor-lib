//
// Created by martin on 04.01.20.
//

#ifndef UNTITELED1_REMOVE_ITH_TUPLE_ELEMENT_H
#define UNTITELED1_REMOVE_ITH_TUPLE_ELEMENT_H


template<std::size_t Count, typename T>
struct remove_ith_tuple_element{};

template<typename Head, typename ...Tail>
struct remove_ith_tuple_element<0, std::tuple<Head, Tail...>>{
    typedef std::tuple<Tail...> type;
};

template<std::size_t Count, typename Head, typename ...Tail>
struct remove_ith_tuple_element<Count, std::tuple<Head, Tail...>>{

    typedef decltype(
        std::tuple_cat(
                std::declval<std::tuple<Head>>(),
                std::declval<typename remove_ith_tuple_element<Count-1, std::tuple<Tail...>>::type>()
                        )) type;
};

#endif //UNTITELED1_REMOVE_ITH_TUPLE_ELEMENT_H
