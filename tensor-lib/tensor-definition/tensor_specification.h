//
// Created by martin machajewski on 02.12.19.
// base idea by Ludwig Jens Papenfort and  Elias R. Most
// Goethe University Frankfurt am Main
//

#ifndef UNTITELED1_TENSOR_SPECIFICATION_H
#define UNTITELED1_TENSOR_SPECIFICATION_H

template<auto i> constexpr auto dim_length = i;
constexpr auto dim_length_n = dim_length<3>;

class index_t  {};
class up_t : index_t  {};
class low_t : index_t {};

#endif //UNTITELED1_TENSOR_SPECIFICATION_H
