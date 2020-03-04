//
// Created by martin on 04.03.20.
//

#ifndef UNTITELED1_SPEED_TEST_COMPILETIME_REORDER_H
#define UNTITELED1_SPEED_TEST_COMPILETIME_REORDER_H

#include "speed_test_tensors.h"
#include "reorder.h"

#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */


template<typename T>
auto speed_test_compileTime_reorder(){

    std::cout << "_____START UNIT TEST:__COMPILE_TIME_REORDER__" << std::endl;

    int count1 = 0;
    int count2 = 0;
    int reps = 2000000;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;
    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_reorder fl_reorder;

    std::vector<tensor<T, up_t, up_t>> firstTest;
    std::vector<tensor_rt<T, up_t, up_t>> secondTest;

    srand(time(0));


    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = reorder<generator_ct.pick_random_tensor_2D(), 1,0>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_reorder.for_loop_reordering_2D(tensor_generator.pick_random_tensor_2D());
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count1 = duration1 / reps;
    count2 = duration2 / reps;

    std::cout << "REORDER_ALGO(nano sec) :" << count1 << std::endl;
    std::cout << "REORDER_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout << "FOR_LOOP_SPEED_UP FACTOR:" << (float)count1/count2 << std::endl;
    std::cout << "REORDER SPEED UP FACTOR:" << (float)count2/count1 << std::endl;

    std::cout << "_________________END UNIT TEST:__COMPILE_TIME_REORDER_____________" << std::endl;

    return std::vector<float> {count1, count2};
}


#endif //UNTITELED1_SPEED_TEST_COMPILETIME_REORDER_H
