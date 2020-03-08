//
// Created by martin on 06.03.20.
//

#ifndef UNTITELED1_SPEED_TEST_FORLOOP_CONTRACTION_H
#define UNTITELED1_SPEED_TEST_FORLOOP_CONTRACTION_H


#include "speed_test_tensors.h"
#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */

using nano_s = std::chrono::nanoseconds;
using micro_s = std::chrono::microseconds;
using milli_s = std::chrono::milliseconds;
using seconds = std::chrono::seconds;

template<typename T>
int constexpr speed_test_forLoop_contraction(){
    std::cout << "_________________START SPEED TEST:__FOR_LOOP_CONTRACTION_____________" << std::endl;

    int count2 = 0;
    int reps = 2000000;

    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor_rt<T, up_t, up_t>> secondTest;

    srand(time(0));
    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D());
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count2 = duration2 / reps;

    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout << std::endl;

    return count2;
}

template<typename T>
int constexpr speed_test_double_forLoop_contraction(){
    std::cout << "_________________START SPEED TEST:__DOUBLE_FOR_LOOP_CONTRACTION_____________" << std::endl;

    int count2 = 0;
    int reps = 2000000;

    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor_rt<T, up_t, up_t>> secondTest;

    srand(time(0));
    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(),
                fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D()));
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count2 = duration2 / reps;


    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout  << std::endl;

    return count2;
}


template<typename T>
int constexpr speed_test_triple_forLoop_contraction(){
    std::cout << "_________________START SPEED TEST:__TRIPLE_FOR_LOOP_CONTRACTION_____________" << std::endl;

    int count2 = 0;
    int reps = 2000000;

    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor_rt<T, up_t, up_t>> secondTest;

    srand(time(0));
    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(),
                fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(),
                                                             fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D())));
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count2 = duration2 / reps;


    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout  << std::endl;

    return count2;
}

/**
 *
 *  3D
 */


template<typename T>
int constexpr speed_test_forLoop_contraction3D(){
    std::cout << "_________________START SPEED TEST:__FOR_LOOP_CONTRACTION_____________" << std::endl;

    int count2 = 0;
    int reps = 2000000;

    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor_rt<T, up_t, up_t, up_t>> secondTest;

    srand(time(0));
    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_calculation.for_loop_contraction_3D(tensor_generator.pick_random_tensor_3D(), tensor_generator.pick_random_tensor_3D());
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count2 = duration2 / reps;

    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout << std::endl;

    return count2;
}

template<typename T>
int constexpr speed_test_double_forLoop_contraction3D(){
    std::cout << "_________________START SPEED TEST:__DOUBLE_FOR_LOOP_CONTRACTION_____________" << std::endl;

    int count2 = 0;
    int reps = 2000000;

    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor_rt<T, up_t, up_t, up_t>> secondTest;

    srand(time(0));
    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_calculation.for_loop_contraction_3D(tensor_generator.pick_random_tensor_3D(),
                                                             fl_calculation.for_loop_contraction_3D(tensor_generator.pick_random_tensor_3D(), tensor_generator.pick_random_tensor_3D()));
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count2 = duration2 / reps;


    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout  << std::endl;

    return count2;
}


template<typename T>
int constexpr speed_test_triple_forLoop_contraction3D(){
    std::cout << "_________________START SPEED TEST:__TRIPLE_FOR_LOOP_CONTRACTION_____________" << std::endl;

    int count2 = 0;
    int reps = 2000000;

    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor_rt<T, up_t, up_t, up_t>> secondTest;

    srand(time(0));
    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_calculation.for_loop_contraction_3D(tensor_generator.pick_random_tensor_3D(),
                                                             fl_calculation.for_loop_contraction_3D(tensor_generator.pick_random_tensor_3D(),
                                                                                                    fl_calculation.for_loop_contraction_3D(tensor_generator.pick_random_tensor_3D(), tensor_generator.pick_random_tensor_3D())));
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count2 = duration2 / reps;


    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout  << std::endl;

    return count2;
}

#endif //UNTITELED1_SPEED_TEST_FORLOOP_CONTRACTION_H
