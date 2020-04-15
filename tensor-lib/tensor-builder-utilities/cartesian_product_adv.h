//
// Created by martin machajewski on 08.03.20.
//

#ifndef UNTITELED1_CARTESIAN_PRODUCT_ADV_H
#define UNTITELED1_CARTESIAN_PRODUCT_ADV_H


////////////////////this c++ file contains code provided by/////////////
//@author: Timo
//reference: Stackoverflow
//URL:https://stackoverflow.com/questions/60580444/cartesian-product-for-multiple-sets-at-compile-time/60585120#60585120
////////////////////////////////////////////////////////////////////////

template <typename It, typename T>
constexpr void setAll(It begin, It end, T value)
{
    for (; begin != end; ++begin)
        *begin = value;
}

template <typename T, std::size_t I>
constexpr void increment(std::array<T, I>& counter, T max)
{
    for (auto idx = I; idx > 0;)
    {
        --idx;

        if (++counter[idx] >= max)
        {
            setAll(counter.begin() + idx, counter.end(), 0); // because std::fill is not constexpr yet
        }
        else
        {
            break;
        }
    }
}

// std::pow is not constexpr
constexpr auto power = [](auto base, auto power)
{
    auto result = base;
    while (--power)
        result *= base;
    return result;
};


template<typename T, std::size_t ...is>
constexpr auto type_to_tuple(std::index_sequence<is...>){

    return std::make_tuple((static_cast<T>(is))...);

}

template<typename T, std::size_t sets, std::size_t ...is>
constexpr auto generate_tuple(std::array<T, sets> arr, std::index_sequence<is...>){

    return std::make_tuple(arr[is]...);

}

template<typename T, std::size_t sets, std::size_t length, std::size_t ...is, typename ...U>
constexpr auto array_to_tuple(std::array<std::array<T, sets>, length>& arr, std::index_sequence<is...>){

    std::array<decltype(type_to_tuple<int>(std::make_index_sequence<sets>{})),
            length> products_tuple{generate_tuple(arr[is], std::make_index_sequence<sets>{})...};

    return products_tuple;
}


template<std::size_t range, std::size_t sets>
constexpr auto cartesian_product_adv()
{
    std::array<std::array<int, sets>, power(range, sets)> products{};

    std::array<int, sets> currentSet{};

    for (auto& product : products)
    {
        product = currentSet;
        increment(currentSet, static_cast<int>(range));
    }

    return array_to_tuple(products, std::make_index_sequence<power(range, sets)>{});
}

//https://stackoverflow.com/questions/60580444/cartesian-product-for-multiple-sets-at-compile-time/60585120#60585120

#endif //UNTITELED1_CARTESIAN_PRODUCT_ADV_H
