//
// Created by martin on 13.02.20.
//

#ifndef UNTITELED1_UNITTEST_TENSORS_H
#define UNTITELED1_UNITTEST_TENSORS_H

#include "tensor.h"
#include "tensor_range.h"

struct unitTest_tensors {

    static tensor<int> tensor_Identiy_0D(0);
    static tensor<int, up_t> tensor_Identiy_1D(1,0,0);
    static tensor<int, up_t, up_t> tensor_Identiy_2D(1,0,0,
                                                     0,1,0,
                                                     0,0,1);
    static tensor<int, up_t, up_t, up_t> tensor_Identiy_3D(
                                                            1,0,0,
                                                            0,0,0,
                                                            0,0,0,

                                                            0,0,0,
                                                            0,1,0,
                                                            0,0,0,

                                                            0,0,0,
                                                            0,0,0,
                                                            0,0,1);
    static tensor<double> tensor_Identiy_0D_int(0);
    static tensor<double, up_t> tensor_Identiy_1D_int(1.0, 0.0, 0.0);
    static tensor<double, up_t, up_t> tensor_Identiy_2D_int(1,0,0,
                                                            0,1,0,
                                                            0,0,1);
    static tensor<double, up_t, up_t, up_t> tensor_Identiy_3D_int(
                                                            1,0,0,
                                                            0,0,0,
                                                            0,0,0,

                                                            0,0,0,
                                                            0,1,0,
                                                            0,0,0,

                                                            0,0,0,
                                                            0,0,0,
                                                            0,0,1)
};

#endif //UNTITELED1_UNITTEST_TENSORS_H
