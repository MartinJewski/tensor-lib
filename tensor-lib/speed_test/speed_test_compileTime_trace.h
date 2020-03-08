//
// Created by martin on 04.03.20.
//

#ifndef UNTITELED1_SPEED_TEST_COMPILETIME_TRACE_H
#define UNTITELED1_SPEED_TEST_COMPILETIME_TRACE_H

#include "speed_test_tensors.h"
#include "trace_ct.h"

#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */

template<typename T>
auto speed_test_compileTime_trace(){

    std::cout << "_________________START SPEED TEST:__COMPILETIME_TRACE_____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    for_loop_trace fl_trace;

    std::vector<int> firstTest;


    srand(time(0));


    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = trace<generator_ct.pick_random_tensor_2D()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "TRACE_ALGO(nano sec) :" << count1 << std::endl;

    std::cout  << std::endl;

    return count1;
}




template<typename T>
auto speed_test_compileTime_trace3D(){

    std::cout << "_________________START SPEED TEST:__COMPILETIME_TRACE_____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    for_loop_trace fl_trace;

    std::vector<int> firstTest;


    srand(time(0));


    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = trace<generator_ct.pick_random_tensor_3D()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "TRACE_ALGO(nano sec) :" << count1 << std::endl;

    std::cout  << std::endl;

    return count1;
}



#endif //UNTITELED1_SPEED_TEST_COMPILETIME_TRACE_H
