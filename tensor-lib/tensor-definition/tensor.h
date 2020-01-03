//
// Created by martin on 03.01.20.
//

#ifndef UNTITELED1_TENSOR_H
#define UNTITELED1_TENSOR_H

#include <vector>
#include <tuple>

template<typename T, typename ... Args>
class tensor{

    private:

    std::vector<T> elements = {};

    public:

    using type = std::tuple<Args...>;
    std::size_t indices_amount = sizeof...(Args);

    template<typename ... Element>
    constexpr tensor(Element&&... input) : elements{input...} {};

    constexpr auto calculate_indices(){
        return cartesian_product_to_vec<2,2>();
    };

};


#endif //UNTITELED1_TENSOR_H
