//
// Created by martin on 13.02.20.
//

#ifndef UNTITELED1_SPEED_TEST_COMPILETIME_CONTRACTION_H
#define UNTITELED1_SPEED_TEST_COMPILETIME_CONTRACTION_H

#include "speed_test_tensors.h"
#include "contraction_ct.h"
#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */

using nano_s = std::chrono::nanoseconds;
using micro_s = std::chrono::microseconds;
using milli_s = std::chrono::milliseconds;
using seconds = std::chrono::seconds;

template<typename T>
auto constexpr speed_test_compileTime_contraction(){

    std::cout << "_________________START SPEED TEST:__COMPILE_TIME_CONTRACTION_____________" << std::endl;

    int count1 = 0;

    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    std::vector<tensor<T, up_t, up_t>> firstTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = contraction<0,1, generator_ct.pick_random_tensor_2D(), generator_ct.pick_random_tensor_2D()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;

    std::cout  << std::endl;

    return count1;
}


template<typename T>
auto constexpr speed_test_double_compileTime_contraction(){

    std::cout << "_________________START SPEED TEST:__COMPILE_TIME_DOUBLE_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    std::vector<tensor<T, up_t, up_t>> firstTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = contraction<0, 1, generator_ct.pick_random_tensor_2D(), contraction<0,1, generator_ct.pick_random_tensor_2D(), generator_ct.pick_random_tensor_2D()>()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;
    std::cout << std::endl;

    return count1;
}


template<typename T>
auto constexpr speed_test_triple_compileTime_contraction(){

    std::cout << "_________________START SPEED TEST:__COMPILE_TIME_TRIPLE_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    std::vector<tensor<T, up_t, up_t>> firstTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = contraction<0,1, generator_ct.pick_random_tensor_2D(),
                contraction<0,1, generator_ct.pick_random_tensor_2D(),
                        contraction<0,1, generator_ct.pick_random_tensor_2D(), generator_ct.pick_random_tensor_2D()>()>()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;

    std::cout  << std::endl;

    return count1;
}

template<typename T>
auto constexpr speed_test_quadruple_compileTime_contraction(){

    std::cout << "_________________START SPEED TEST:__COMPILE_TIME_QUADRUPLE_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    std::vector<tensor<T, up_t, up_t>> firstTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result =
                contraction<0,1, generator_ct.pick_random_tensor_2D(),
                contraction<0,1, generator_ct.pick_random_tensor_2D(),
                contraction<0,1, generator_ct.pick_random_tensor_2D(),
                        contraction<0,1, generator_ct.pick_random_tensor_2D(), generator_ct.pick_random_tensor_2D()>()>()>()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;

    std::cout << std::endl;

    return count1;
}

/**
 * 3d
 *
 */


template<typename T>
auto constexpr speed_test_compileTime_contraction3D(){

    std::cout << "_________________START SPEED TEST:__COMPILE_TIME_CONTRACTION_____________" << std::endl;

    int count1 = 0;

    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    std::vector<tensor<T, up_t, up_t, up_t, up_t>> firstTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = contraction<0,1, generator_ct.pick_random_tensor_3D(), generator_ct.pick_random_tensor_3D()>();

        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;

    std::cout  << std::endl;

    return count1;
}


template<typename T>
auto constexpr speed_test_double_compileTime_contraction3D(){

    std::cout << "_________________START SPEED TEST:__COMPILE_TIME_DOUBLE_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    std::vector<tensor<T, up_t, up_t, up_t, up_t, up_t>> firstTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = contraction<0, 1, generator_ct.pick_random_tensor_3D(), contraction<0,1, generator_ct.pick_random_tensor_3D(), generator_ct.pick_random_tensor_3D()>()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;
    std::cout << std::endl;

    return count1;
}


template<typename T>
auto constexpr speed_test_triple_compileTime_contraction3D(){

    std::cout << "_________________START SPEED TEST:__COMPILE_TIME_TRIPLE_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    std::vector<tensor<T, up_t, up_t, up_t>> firstTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = contraction<0,1, generator_ct.pick_random_tensor_3D(),
                contraction<0,1, generator_ct.pick_random_tensor_3D(),
                        contraction<0,1, generator_ct.pick_random_tensor_3D(), generator_ct.pick_random_tensor_3D()>()>()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;

    std::cout  << std::endl;

    return count1;
}

template<typename T>
auto constexpr speed_test_quadruple_compileTime_contraction3D(){

    std::cout << "_________________START SPEED TEST:__COMPILE_TIME_QUADRUPLE_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    std::vector<tensor<T, up_t, up_t, up_t>> firstTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result =
                contraction<0,1, generator_ct.pick_random_tensor_3D(),
                        contraction<0,1, generator_ct.pick_random_tensor_3D(),
                                contraction<0,1, generator_ct.pick_random_tensor_3D(),
                                        contraction<0,1, generator_ct.pick_random_tensor_3D(), generator_ct.pick_random_tensor_3D()>()>()>()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;

    std::cout << std::endl;

    return count1;
}

#endif //UNTITELED1_SPEED_TEST_COMPILETIME_CONTRACTION_H
