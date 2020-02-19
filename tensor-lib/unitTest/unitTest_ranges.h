//
// Created by martin on 16.02.20.
//

#ifndef UNTITELED1_UNITTEST_RANGES_H
#define UNTITELED1_UNITTEST_RANGES_H

#include "unitTest_tensors.h"
#include "contraction_ranges.h"
#include "reorder_ranges.h"
#include "trace_ranges.h"
#include <chrono>
#include <tuple>

using nano_s = std::chrono::nanoseconds;
using micro_s = std::chrono::microseconds;
using milli_s = std::chrono::milliseconds;
using seconds = std::chrono::seconds;

void unitTest_ranges(){

    std::cout << "_________________START UNIT TEST:__RANGES__________________" << std::endl;
    std::cout << "...." << std::endl;

    std::vector<int> times{};
    int accu = 0;
    unitTest_tensor_range tensors_range;
    int reps = 2000000;
    for(int val = 0; val < reps; val++){
        unitTest_tensor_range tensors_range;

        auto t1 = std::chrono::high_resolution_clock::now();
        auto result = contraction_ranges<0,1>(tensors_range.tensor_sequence_2D_int, tensors_range.tensor_sequence_2D_int);
        auto t2 = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

        times.push_back(duration);
        accu += duration;
    }

    accu = accu / reps;
    /*
    for(auto ele : times){
        std::cout << " " << ele << " ";
    }
     */
    std::cout << " " << std::endl;
    std::cout << "average time in nano sec :" << accu << std::endl;


    std::cout << "....";
    std::cout << "_________________END UNIT TEST:__RANGES__________________";
}



#endif //UNTITELED1_UNITTEST_RANGES_H
