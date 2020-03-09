//
// Created by martin on 16.02.20.
//

#ifndef UNTITELED1_SPEED_TEST_RANGES_CONTRACTION_H
#define UNTITELED1_SPEED_TEST_RANGES_CONTRACTION_H

//#include "unitTest_tensors.h"
#include "contraction_ranges.h"
#include "tensor_range.h"

#include <chrono>
#include <tuple>
#include <time.h>

using nano_s = std::chrono::nanoseconds;
using micro_s = std::chrono::microseconds;
using milli_s = std::chrono::milliseconds;
using seconds = std::chrono::seconds;

template<typename T>
auto speed_test_ranges_contraction(){

    std::cout << "_____________START SPEED TEST:__RANGES__CONTRACTION___________" << std::endl;

    int count1 = 0;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);

    std::vector<tensorRange<T, up_t, up_t>> firstTest;

    srand(time(0));

    int reps = REP;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = contraction_ranges<0,1>
                (tensor_generator_ranges.pick_random_tensor_2D(), tensor_generator_ranges.pick_random_tensor_2D());
        //firstTest.push_back(result);
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //time calculations
    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO_RANGES(nano sec) :" << count1 << std::endl;


    return count1;
}


template<typename T>
auto speed_test_ranges_double_contraction(){

    std::cout << "_________________START SPEED TEST:__RANGES__DOUBLE_CONTRACTION________" << std::endl;

    int count1 = 0;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);

    std::vector<tensorRange<T, up_t, up_t>> firstTest;

    srand(time(0));

    int reps = REP;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = contraction_ranges<0,1>(tensor_generator_ranges.pick_random_tensor_2D(), contraction_ranges<0,1>
                (tensor_generator_ranges.pick_random_tensor_2D(), tensor_generator_ranges.pick_random_tensor_2D()));
        //firstTest.push_back(result);
    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //time calculations
    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO_RANGES(nano sec) :" << count1 << std::endl;


    return count1;
}


template<typename T>
auto speed_test_ranges_triple_contraction(){

    std::cout << "_________________START SPEED TEST:__RANGES__TRIPLE_CONTRACTION________" << std::endl;

    int count1 = 0;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);

    std::vector<tensorRange<T, up_t, up_t>> firstTest;

    srand(time(0));

    int reps = REP;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = contraction_ranges<0,1>(tensor_generator_ranges.pick_random_tensor_2D(),
                contraction_ranges<0,1>(tensor_generator_ranges.pick_random_tensor_2D(), contraction_ranges<0,1>
                (tensor_generator_ranges.pick_random_tensor_2D(), tensor_generator_ranges.pick_random_tensor_2D())));
        //firstTest.push_back(result);
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //time calculations
    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO_RANGES(nano sec) :" << count1 << std::endl;

    return count1;
}


/**
 * 3D
 *
 */



template<typename T>
auto speed_test_ranges_contraction3D(){

    std::cout << "_____________START SPEED TEST:__RANGES__CONTRACTION___________" << std::endl;

    int count1 = 0;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);

    std::vector<tensorRange<T, up_t, up_t, up_t, up_t>> firstTest;

    srand(time(0));

    int reps = REP;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = contraction_ranges<0,1>
                (tensor_generator_ranges.pick_random_tensor_3D(), tensor_generator_ranges.pick_random_tensor_3D());
        //firstTest.push_back(result);
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //time calculations
    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO_RANGES(nano sec) :" << count1 << std::endl;

    return count1;
}


template<typename T>
auto speed_test_ranges_double_contraction3D(){

    std::cout << "_________________START SPEED TEST:__RANGES__DOUBLE_CONTRACTION________" << std::endl;

    int count1 = 0;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);

    std::vector<tensorRange<T, up_t, up_t, up_t, up_t, up_t>> firstTest;

    srand(time(0));

    int reps = REP;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = contraction_ranges<0,1>(tensor_generator_ranges.pick_random_tensor_3D(), contraction_ranges<0,1>
                (tensor_generator_ranges.pick_random_tensor_3D(), tensor_generator_ranges.pick_random_tensor_3D()));

        //firstTest.push_back(result);
    }
    auto t2 = std::chrono::high_resolution_clock::now();


    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //time calculations
    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO_RANGES(nano sec) :" << count1 << std::endl;

    return count1;
}


template<typename T>
auto speed_test_ranges_triple_contraction3D(){

    std::cout << "_________________START UNIT TEST:__RANGES__TRIPLE_CONTRACTION________" << std::endl;

    int count1 = 0;

    random_tensor_generator_ranges<T, 10> tensor_generator_ranges(0, 10);

    std::vector<tensorBase_ranges<T, std::tuple<up_t, up_t, up_t, up_t, up_t, up_t>>> firstTest;

    srand(time(0));

    int reps = REP;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = contraction_ranges<0,1>(tensor_generator_ranges.pick_random_tensor_3D(),
                                              contraction_ranges<0,1>(tensor_generator_ranges.pick_random_tensor_3D(), contraction_ranges<0,1>
                                                      (tensor_generator_ranges.pick_random_tensor_3D(), tensor_generator_ranges.pick_random_tensor_3D())));
        //firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    //time calculations
    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO_RANGES(nano sec) :" << count1 << std::endl;


    return count1;
}


#endif //UNTITELED1_SPEED_TEST_RANGES_CONTRACTION_H
