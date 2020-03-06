//
// Created by martin on 13.02.20.
//

#ifndef UNTITELED1_SPEED_TEST_RUNTIME_CONTRACTION_H
#define UNTITELED1_SPEED_TEST_RUNTIME_CONTRACTION_H

#include "speed_test_tensors.h"
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

template<typename T>
auto speed_test_runtime_contraction(){

    std::cout << "_________________START UNIT TEST:__RUNTIME_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int reps = 2000000;

    random_tensor_generator<T, 10> tensor_generator(0, 10);

    std::vector<tensor_rt<T, up_t, up_t>> firstTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = contraction<0,1>(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D());
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;


    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;


    std::cout << "_________________END UNIT TEST:__RUNTIME__________________" << std::endl;

    return count1;
}



template<typename T>
auto speed_test_runtime_double_contraction(){

    std::cout << "_____START UNIT TEST:__RUNTIME_DOUBLE_CONTRACTION___" << std::endl;

    int count1 = 0;
    int reps = 2000000;

    random_tensor_generator<T, 10> tensor_generator(0, 10);

    std::vector<tensor_rt<T, up_t, up_t>> firstTest;

    srand(time(0));


    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = contraction<0,1>(tensor_generator.pick_random_tensor_2D(),
                contraction<0,1>(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D()));
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;


    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;


    std::cout << "_________________END UNIT TEST:__RUNTIME__________________" << std::endl;

    return count1;
}



template<typename T>
auto speed_test_runtime_triple_contraction(){

    std::cout << "_____START UNIT TEST:__RUNTIME_TRIPLE_CONTRACTION___" << std::endl;

    int count1 = 0;
    int reps = 2000000;

    random_tensor_generator<T, 10> tensor_generator(0, 10);

    std::vector<tensor_rt<T, up_t, up_t>> firstTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto result = contraction<0,1>(tensor_generator.pick_random_tensor_2D(),
                contraction<0,1>(tensor_generator.pick_random_tensor_2D(),
                                       contraction<0,1>(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D())));
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

    count1 = duration1 / reps;

    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;

    std::cout << "_________________END UNIT TEST:__RUNTIME__________________" << std::endl;

    return count1;
}



#endif //UNTITELED1_SPEED_TEST_RUNTIME_CONTRACTION_H
























