//
// Created by martin on 18.12.19.
//

#ifndef UNTITELED1_SAVE_AS_ARRAY_H
#define UNTITELED1_SAVE_AS_ARRAY_H

template<typename T, std::size_t size, typename ...tuples>
constexpr auto save_as_array(tuples... args){

    std::array<T, size> data = {args...};

    return data;

}

#endif //UNTITELED1_SAVE_AS_ARRAY_H
