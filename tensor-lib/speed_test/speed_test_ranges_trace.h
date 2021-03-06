//
// Created by martin machajewski on 29.02.20.
//

#ifndef UNTITELED1_SPEED_TEST_RANGES_TRACE_H
#define UNTITELED1_SPEED_TEST_RANGES_TRACE_H

#include "speed_test_tensors.h"
#include "trace_contraction_ranges.h"

#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */

template<typename T>
auto speed_test_ranges_trace(){

    //std::cout << "________________START SPEED TEST:__RANGES_TRACE________" << std::endl;

    int count1 = 0;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);

    std::vector<int> firstTest;

    srand(time(0));

    std::size_t times = 0;

    int reps = REP;

    //auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto t1 = std::chrono::high_resolution_clock::now();
        volatile auto result = trace_contraction_ranges<0,1>(tensor_generator_ranges.pick_random_tensor_2D());
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

        times += duration1;
        //firstTest.push_back(result);
    }
    //auto t2 = std::chrono::high_resolution_clock::now();


    //auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //time calculations
    //count1 = duration1 / reps;

    //std::cout << "TRACE_ALGO_RANGES(nano sec) :" << count1 << std::endl;

    //std::cout  << std::endl;
    //return count1;
    return (times/reps);
}



template<typename T>
auto speed_test_ranges_trace3D(){

    //std::cout << "_________________START SPEED TEST:__RANGES_TRACE_3D______" << std::endl;

    int count1 = 0;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);

    std::vector<tensorBase_ranges<int, std::tuple<up_t>> > firstTest;

    srand(time(0));

    std::size_t times = 0;

    int reps = REP;

    //auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto t1 = std::chrono::high_resolution_clock::now();
        volatile auto result = trace_contraction_ranges<0,1>(tensor_generator_ranges.pick_random_tensor_3D());
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        //firstTest.push_back(result);
        times += duration1;
    }
    //auto t2 = std::chrono::high_resolution_clock::now();

    //auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //time calculations
    //count1 = duration1 / reps;

   // std::cout << "TRACE_ALGO_RANGES(nano sec) :" << count1 << std::endl;

   // std::cout  << std::endl;

    //return count1;
    return (times/reps);
}




#endif //UNTITELED1_SPEED_TEST_RANGES_TRACE_H
