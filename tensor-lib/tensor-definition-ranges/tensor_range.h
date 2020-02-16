//
// Created by martin on 04.02.20.
//

#ifndef UNTITELED1_TENSOR_RANGES_H
#define UNTITELED1_TENSOR_RANGES_H

#include <vector>
#include <tuple>
#include "tensor_specification.h"
#include "positive_natural_compiletime_pow.h"
#include "cartesian_product_ranges.h"
#include <type_traits>
#include "tensor.h"

#include "reorder.h"



template<typename T, typename Args>
class tensorBase_ranges : tensorFundamental{

public:
    std::vector<T> data;

    using tuple_indices = Args;
    using elem_type = T;

    static constexpr std::size_t indices_amount =  std::tuple_size<Args>::value;

    template<typename ... Element>
    constexpr tensorBase_ranges(Element&&... input) : data{input...} {
        static_assert(areT<T, Element...>::value , "VALUES INPUT TYPE DOESN'T MATCH TEMPLATE TYPE");
    };

    constexpr tensorBase_ranges(std::vector<T> &vec){
        data = vec;
    };

    template<typename Ti,typename Argsi>
    constexpr tensorBase_ranges(const tensorBase_ranges<Ti, Argsi> &oldObj){
        data = oldObj.data;
    };

    template<typename Ti,typename Argsi>
    constexpr tensorBase_ranges(tensorBase_ranges<Ti, Argsi> &oldObj){
        data = oldObj.data;
    };

    constexpr auto calculate_indices() const{

        return cartesian_product_ranges<DIM3, std::tuple_size<Args>::value>();
    };

    constexpr auto data_to_range_positions1D() const{
        return ranges::views::all(this->data) | ranges::views::enumerate;
    }

    constexpr auto data_to_range_positionsND() const {
        auto indices = this->calculate_indices() | ranges::to<std::vector>();
        return ranges::views::all(this->data)
            | ranges::views::enumerate
            | ranges::views::transform([=](auto d){return std::make_tuple(indices[std::get<0>(d)], std::get<1>(d));});
    }
};

template<typename T, typename ... Args>
using tensorRange = tensorBase_ranges<T, std::tuple<Args...>>;


template<typename Ti, typename Argsi>
std::ostream& operator<<(std::ostream& os, const tensorBase_ranges<Ti, Argsi>& tsr)
{
    for(int i = 0; i < tsr.data.size(); i++){

        std::cout << " " << tsr.data[i] << " ";
    }
    std::cout << " " << std::endl;

    return os;
}



#endif //UNTITELED1_TENSOR_RANGES_H
