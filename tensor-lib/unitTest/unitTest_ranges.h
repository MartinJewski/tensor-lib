//
// Created by martin on 16.02.20.
//

#ifndef UNTITELED1_UNITTEST_RANGES_H
#define UNTITELED1_UNITTEST_RANGES_H

//#include "unitTest_tensors.h"
#include "contraction_ranges.h"
#include "reorder_ranges.h"
#include "trace_ranges.h"
#include "tensor_range.h"

#include <chrono>
#include <tuple>
#include <time.h>

using nano_s = std::chrono::nanoseconds;
using micro_s = std::chrono::microseconds;
using milli_s = std::chrono::milliseconds;
using seconds = std::chrono::seconds;

void unitTest_ranges(){

    std::cout << "_________________START UNIT TEST:__RANGES__________________" << std::endl;
    std::cout << "...." << std::endl;

    std::vector<int> times{};

    int count1 = 0;
    int count2 = 0;
    unitTest_tensor_range tensors_range;

    random_tensor_generator_ranges<int, 10> tensor_generator_ranges(0, 10);
    random_tensor_generator<int, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensorRange<int, up_t, up_t>> firstTest;
    std::vector<tensor_rt<int, up_t, up_t>> secondTest;

    srand(time(0));

    int reps = 2000000;

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = contraction_ranges<0,1>
                (tensor_generator_ranges.pick_random_tensor_2D(), tensor_generator_ranges.pick_random_tensor_2D());
        firstTest.push_back(result);
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto t3 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D());
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    //time calculations
    count1 = duration1 / reps;
    count2 = duration2 / reps;

    std::cout << " " << std::endl;
    std::cout << "CONTRACTION_ALGO_RANGES(nano sec) :" << count1 << std::endl;
    std::cout << " " << std::endl;
    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout << "FOR_LOOP_SPEED_UP:" << (float)count1/count2 << std::endl;


    std::cout << "....";
    std::cout << "_________________END UNIT TEST:__RANGES__________________";
}



#endif //UNTITELED1_UNITTEST_RANGES_H
