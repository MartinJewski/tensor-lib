//
// Created by martin on 13.02.20.
//

#ifndef UNTITELED1_SPEED_TEST_COMPILETIME_CONTRACTION_H
#define UNTITELED1_SPEED_TEST_COMPILETIME_CONTRACTION_H

#include "speed_test_tensors.h"
#include "contraction_ct.h"
#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */

using nano_s = std::chrono::nanoseconds;
using micro_s = std::chrono::microseconds;
using milli_s = std::chrono::milliseconds;
using seconds = std::chrono::seconds;

template<typename T>
void constexpr speed_test_compileTime_contraction(){

    std::cout << "_________________START UNIT TEST:__COMPILE_TIME_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int count2 = 0;
    int reps = 2000000;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;
    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor<T, up_t, up_t>> firstTest;
    std::vector<tensor_rt<T, up_t, up_t>> secondTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = contraction<0,1, generator_ct.pick_random_tensor_2D(), generator_ct.pick_random_tensor_2D()>();
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
    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout << "FOR_LOOP_SPEED_UP FACTOR:" << (float)count1/count2 << std::endl;
    std::cout << "CONTRACTION SPEED UP FACTOR:" << (float)count2/count1 << std::endl;

    std::cout << "_________________END UNIT TEST:__COMPILE_TIME__________________" << std::endl;

    return std::vector<float> {count1, count2};
}


template<typename T>
void constexpr speed_test_double_compileTime_contraction(){

    std::cout << "_________________START UNIT TEST:__COMPILE_TIME_DOUBLE_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int count2 = 0;
    int reps = 2000000;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;
    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor<T, up_t, up_t>> firstTest;
    std::vector<tensor_rt<T, up_t, up_t>> secondTest;generator_ct.pick_random_tensor_2D();

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = contraction<0, 1, generator_ct.pick_random_tensor_2D(), contraction<0,1, generator_ct.pick_random_tensor_2D(), generator_ct.pick_random_tensor_2D()>()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(),
                                                             fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D()));
        secondTest.push_back(result);

    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count1 = duration1 / reps;
    count2 = duration2 / reps;

    std::cout << " " << std::endl;
    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;
    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout << "FOR_LOOP_SPEED_UP FACTOR:" << (float)count1/count2 << std::endl;
    std::cout << "CONTRACTION SPEED UP FACTOR:" << (float)count2/count1 << std::endl;

    std::cout << "_________________END UNIT TEST:__COMPILE_TIME__________________" << std::endl;

    return std::vector<float> {count1, count2};
}


template<typename T>
void constexpr speed_test_triple_compileTime_contraction(){

    std::cout << "_________________START UNIT TEST:__COMPILE_TIME_TRIPLE_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int count2 = 0;
    int reps = 2000000;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;
    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor<T, up_t, up_t>> firstTest;
    std::vector<tensor_rt<T, up_t, up_t>> secondTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result = contraction<0,1, generator_ct.pick_random_tensor_2D(),
                contraction<0,1, generator_ct.pick_random_tensor_2D(),
                        contraction<0,1, generator_ct.pick_random_tensor_2D(), generator_ct.pick_random_tensor_2D()>()>()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(),
                                                             fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(),
                                                                                                    fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(), tensor_generator.pick_random_tensor_2D())));
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count1 = duration1 / reps;
    count2 = duration2 / reps;

    std::cout << " " << std::endl;
    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;
    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout << "FOR_LOOP_SPEED_UP FACTOR:" << (float)count1/count2 << std::endl;
    std::cout << "CONTRACTION SPEED UP FACTOR:" << (float)count2/count1 << std::endl;

    std::cout << "_________________END UNIT TEST:__COMPILE_TIME__________________" << std::endl;

    return std::vector<float> {count1, count2};
}

template<typename T>
void constexpr speed_test_quadruple_compileTime_contraction(){

    std::cout << "_________________START UNIT TEST:__COMPILE_TIME_QUADRUPLE_CONTRACTION_____________" << std::endl;

    int count1 = 0;
    int count2 = 0;
    int reps = 2000000;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> generator_ct;
    random_tensor_generator<T, 10> tensor_generator(0, 10);
    for_loop_contraction fl_calculation;

    std::vector<tensor<T, up_t, up_t>> firstTest;
    std::vector<tensor_rt<T, up_t, up_t>> secondTest;

    srand(time(0));

    auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        constexpr auto result =
                contraction<0,1, generator_ct.pick_random_tensor_2D(),
                contraction<0,1, generator_ct.pick_random_tensor_2D(),
                contraction<0,1, generator_ct.pick_random_tensor_2D(),
                        contraction<0,1, generator_ct.pick_random_tensor_2D(), generator_ct.pick_random_tensor_2D()>()>()>()>();
        firstTest.push_back(result);

    }
    auto t2 = std::chrono::high_resolution_clock::now();

    auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto result = fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(),
                fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(),
                                                             fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(),
                                                             fl_calculation.for_loop_contraction_2D(tensor_generator.pick_random_tensor_2D(),
                                                                     tensor_generator.pick_random_tensor_2D()))));
        secondTest.push_back(result);
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    count1 = duration1 / reps;
    count2 = duration2 / reps;

    std::cout << " " << std::endl;
    std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;
    std::cout << "CONTRACTION_FOR_LOOP(nano sec) :" << count2 << std::endl;
    std::cout << "FOR_LOOP_SPEED_UP FACTOR:" << (float)count1/count2 << std::endl;
    std::cout << "CONTRACTION SPEED UP FACTOR:" << (float)count2/count1 << std::endl;

    std::cout << "_________________END UNIT TEST:__COMPILE_TIME__________________" << std::endl;

    return std::vector<float> {count1, count2};
}
#endif //UNTITELED1_SPEED_TEST_COMPILETIME_CONTRACTION_H
