//
// Created by martin on 13.02.20.
//

#ifndef UNTITELED1_UNITTEST_RUNTIME_H
#define UNTITELED1_UNITTEST_RUNTIME_H

#include "unitTest_tensors.h"
#include "contraction.h"
#include "reorder.h"
#include "trace.h"
#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */

using nano_s = std::chrono::nanoseconds;
using micro_s = std::chrono::microseconds;
using milli_s = std::chrono::milliseconds;
using seconds = std::chrono::seconds;


void unitTest_runtime(){

    std::cout << "_________________START UNIT TEST:__RUNTIME__________________" << std::endl;
    std::cout << "...." << std::endl;

    std::vector<int> times{};
    int accu = 0;
    int reps = 2000000;

    for(int val = 0; val < reps; val++){
        unitTest_tensor_rt tensors_rt;

        auto t1 = std::chrono::high_resolution_clock::now();
        auto result = contraction<0,1>(tensors_rt.tensor_sequence_2D_int, tensors_rt.tensor_sequence_2D_int);
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
    std::cout << "...." << std::endl;
    std::cout << "_________________END UNIT TEST:__RUNTIME__________________" << std::endl;
}

#endif //UNTITELED1_UNITTEST_RUNTIME_H
























