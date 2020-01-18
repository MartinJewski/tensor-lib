//
// Created by martin on 04.01.20.
//

#ifndef UNTITELED1_POW_H
#define UNTITELED1_POW_H

template<std::size_t base, std::size_t exponent>
int constexpr positive_natural_compiletime_pow(){
    if constexpr(exponent == 0){
        return 1;
    }
    if constexpr(exponent > 0){
        return base * positive_natural_compiletime_pow<base, exponent-1>();
    }
}


#endif //UNTITELED1_POW_H
