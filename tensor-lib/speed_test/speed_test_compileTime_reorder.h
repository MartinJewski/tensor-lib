//
// Created by martin on 04.03.20.
//

#ifndef UNTITELED1_SPEED_TEST_COMPILETIME_REORDER_H
#define UNTITELED1_SPEED_TEST_COMPILETIME_REORDER_H

#include "speed_test_tensors.h"
#include "reorder.h"

#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */


template<typename T>
auto speed_test_compileTime_reorder(){

    std::cout << "_____START SPEED TEST:__COMPILE_TIME_REORDER__" << std::endl;

    int count1 = 0;

    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    std::vector<tensor<T, up_t, up_t>> firstTest;

    srand(time(0));


    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = reorder<generator_ct.pick_random_tensor_2D(), 1,0>();
        //firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "REORDER_ALGO(nano sec) :" << count1 << std::endl;

    std::cout << std::endl;

    return count1;
}



template<typename T>
auto speed_test_compileTime_reorder3D(){

    std::cout << "_____START SPEED TEST:__COMPILE_TIME_REORDER__" << std::endl;

    int count1 = 0;

    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;

    std::vector<tensor<T, up_t, up_t, up_t>> firstTest;

    srand(time(0));


    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = reorder<generator_ct.pick_random_tensor_3D(), 1,0>();
        //firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "REORDER_ALGO(nano sec) :" << count1 << std::endl;

    std::cout << std::endl;

    return count1;
}


#endif //UNTITELED1_SPEED_TEST_COMPILETIME_REORDER_H
