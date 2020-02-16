//
// Created by martin on 13.02.20.
//

#ifndef UNTITELED1_UNITTEST_TENSORS_H
#define UNTITELED1_UNITTEST_TENSORS_H

#include "tensor.h"
#include "tensor_range.h"

struct unitTest_tensor_ct {

    static constexpr tensor<int> tensor_Identiy_0D_int();
    static constexpr tensor<int, up_t> tensor_Identiy_1D_int{1,0,0};
    static constexpr tensor<int, up_t, up_t> tensor_Identiy_2D_int{1,0,0,
                                                     0,1,0,
                                                     0,0,1};
    static constexpr tensor<int, up_t, up_t, up_t> tensor_Identiy_3D_int{
                                                            1,0,0,
                                                            0,0,0,
                                                            0,0,0,

                                                            0,0,0,
                                                            0,1,0,
                                                            0,0,0,

                                                            0,0,0,
                                                            0,0,0,
                                                            0,0,1};

    static constexpr tensor<double> tensor_Identiy_0D_double{0.0};
    static constexpr tensor<double, up_t> tensor_Identiy_1D_double{1.0, 0.0, 0.0};
    static constexpr tensor<double, up_t, up_t> tensor_Identiy_2D_double{1.0,0.0,0.0,
                                                            0.0,1.0,0.0,
                                                            0.0,0.0,1.0};
    static constexpr tensor<double, up_t, up_t, up_t> tensor_Identiy_3D_double{
                                                            1.0,0.0,0.0,
                                                            0.0,0.0,0.0,
                                                            0.0,0.0,0.0,

                                                            0.0,0.0,0.0,
                                                            0.0,1.0,0.0,
                                                            0.0,0.0,0.0,

                                                            0.0,0.0,0.0,
                                                            0.0,0.0,0.0,
                                                            0.0,0.0,1.0};

    static constexpr tensor<float> tensor_Identiy_0D_float{0.0f};
    static constexpr tensor<float, up_t> tensor_Identiy_1D_float{1.0f, 0.0f, 0.0f};
    static constexpr tensor<float, up_t, up_t> tensor_Identiy_2D_float{1.0f,0.0f,0.0f,
                                                            0.0f,1.0f,0.0f,
                                                            0.0f,0.0f,1.0f};
    static constexpr tensor<float, up_t, up_t, up_t> tensor_Identiy_3D_float{
                                                            1.0f,0.0f,0.0f,
                                                            0.0f,0.0f,0.0f,
                                                            0.0f,0.0f,0.0f,

                                                            0.0f,0.0f,0.0f,
                                                            0.0f,1.0f,0.0f,
                                                            0.0f,0.0f,0.0f,

                                                            0.0f,0.0f,0.0f,
                                                            0.0f,0.0f,0.0f,
                                                            0.0f,0.0f,1.0f};


    static constexpr tensor<int> tensor_sequence_0D_int{0};
    static constexpr tensor<int, up_t> tensor_sequence_1D_int{0,1,2};
    static constexpr tensor<int, up_t, up_t> tensor_sequence_2D_int{  0,1,2,
                                                            3,4,5,
                                                            6,7,8};
    static constexpr tensor<int, up_t, up_t, up_t> tensor_sequence_3D{
                                                            0,1,2,
                                                            3,4,5,
                                                            6,7,8,

                                                            9,10,11,
                                                            12,13,14,
                                                            15,16,17,

                                                            18,19,20,
                                                            21,22,23,
                                                            24,25,26};

    static constexpr tensor<double> tensor_sequence_0D_double{0.0};
    static constexpr tensor<double, up_t> tensor_sequence_1D_double{0.0, 1.0, 2.0};
    static constexpr tensor<double, up_t, up_t> tensor_sequence_2D_double{    0.0,1.0,2.0,
                                                                    3.0,4.0,5.0,
                                                                    6.0,7.0,8.0};
    static constexpr tensor<double, up_t, up_t, up_t> tensor_sequence_double{
                                                                0.0,1.0,2.0,
                                                                3.0,4.0,5.0,
                                                                6.0,7.0,8.0,

                                                                9.0,10.0,11.0,
                                                                12.0,13.0,14.0,
                                                                15.0,16.0,17.0,

                                                                18.0,19.0,20.0,
                                                                21.0,22.0,23.0,
                                                                24.0,25.0,26.0};

    static constexpr tensor<float> tensor_sequence_0D_float{0.0f};
    static constexpr tensor<float, up_t> tensor_sequence_1D_float{0.0f, 1.0f, 2.0f};
    static constexpr tensor<float, up_t, up_t> tensor_sequence_2D_float{  0.0f,1.0f,2.0f,
                                                                3.0f,4.0f,5.0f,
                                                                6.0f,7.0f,8.0f};
    static constexpr tensor<float, up_t, up_t, up_t> tensor_sequence_3D_float{
                                                                0.0f,1.0f,2.0f,
                                                                3.0f,4.0f,5.0f,
                                                                6.0f,7.0f,8.0f,

                                                                9.0f,10.0f,11.0f,
                                                                12.0f,13.0f,14.0f,
                                                                15.0f,16.0f,17.0f,

                                                                18.0f,19.0f,20.0f,
                                                                21.0f,22.0f,23.0f,
                                                                24.0f,25.0f,26.0f};
};

struct unitTest_tensor_rt{

     tensor_rt<int> tensor_Identiy_0D_int{0};
     tensor_rt<int, up_t> tensor_Identiy_1D_int{1,0,0};
     tensor_rt<int, up_t, up_t> tensor_Identiy_2D_int{1,0,0,
                                                            0,1,0,
                                                            0,0,1};
     tensor_rt<int, up_t, up_t, up_t> tensor_Identiy_3D_int{
                                                                    1,0,0,
                                                                    0,0,0,
                                                                    0,0,0,

                                                                    0,0,0,
                                                                    0,1,0,
                                                                    0,0,0,

                                                                    0,0,0,
                                                                    0,0,0,
                                                                    0,0,1};

     tensor_rt<double> tensor_Identiy_0D_double{0.0};
     tensor_rt<double, up_t> tensor_Identiy_1D_double{1.0, 0.0, 0.0};
     tensor_rt<double, up_t, up_t> tensor_Identiy_2D_double{  1.0,0.0,0.0,
                                                                    0.0,1.0,0.0,
                                                                    0.0,0.0,1.0};
     tensor_rt<double, up_t, up_t, up_t> tensor_Identiy_3D_double{
                                                                        1.0,0.0,0.0,
                                                                        0.0,0.0,0.0,
                                                                        0.0,0.0,0.0,

                                                                        0.0,0.0,0.0,
                                                                        0.0,1.0,0.0,
                                                                        0.0,0.0,0.0,

                                                                        0.0,0.0,0.0,
                                                                        0.0,0.0,0.0,
                                                                        0.0,0.0,1.0};

     tensor_rt<float> tensor_Identiy_0D_float{0.0f};
     tensor_rt<float, up_t> tensor_Identiy_1D_float{1.0f, 0.0f, 0.0f};
     tensor_rt<float, up_t, up_t> tensor_Identiy_2D_float{1.0f,0.0f,0.0f,
                                                                0.0f,1.0f,0.0f,
                                                                0.0f,0.0f,1.0f};
     tensor_rt<float, up_t, up_t, up_t> tensor_Identiy_3D_float{
                                                                        1.0f,0.0f,0.0f,
                                                                        0.0f,0.0f,0.0f,
                                                                        0.0f,0.0f,0.0f,

                                                                        0.0f,0.0f,0.0f,
                                                                        0.0f,1.0f,0.0f,
                                                                        0.0f,0.0f,0.0f,

                                                                        0.0f,0.0f,0.0f,
                                                                        0.0f,0.0f,0.0f,
                                                                        0.0f,0.0f,1.0f};


     tensor_rt<int> tensor_sequence_0D_int{0};
     tensor_rt<int, up_t> tensor_sequence_1D_int{0,1,2};
     tensor_rt<int, up_t, up_t> tensor_sequence_2D_int{  0,1,2,
                                                                3,4,5,
                                                                6,7,8};
     tensor_rt<int, up_t, up_t, up_t> tensor_sequence_3D_int{
                                                                0,1,2,
                                                                3,4,5,
                                                                6,7,8,

                                                                9,10,11,
                                                                12,13,14,
                                                                15,16,17,

                                                                18,19,20,
                                                                21,22,23,
                                                                24,25,26};

     tensor_rt<double> tensor_sequence_0D_double{0.0};
     tensor_rt<double, up_t> tensor_sequence_1D_double{0.0, 1.0, 2.0};
     tensor_rt<double, up_t, up_t> tensor_sequence_2D_double{ 0.0,1.0,2.0,
                                                                    3.0,4.0,5.0,
                                                                    6.0,7.0,8.0};
     tensor_rt<double, up_t, up_t, up_t> tensor_sequence_double{
                                                                    0.0,1.0,2.0,
                                                                    3.0,4.0,5.0,
                                                                    6.0,7.0,8.0,

                                                                    9.0,10.0,11.0,
                                                                    12.0,13.0,14.0,
                                                                    15.0,16.0,17.0,

                                                                    18.0,19.0,20.0,
                                                                    21.0,22.0,23.0,
                                                                    24.0,25.0,26.0};

      tensor_rt<float> tensor_sequence_0D_float{0.0f};
      tensor_rt<float, up_t> tensor_sequence_1D_float{0.0f, 1.0f, 2.0f};
      tensor_rt<float, up_t, up_t> tensor_sequence_2D_float{   0.0f,1.0f,2.0f,
                                                                    3.0f,4.0f,5.0f,
                                                                    6.0f,7.0f,8.0f};
      tensor_rt<float, up_t, up_t, up_t> tensor_sequence_3D_float{
                                                                        0.0f,1.0f,2.0f,
                                                                        3.0f,4.0f,5.0f,
                                                                        6.0f,7.0f,8.0f,

                                                                        9.0f,10.0f,11.0f,
                                                                        12.0f,13.0f,14.0f,
                                                                        15.0f,16.0f,17.0f,

                                                                        18.0f,19.0f,20.0f,
                                                                        21.0f,22.0f,23.0f,
                                                                        24.0f,25.0f,26.0f};
};

struct unitTest_tensor_range {

     tensorRange<int> tensor_Identiy_0D_int();
     tensorRange<int, up_t> tensor_Identiy_1D_int{1,0,0};
     tensorRange<int, up_t, up_t> tensor_Identiy_2D_int{1,0,0,
                                                            0,1,0,
                                                            0,0,1};
     tensorRange<int, up_t, up_t, up_t> tensor_Identiy_3D_int{
            1,0,0,
            0,0,0,
            0,0,0,

            0,0,0,
            0,1,0,
            0,0,0,

            0,0,0,
            0,0,0,
            0,0,1};

     tensorRange<double> tensor_Identiy_0D_double{0.0};
     tensorRange<double, up_t> tensor_Identiy_1D_double{1.0, 0.0, 0.0};
     tensorRange<double, up_t, up_t> tensor_Identiy_2D_double{  1.0,0.0,0.0,
                                                                    0.0,1.0,0.0,
                                                                    0.0,0.0,1.0};
     tensorRange<double, up_t, up_t, up_t> tensor_Identiy_3D_double{
            1.0,0.0,0.0,
            0.0,0.0,0.0,
            0.0,0.0,0.0,

            0.0,0.0,0.0,
            0.0,1.0,0.0,
            0.0,0.0,0.0,

            0.0,0.0,0.0,
            0.0,0.0,0.0,
            0.0,0.0,1.0};

     tensorRange<float> tensor_Identiy_0D_float{0.0f};
     tensorRange<float, up_t> tensor_Identiy_1D_float{1.0f, 0.0f, 0.0f};
     tensorRange<float, up_t, up_t> tensor_Identiy_2D_float{1.0f,0.0f,0.0f,
                                                                0.0f,1.0f,0.0f,
                                                                0.0f,0.0f,1.0f};
     tensorRange<float, up_t, up_t, up_t> tensor_Identiy_3D_float{
            1.0f,0.0f,0.0f,
            0.0f,0.0f,0.0f,
            0.0f,0.0f,0.0f,

            0.0f,0.0f,0.0f,
            0.0f,1.0f,0.0f,
            0.0f,0.0f,0.0f,

            0.0f,0.0f,0.0f,
            0.0f,0.0f,0.0f,
            0.0f,0.0f,1.0f};


     tensorRange<int> tensor_sequence_0D_int{0};
     tensorRange<int, up_t> tensor_sequence_1D_int{0,1,2};
     tensorRange<int, up_t, up_t> tensor_sequence_2D_int{ 0,1,2,
                                                               3,4,5,
                                                               6,7,8};
     tensorRange<int, up_t, up_t, up_t> tensor_sequence_3D_in{
            0,1,2,
            3,4,5,
            6,7,8,

            9,10,11,
            12,13,14,
            15,16,17,

            18,19,20,
            21,22,23,
            24,25,26};

     tensorRange<double> tensor_sequence_0D_double{0.0};
     tensorRange<double, up_t> tensor_sequence_1D_double{0.0, 1.0, 2.0};
     tensorRange<double, up_t, up_t> tensor_sequence_2D_double{ 0.0,1.0,2.0,
                                                                    3.0,4.0,5.0,
                                                                    6.0,7.0,8.0};
     tensorRange<double, up_t, up_t, up_t> tensor_sequence_double{
            0.0,1.0,2.0,
            3.0,4.0,5.0,
            6.0,7.0,8.0,

            9.0,10.0,11.0,
            12.0,13.0,14.0,
            15.0,16.0,17.0,

            18.0,19.0,20.0,
            21.0,22.0,23.0,
            24.0,25.0,26.0};

     tensorRange<float> tensor_sequence_0D_float{0.0f};
     tensorRange<float, up_t> tensor_sequence_1D_float{0.0f, 1.0f, 2.0f};
     tensorRange<float, up_t, up_t> tensor_sequence_2D_float{   0.0f,1.0f,2.0f,
                                                                    3.0f,4.0f,5.0f,
                                                                    6.0f,7.0f,8.0f};
     tensorRange<float, up_t, up_t, up_t> tensor_sequence_3D_float{
            0.0f,1.0f,2.0f,
            3.0f,4.0f,5.0f,
            6.0f,7.0f,8.0f,

            9.0f,10.0f,11.0f,
            12.0f,13.0f,14.0f,
            15.0f,16.0f,17.0f,

            18.0f,19.0f,20.0f,
            21.0f,22.0f,23.0f,
            24.0f,25.0f,26.0f};
};
#endif //UNTITELED1_UNITTEST_TENSORS_H
