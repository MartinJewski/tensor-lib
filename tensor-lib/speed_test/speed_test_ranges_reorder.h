//
// Created by martin on 29.02.20.
//

#ifndef UNTITELED1_SPEED_TEST_RANGES_REORDER_H
#define UNTITELED1_SPEED_TEST_RANGES_REORDER_H

#include "reorder_ranges.h"

#include <chrono>
#include <tuple>
#include <time.h>

template<typename T>
auto speed_test_ranges_reorder(){
    std::cout << "_________________START SPEED TEST:__RANGES__REORDER________" << std::endl;

    int count1 = 0;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);


    std::vector<tensorRange<T, up_t, up_t>> firstTest;

    srand(time(0));

    int reps = REP;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = reorder_ranges<1,0>(tensor_generator_ranges.pick_random_tensor_2D());
        //firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //time calculations
    count1 = duration1 / reps;

    std::cout << "REORDER_ALGO_RANGES(nano sec) :" << count1 << std::endl;

    std::cout << std::endl;

    return count1;
}



template<typename T>
auto speed_test_ranges_reorder3D(){
    std::cout << "_________________START SPEED TEST:__RANGES__REORDER________" << std::endl;

    int count1 = 0;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);


    std::vector<tensorRange<T, up_t, up_t, up_t>> firstTest;

    srand(time(0));

    int reps = REP;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = reorder_ranges<1,0>(tensor_generator_ranges.pick_random_tensor_3D());
        //firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //time calculations
    count1 = duration1 / reps;

    std::cout << "REORDER_ALGO_RANGES(nano sec) :" << count1 << std::endl;

    std::cout << std::endl;

    return count1;
}

#endif //UNTITELED1_SPEED_TEST_RANGES_REORDER_H
