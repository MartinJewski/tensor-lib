//
// Created by martin on 29.02.20.
//

#ifndef UNTITELED1_SPEED_TEST_RANGES_TRACE_H
#define UNTITELED1_SPEED_TEST_RANGES_TRACE_H

#include "speed_test_tensors.h"
#include "reorder.h"

#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */

template<typename T>
auto speed_test_ranges_trace(){

    std::cout << "_________________START UNIT TEST:__RANGES_TRACE________" << std::endl;

    std::vector<int> times{};

    int count1 = 0;
    int count2 = 0;
    unitTest_tensor_range tensors_range;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);
    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_trace fl_trace;

    std::vector<int> firstTest;
    std::vector<int> secondTest;

    srand(time(0));

    int reps = 2000000;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = trace_ranges(tensor_generator_ranges.pick_random_tensor_2D());

        firstTest.push_back(result);
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto t3 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = fl_trace.for_loop_trace_2D(tensor_generator.pick_random_tensor_2D());
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    //time calculations
    count1 = duration1 / reps;
    count2 = duration2 / reps;

    std::cout << "TRACE_ALGO_RANGES(nano sec) :" << count1 << std::endl;
    std::cout << "TRACE_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout << "FOR_LOOP_SPEED_UP FACTOR:" << (float)count1/count2 << std::endl;
    std::cout << "CONTRACTION SPEED UP FACTOR:" << (float)count2/count1 << std::endl;


    std::cout << "_______________END UNIT TEST:__RANGES_TRACE______________" << std::endl;

    return std::vector<float> {count1, count2};
}



#endif //UNTITELED1_SPEED_TEST_RANGES_TRACE_H
