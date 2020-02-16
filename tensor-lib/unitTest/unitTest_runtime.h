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
using nano_s = std::chrono::nanoseconds;
using micro_s = std::chrono::microseconds;
using milli_s = std::chrono::milliseconds;
using seconds = std::chrono::seconds;

void unitTest_runtime(){

    std::cout << "_________________START UNIT TEST:__RUNTIME__________________" << std::endl;
    std::cout << "...." << std::endl;

    std::vector<int> times{};
    int accu = 0;

    for(int val = 0; val < 10000; val++){
        unitTest_tensor_rt tensors_rt;
        auto t1 = std::chrono::steady_clock::now();
        auto result = contraction<0,1>(tensors_rt.tensor_sequence_2D_int, tensors_rt.tensor_sequence_2D_int);
        auto t2 = std::chrono::steady_clock::now();
        auto n_s = std::chrono::duration_cast<nano_s>( t2 - t1 ).count();
        auto mc_s = std::chrono::duration_cast<micro_s>( t2 - t1 ).count();
        auto m_s = std::chrono::duration_cast<milli_s>( t2 - t1 ).count();
        auto d_s = std::chrono::duration_cast<seconds>( t2 - t1 ).count();
        //std::cout << "time to calculate nano seconds: " << n_s << std::endl;
        //std::cout << "time to calculate micro seconds: " << mc_s << std::endl;
        //std::cout << "time to calculate milli seconds: " << m_s << std::endl;
        //std::cout << "time to calculate seconds: " << d_s << std::endl;
        times.push_back(n_s);
        accu += n_s;
    }
    accu = accu / 10000;
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
























