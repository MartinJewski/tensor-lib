//
// Created by martin machajewski on 06.03.20.
//

#ifndef UNTITELED1_SPEED_TEST_FORLOOP_REORDER_H
#define UNTITELED1_SPEED_TEST_FORLOOP_REORDER_H


#include "speed_test_tensors.h"
#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */


template<typename T>
auto speed_test_forLoop_reorder(){

    //std::cout << "_________________START SPEED TEST:__FOR_LOOP_REORDER___________" << std::endl;

    int count2 = 0;
    int reps = REP;

     random_tensor_generator_compiletime<T, 10, 0, 10> tensor_generator;

    for_loop_reorder fl_reorder;

    std::vector<tensor<T, up_t, up_t>> secondTest;

    srand(time(0));
    std::size_t times = 0;

    //auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto t3 = std::chrono::high_resolution_clock::now();
        volatile auto result = fl_reorder.for_loop_reordering_2D(tensor_generator.pick_random_tensor_2D());
        auto t4 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
        times += duration2;
        //secondTest.push_back(result);
    }
    //auto t4 = std::chrono::high_resolution_clock::now();

    //auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    //count2 = duration2 / reps;

    //std::cout << "REORDER_FOR_LOOP(nano sec) :" << count2 << std::endl;
    //std::cout << std::endl;

    //return count2;
    return times/reps;
}


template<typename T>
auto speed_test_forLoop_reorder3D(){

    //std::cout << "_________________START SPEED TEST:__FOR_LOOP_REORDER___________" << std::endl;

    int count2 = 0;
    int reps = REP;

     random_tensor_generator_compiletime<T, 10, 0, 10> tensor_generator;
    for_loop_reorder fl_reorder;

    std::vector<tensor<T, up_t, up_t, up_t>> secondTest;

    srand(time(0));

    std::size_t times = 0;

    //auto t3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < reps; i++){
        auto t3 = std::chrono::high_resolution_clock::now();
        volatile auto result = fl_reorder.for_loop_reordering_3D(tensor_generator.pick_random_tensor_3D());
        //secondTest.push_back(result);
        auto t4 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
        times += duration2;
    }
    //auto t4 = std::chrono::high_resolution_clock::now();

    //auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>( t4 - t3 ).count();
    //count2 = duration2 / reps;

   // std::cout << "REORDER_FOR_LOOP(nano sec) :" << count2 << std::endl;
   // std::cout << std::endl;

    //return count2;
    return times/reps;
}


#endif //UNTITELED1_SPEED_TEST_FORLOOP_REORDER_H
