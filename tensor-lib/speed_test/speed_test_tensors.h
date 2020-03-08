//
// Created by martin on 13.02.20.
//

#ifndef UNTITELED1_SPEED_TEST_TENSORS_H
#define UNTITELED1_SPEED_TEST_TENSORS_H

#include "tensor.h"
#include "tensor_range.h"
#include "pos_nd_to_1d.h"
#include "random_number.h"

template<auto i> constexpr auto REPS = i;
constexpr auto REP= REPS<100000>;


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

template<typename T, std::size_t U, std::size_t V, std::size_t W, typename X>
struct random_tensor_generator_ct;

template<typename T, std::size_t size, std::size_t lowerBound, std::size_t upperBound, std::size_t ...is>
struct random_tensor_generator_ct<T, size, lowerBound, upperBound, std::index_sequence<is...>>{

public:
//https://mklimenko.github.io/english/2018/06/04/constexpr-random/
    std::array<tensor<T>, size> array_0D = {(is, tensor<T>::random_tensor_ct(lowerBound, upperBound))...};
    std::array<tensor<T, up_t>, size> array_1D = {(is, tensor<T, up_t>::random_tensor_ct(lowerBound, upperBound))...};
    std::array<tensor<T, up_t, up_t>, size> array_2D = {(is, tensor<T, up_t, up_t>::random_tensor_ct(lowerBound, upperBound))...};
    std::array<tensor<T, up_t, up_t, up_t>, size> array_3D = {(is, tensor<T, up_t, up_t, up_t>::random_tensor_ct(lowerBound, upperBound))...};


    constexpr auto pick_random_tensor_0D() const{
        return array_0D[uniform_distribution<int>(0, 100000+size) % size];
    }
    constexpr auto pick_random_tensor_1D() const{
        return array_1D[uniform_distribution<int>(0, 100000+size) % size];
    }
    constexpr auto pick_random_tensor_2D() const{
        return array_2D[uniform_distribution<int>(0, 100000+size) % size];
    }
    constexpr auto pick_random_tensor_3D() const{
        return array_3D[uniform_distribution<int>(0, 100000+size) % size];
    }

    constexpr random_tensor_generator_ct(){

        static_assert((std::is_same<T, int>::value || std::is_same<T, float>::value), "only float or int is allowed");

    };
};

template<typename T, std::size_t size, std::size_t lowerBound, std::size_t upperBound>
using random_tensor_generator_compiletime = random_tensor_generator_ct<T, size, lowerBound, upperBound, std::make_index_sequence<size>>;




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

    //compares to a contraction<0,1>
    template<typename T>
    tensor_rt<T, up_t, up_t, up_t, up_t, up_t> for_loop_double_contraction_3D(tensor_rt<T, up_t, up_t, up_t, up_t> tensor1, tensor_rt<T, up_t, up_t, up_t> tensor2) {

        tensor_rt<T, up_t, up_t, up_t, up_t, up_t> tensor3;

        for (int i = 0; i < DIM3; i++) { //rows

            for (int j = 0; j < DIM3; j++) { //columns

                for (int l = 0; l < DIM3; l++) {

                    for (int k = 0; k < DIM3; k++) {

                        for (int m = 0; m < DIM3; m++) {

                            for (int n = 0; n < DIM3; n++) {

                                for (int o = 0; o < DIM3; o++) {

                                    for (int d = 0; d < DIM3; d++) {
                                        tensor3.data[pos_nd_to_1d(j, l, k, m, o)] +=
                                                tensor1.data[pos_nd_to_1d(i, j, l, k)] *
                                                tensor2.data[pos_nd_to_1d(m, n, o)];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return tensor3;
    }

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



template <typename T, typename U>
struct selector;

template <typename T, std::size_t... Is>
struct selector<T, std::index_sequence<Is...>>
{
    using type = std::tuple<typename std::tuple_element<Is, T>::type...>;
};

template <std::size_t N, typename... Ts>
struct remove_last_n
{
    using Indices = std::make_index_sequence<sizeof...(Ts)-N>;
    using type = typename selector<std::tuple<Ts...>, Indices>::type;
};

#endif //UNTITELED1_SPEED_TEST_TENSORS_H
