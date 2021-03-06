//
// Created by martin on 21.11.19.
//

#ifndef BACHELOR_THESIS_TENSOR_CPP20_TUPLE_HELPER_H
#define BACHELOR_THESIS_TENSOR_CPP20_TUPLE_HELPER_H

#include <tuple>

//----------------------------------------------------------------------------

////////////////////this c++ file contains code provided by/////////////
//@author: Andy Prowl
//reference: Stackoverflow
//URL: https://stackoverflow.com/questions/14852593/removing-the-first-type-of-a-stdtuple
////////////////////////////////////////////////////////////////////////

/**
 * dummy definition of remove_ith_element
 * @tparam Count recursion times
 * @tparam T types
 */
template<std::size_t Count, typename T>
struct remove_ith_element{};

/**
 * Tuple with just the tail
 * @tparam Head type
 * @tparam Tail types
 */
template<typename Head, typename ...Tail>
struct remove_ith_element<0, std::tuple<Head, Tail...>>{
    typedef std::tuple<Tail...> type;
};

/**
 * Removes the ith element of an tuple
 * @tparam Count how many recursion steps
 * @tparam Head type we are looking at
 * @tparam Tail rest of the telements
 */
template<std::size_t Count, typename Head, typename ...Tail>
struct remove_ith_element<Count, std::tuple<Head, Tail...>>{

    typedef decltype(
                std::tuple_cat(
                        std::declval<std::tuple<Head>>(),
                        std::declval<typename remove_ith_element<Count-1, std::tuple<Tail...>>::type>()
                        )
            ) type;
};

//-----------------------------------------------------------------------------------------------------

template<std::size_t pos1, std::size_t pos2, typename, typename>
struct remove_ith_concat_tuple{};

/**
 * Contracts two tuples. Removes an type of both input tuples at given positions
 * @tparam pos1 position to be removed from the first tuple
 * @tparam pos2 position to be removed from the second tuple
 * @tparam T1 tuple types
 * @tparam T2 tuples types
 */
template<std::size_t pos1, std::size_t pos2, typename... T1, typename... T2>
struct remove_ith_concat_tuple<pos1, pos2 ,std::tuple<T1...>, std::tuple<T2...>>{
    using rem_t1 = typename remove_ith_element<pos1, std::tuple<T1...>>::type;
    using rem_t2 = typename remove_ith_element<pos2, std::tuple<T2...>>::type;

    typedef decltype(
            std::tuple_cat(rem_t1(), rem_t2())
            ) type;
};



template<std::size_t pos1, std::size_t pos2, typename>
struct remove_ith_jth_concat_tuple{};

template<std::size_t pos1, std::size_t pos2, typename... T1>
struct remove_ith_jth_concat_tuple<pos1, pos2 ,std::tuple<T1...>>{
    static_assert((pos1 <= pos2), "pos1 must be smaller than pos2!");
    using rem_t1 = typename remove_ith_element<pos1, std::tuple<T1...>>::type;
    using rem_t2 = typename remove_ith_element<pos2-1, rem_t1>::type;

    typedef rem_t2 type;
};

//------------------------------------------------------------------------------------------------------

#endif //BACHELOR_THESIS_TENSOR_CPP20_TUPLE_HELPER_H
