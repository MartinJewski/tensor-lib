//
// Created by martin on 06.03.20.
//

#ifndef UNTITELED1_SPEED_TEST_FORLOOP_TRACE_H
#define UNTITELED1_SPEED_TEST_FORLOOP_TRACE_H

#include "speed_test_tensors.h"
#include "trace_ct.h"

#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */

template<typename T>
auto speed_test_forLoop_trace(){

    std::cout << "_________________START UNIT TEST:__FOR_LOOP_TRACE_____________" << std::endl;

    int count2 = 0;
    int reps = 2000000;

    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_trace fl_trace;

    std::vector<T> secondTest;

    srand(time(0));

    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_trace.for_loop_trace_2D(tensor_generator.pick_random_tensor_2D());
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();

    count2 = duration2 / reps;

    std::cout << "TRACE_FOR_LOOP(nano sec) :" << count2 << std::endl;

    std::cout << "_________________END UNIT TEST:__COMPILETIME_TRACE_____________" << std::endl;

    return count2;
}




#endif //UNTITELED1_SPEED_TEST_FORLOOP_TRACE_H
