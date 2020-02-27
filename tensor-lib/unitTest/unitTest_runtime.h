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
    int count1 = 0;
    int count2 = 0;
    int reps = 2000000;

    random_tensor_generator<int, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor_rt<int, up_t, up_t>> firstTest;
    std::vector<tensor_rt<int, up_t, up_t>> secondTest;

    srand(time(0));
    //auto tensor_rnd_2D_1 = tensor_generator.pick_random_tensor_2D();
    //auto tensor_rnd_2D_2 = tensor_generator.pick_random_tensor_2D();

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){
        unitTest_tensor_rt tensors_rt;

        auto result = contraction<0,1>(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D());
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D());
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count1 = duration1 / reps;
    count2 = duration2 / reps;

    std::cout << " " << std::endl;
    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;
    std::cout << " " << std::endl;
    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout << "FOR_LOOP_SPEED_UP:" << (float)count1/count2 << std::endl;

    std::cout << "...." << std::endl;
    std::cout << "_________________END UNIT TEST:__RUNTIME__________________" << std::endl;
}

#endif //UNTITELED1_UNITTEST_RUNTIME_H
























