//
// Created by martin on 04.01.20.
//

#ifndef UNTITELED1_POW_H
#define UNTITELED1_POW_H

template<int base, int exponent>
int constexpr compiletime_pow(){
    if constexpr(exponent == 0){
        return 1;
    }else{
        return base * compiletime_pow<base, exponent-1>();
    }
}


#endif //UNTITELED1_POW_H
