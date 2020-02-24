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

    int count = 0;
    unitTest_tensor_range tensors_range;

    int reps = 2000000;

    auto t1 = std::chrono::high_resolution_clock::now();

    for(int val = 0; val < reps; val++){

        auto result = contraction_ranges<0,1>
                (tensorRange<int, up_t, up_t>::random_tensor_range(0,10), tensorRange<int, up_t, up_t>::random_tensor_range(0,10));

        auto result2 = contraction_ranges<0,0>(tensorRange<int, up_t, up_t>::random_tensor_range(0,10), result);
    }

    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    //time calculations
    count = duration / reps;

    std::cout << " " << std::endl;
    std::cout << "average time in nano sec :" << count << std::endl;


    std::cout << "....";
    std::cout << "_________________END UNIT TEST:__RANGES__________________";
}



#endif //UNTITELED1_UNITTEST_RANGES_H
