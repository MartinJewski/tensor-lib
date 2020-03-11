//
// Created by martin on 02.12.19.
//

#ifndef UNTITELED1_TENSOR_SPECIFICATION_H
#define UNTITELED1_TENSOR_SPECIFICATION_H

template<auto i> constexpr auto DIM = i;
constexpr auto DIM2 = DIM<2>;
constexpr auto DIM3 = DIM<3>;


class index_t  {};
class up_t : index_t  {};
class low_t : index_t {};

#endif //UNTITELED1_TENSOR_SPECIFICATION_H
