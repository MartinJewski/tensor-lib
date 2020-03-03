//
// Created by martin on 13.02.20.
//

#ifndef UNTITELED1_SPEED_TEST_TENSORS_H
#define UNTITELED1_SPEED_TEST_TENSORS_H

#include "tensor.h"
#include "tensor_range.h"
#include "pos_nd_to_1d.h"


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

template<typename T, std::size_t size>
class random_tensor_generator{

    public:

        std::array<tensor_rt<T>, size> array_0D;
        std::array<tensor_rt<T, up_t>, size> array_1D;
        std::array<tensor_rt<T, up_t, up_t>, size> array_2D;
        std::array<tensor_rt<T, up_t, up_t, up_t>, size> array_3D;


        auto pick_random_tensor_0D(){
            return array_0D[random() % size];
        }
        auto pick_random_tensor_1D(){
            return array_1D[random() % size];
        }
        auto pick_random_tensor_2D(){
            return array_2D[random() % size];
        }
        auto pick_random_tensor_3D(){
            return array_3D[random() % size];
        }

        template<std::size_t ...is>
        void generate_tensor_array(int lowerBound, int upperBound, std::index_sequence<is...>){

            array_0D = {(is, tensor_rt<int>::random_tensor_rt(lowerBound, upperBound))...};
            array_1D = {(is, tensor_rt<int, up_t>::random_tensor_rt(lowerBound, upperBound))...};
            array_2D = {(is, tensor_rt<int, up_t, up_t>::random_tensor_rt(lowerBound, upperBound))...};
            array_3D = {(is, tensor_rt<int, up_t, up_t, up_t>::random_tensor_rt(lowerBound, upperBound))...};

        }

        template<std::size_t ...is>
        void generate_tensor_array(float lowerBound, float upperBound, std::index_sequence<is...>){

            array_0D = {(is, tensor_rt<float>::random_tensor_rt(lowerBound, upperBound))...};
            array_1D = {(is, tensor_rt<float, up_t>::random_tensor_rt(lowerBound, upperBound))...};
            array_2D = {(is, tensor_rt<float, up_t, up_t>::random_tensor_rt(lowerBound, upperBound))...};
            array_3D = {(is, tensor_rt<float, up_t, up_t, up_t>::random_tensor_rt(lowerBound, upperBound))...};

        }

        constexpr random_tensor_generator(T lowerBound, T upperBound){

            static_assert((std::is_same<T, int>::value || std::is_same<T, float>::value), "only float or int is allowed");

            if constexpr(std::is_same<T, int>::value){
                generate_tensor_array(lowerBound, upperBound, std::make_index_sequence<size>{});
            }
            if constexpr (std::is_same<T, float>::value){
                generate_tensor_array(lowerBound, upperBound, std::make_index_sequence<size>{});
            }
    };
};




template<typename T, std::size_t size>
class random_tensor_generator_ranges{

public:

    std::array<tensorRange<T>, size> array_0D;
    std::array<tensorRange<T, up_t>, size> array_1D;
    std::array<tensorRange<T, up_t, up_t>, size> array_2D;
    std::array<tensorRange<T, up_t, up_t, up_t>, size> array_3D;


    auto pick_random_tensor_0D(){
        return array_0D[random() % size];
    }
    auto pick_random_tensor_1D(){
        return array_1D[random() % size];
    }
    auto pick_random_tensor_2D(){
        return array_2D[random() % size];
    }
    auto pick_random_tensor_3D(){
        return array_3D[random() % size];
    }

    template<std::size_t ...is>
    void generate_tensor_array(int lowerBound, int upperBound, std::index_sequence<is...>){

        array_0D = {(is, tensorRange<int>::random_tensor_range(lowerBound, upperBound))...};
        array_1D = {(is, tensorRange<int, up_t>::random_tensor_range(lowerBound, upperBound))...};
        array_2D = {(is, tensorRange<int, up_t, up_t>::random_tensor_range(lowerBound, upperBound))...};
        array_3D = {(is, tensorRange<int, up_t, up_t, up_t>::random_tensor_range(lowerBound, upperBound))...};

    }

    template<std::size_t ...is>
    void generate_tensor_array(float lowerBound, float upperBound, std::index_sequence<is...>){

        array_0D = {(is, tensorRange<float>::random_tensor_range(lowerBound, upperBound))...};
        array_1D = {(is, tensorRange<float, up_t>::random_tensor_range(lowerBound, upperBound))...};
        array_2D = {(is, tensorRange<float, up_t, up_t>::random_tensor_range(lowerBound, upperBound))...};
        array_3D = {(is, tensorRange<float, up_t, up_t, up_t>::random_tensor_range(lowerBound, upperBound))...};

    }

    constexpr random_tensor_generator_ranges(T lowerBound, T upperBound){

        static_assert((std::is_same<T, int>::value || std::is_same<T, float>::value), "only float or int is allowed");

        if constexpr(std::is_same<T, int>::value){
            generate_tensor_array(lowerBound, upperBound, std::make_index_sequence<size>{});
        }
        if constexpr (std::is_same<T, float>::value){
            generate_tensor_array(lowerBound, upperBound, std::make_index_sequence<size>{});
        }
    };
};



class for_loop_contraction{

    public:

        constexpr for_loop_contraction() = default;

        //compares to a contraction<0,1>
        template<typename T>
        tensor_rt<T, up_t, up_t> for_loop_contraction_2D(tensor_rt<T, up_t, up_t> tensor1, tensor_rt<T, up_t, up_t> tensor2){

            tensor_rt<T, up_t, up_t> tensor3;

            for(int i = 0; i < DIM3; i++){ //rows

                for(int j = 0; j < DIM3; j++){ //columns

                    for(int k = 0; k < DIM3; k++){ //multiplication

                        tensor3.data[pos_nd_to_1d(i,j)] += tensor1.data[pos_nd_to_1d(k, i)] * tensor2.data[pos_nd_to_1d(j, k)];

                    }
                }
            }

            return tensor3;
        }


        //compares to a contraction<0,1>
        template<typename T>
        tensor_rt<T, up_t, up_t, up_t, up_t> for_loop_contraction_3D(tensor_rt<T, up_t, up_t, up_t> tensor1, tensor_rt<T, up_t, up_t, up_t> tensor2){

            tensor_rt<T, up_t, up_t, up_t, up_t> tensor3;

            for(int i = 0; i < DIM3; i++){ //rows

                for(int j = 0; j < DIM3; j++){ //columns

                    for(int l = 0; l < DIM3; l++){

                        for(int k = 0; k < DIM3; k++){

                            for(int d = 0; d < DIM3; d++){
                                tensor3.data[pos_nd_to_1d(i,j,l,k)] += tensor1.data[pos_nd_to_1d(d,i,j)] * tensor2.data[pos_nd_to_1d(l,d,k)];
                            }
                        }
                    }
                }
            }

            return tensor3;
        };

};

class for_loop_reorder{

    public:

    constexpr for_loop_reorder() = default;

    template<typename T>
    tensor_rt<T, up_t, up_t> for_loop_reordering_2D(tensor_rt<T, up_t, up_t> tensor1){

        //0,1
        tensor_rt<T, up_t, up_t> tensor3;

        for(int i = 0; i < DIM3; i++){ //rows

            for(int j = 0; j < DIM3; j++){ //columns

                tensor3.data[pos_nd_to_1d(j,i)] = tensor1.data[pos_nd_to_1d(i, j)];

            }
        }

        return tensor3;
    }

    template<typename T>
    tensor_rt<T, up_t, up_t, up_t> for_loop_reordering_3D(tensor_rt<T, up_t, up_t, up_t> tensor1){

        //0,1,2
        tensor_rt<T, up_t, up_t, up_t> tensor3;

        for(int i = 0; i < DIM3; i++){ //rows

            for(int j = 0; j < DIM3; j++){ //columns

                for(int k = 0; k < DIM3; k++){

                    //2,1,0
                    tensor3.data[pos_nd_to_1d(k, j, i)] = tensor1.data[pos_nd_to_1d(i, j, k)];

                }
            }
        }

        return tensor3;

    }

};

class for_loop_trace{

    public:
    constexpr for_loop_trace() = default;

    template<typename T>
    auto for_loop_trace_2D(tensor_rt<T, up_t, up_t> tensor1){

        int value = 0;

        for(int i = 0; i < DIM3; i++){

            for(int j = 0; j < DIM3; j++){

                if( i == j ){
                    value += tensor1.data[pos_nd_to_1d(i,j)];
                }
            }
        }

        return value;
    }

    template<typename T>
    auto for_loop_trace_3D(tensor_rt<T, up_t, up_t, up_t> tensor1){

        int value = 0;

        for(int i = 0; i < DIM3; i++){

            for(int j = 0; j < DIM3; j++){

                for(int k = 0; k < DIM3; k++){

                    if( (i == j) && (i == k) && (k == j) ){
                        value += tensor1.data[pos_nd_to_1d(i,j)];
                    }
                }
            }
        }

        return value;
    }
};

#endif //UNTITELED1_SPEED_TEST_TENSORS_H
