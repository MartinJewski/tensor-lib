//
// Created by martin on 29.02.20.
//



#ifndef UNTITELED1_COMPONENT_TEST_RUNTIME_REORDER_H
#define UNTITELED1_COMPONENT_TEST_RUNTIME_REORDER_H

#include "speed_test_tensors.h"
#include "reorder.h"

#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */


template<typename T>
auto speed_test_runtime_reorder(){

    //std::cout << "_____SPEED TEST:__RUNTIME_REORDER2D__" << std::endl;

    int count1 = 0;
    int reps = REP;

    random_tensor_generator_compiletime<T, 10, 0, 10> tensor_generator;


    std::vector<tensor<T, up_t, up_t>> firstTest;

    srand(time(0));

    std::size_t times = 0;


    //auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){
        auto t1 = std::chrono::high_resolution_clock::now();
        auto result = reorder<1,0>(tensor_generator.pick_random_tensor_2D());
        auto t2 = std::chrono::high_resolution_clock::now();

        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        firstTest.push_back(result);
        times += duration1;

    }
    //auto t2 = std::chrono::high_resolution_clock::now();

    //auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //count1 = duration1 / reps;

    //std::cout << "REORDER_ALGO(nano sec) :" << count1 << std::endl;
    //std::cout  << std::endl;

    //return count1;
    return (times/reps);
}


template<typename T>
auto speed_test_runtime_reorder3D(){

    //std::cout << "_____START SPEED TEST:__RUNTIME_REORDER3D__" << std::endl;

    int count1 = 0;
    int reps = REP;

     random_tensor_generator_compiletime<T, 10, 0, 10> tensor_generator;

    std::vector<tensor<T, up_t, up_t, up_t>> firstTest;
    srand(time(0));

    std::size_t times = 0;


    //auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto t1 = std::chrono::high_resolution_clock::now();
        auto result = reorder<2,1,0>(tensor_generator.pick_random_tensor_3D());
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        //firstTest.push_back(result);
        times += duration1;
        firstTest.push_back(result);
    }
    //auto t2 = std::chrono::high_resolution_clock::now();

    //auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //count1 = duration1 / reps;

    //std::cout << "REORDER_ALGO(nano sec) :" << count1 << std::endl;
    //std::cout  << std::endl;

    //return count1;
    return (times/reps);
}

#endif //UNTITELED1_COMPONENT_TEST_RUNTIME_REORDER_H
