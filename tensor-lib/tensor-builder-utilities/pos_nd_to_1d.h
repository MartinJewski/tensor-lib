//
// Created by martin on 04.01.20.
//

#ifndef UNTITELED1_POS_ND_TO_1D_H
#define UNTITELED1_POS_ND_TO_1D_H

template <auto ... as>
auto constexpr pos_nd_to_1d ()
{
    std::size_t  i { 0u };

    (((i *= DIM3, i += as), ...));

    return i;
}


#endif //UNTITELED1_POS_ND_TO_1D_H
