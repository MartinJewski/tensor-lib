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


/**
 * The tensor ranges class defines a tensors with special
 * class functions that operate on ranges.
 * @tparam T data type
 * @tparam Args indices saved as a tuple(here: up_t, low_t)
 */
template<typename T, typename Args>
class tensorBase_ranges : tensorFundamental{
private:
    /**
     * Creates a tensor that is randomly filled with int values.
     * @tparam is index sequence
     * @param lowerBound min value
     * @param upperBound max value
     * @return random tensor
     */
    template<std::size_t ...is>
    static constexpr auto random_tensor_range_int(int lowerBound, int upperBound, std::index_sequence<is...>){
        tensorBase_ranges<T, Args> temp((is, random_number::rand_IntRange(lowerBound, upperBound))...);
        return temp;
    }

    /**
     * Creates a tensor that is randomly filled with float values.
     * @tparam is index sequence
     * @param lowerBound min value
     * @param upperBound max value
     * @return random tensor
     */
    template<std::size_t ...is>
    static constexpr auto random_tensor_range_float(float lowerBound, float upperBound, std::index_sequence<is...>){
        tensorBase_ranges<T, Args> temp((is, random_number::rand_FloatRange(lowerBound, upperBound))...);
        return temp;
    }

public:
    std::vector<T> data;

    using tuple_indices = Args;
    using elem_type = T;

    static constexpr std::size_t indices_amount =  std::tuple_size<Args>::value;

    template<typename ... Element, std::enable_if_t<(std::is_same_v<std::decay_t<Element>, T> && ...), bool> = true>
    constexpr tensorBase_ranges(Element&&... input) : data{input...} {
        static_assert(areT<T, Element...>::value , "VALUES INPUT TYPE DOESN'T MATCH TEMPLATE TYPE");
    };

    template<typename Ti>
    constexpr tensorBase_ranges(std::vector<Ti> input) : data(input){
            static_assert(areT<T, Ti>::value , "VECTOR TYPE DOESN'T MATCH TEMPLATE TYPE");
    };

    /**
     * Constructor that initialized the data contrainer
     * @tparam Element type of the element
     * @param input values
     */
     /*
    template<typename ... Element>
    constexpr tensorBase_ranges(Element&&... input) : data{input...} {
        static_assert(areT<T, Element...>::value , "VALUES INPUT TYPE DOESN'T MATCH TEMPLATE TYPE");
    };

    constexpr tensorBase_ranges(std::vector<T>& vec){
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
*/
    /**
     * calculates array of index tuples at runtime
     * @return array of tuples that contain indices
     */
    constexpr auto calculate_indices() const{

        return cartesian_product_ranges<dim_length_n, std::tuple_size<Args>::value>();
    };

    /**
     * Turns the data container into a range with indices
     * @return every range element is paird with its index
     */
    constexpr auto data_to_range_positions1D() const{
        return ranges::views::all(this->data) | ranges::views::enumerate;
    }

    /**
     * Turns the data container into a range with indices.
     * The index is a tuple of the position in a nD array.
     * @return every range element is paird with its index
     */
    constexpr auto data_to_range_positionsND() const {
        auto indices = this->calculate_indices() | ranges::to<std::vector>();
        return ranges::views::all(this->data)
            | ranges::views::enumerate
            | ranges::views::transform([=](auto pair){return std::make_tuple(indices[std::get<0>(pair)], std::get<1>(pair));});
    }

    /**
     * Returns a random tensor of given data type and indices
     * @param lowerBound min int value
     * @param upperBound max int value
     * @return random tensor with given data type and indices
     */
    static constexpr tensorBase_ranges<T, Args> random_tensor_range(int lowerBound, int upperBound){
        return random_tensor_range_int(lowerBound, upperBound,
                                  std::make_index_sequence<positive_natural_compiletime_pow<dim_length_n, std::tuple_size<Args>::value>()>{});
    }

    /**
     * Returns a random tensor of given data type and indices
     * @param lowerBound min float value
     * @param upperBound max float value
     * @return random tensor with given data type and indices
     */
    static constexpr tensorBase_ranges<T, Args> random_tensor_range(float lowerBound, float upperBound){
        return random_tensor_range_float(lowerBound, upperBound,
                                     std::make_index_sequence<positive_natural_compiletime_pow<dim_length_n, std::tuple_size<Args>::value>()>{});
    }
};

template<typename T, typename ... Args>
using tensorRange = tensorBase_ranges<T, std::tuple<Args...>>;


/**
 * Prints out the tensor data
 * @tparam Ti data type of the tensor
 * @tparam Argsi indices type of the tensor
 * @param os ostream
 * @param tsr object
 * @return a ostream
 */
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
