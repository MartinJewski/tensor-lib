//
// Created by martin machajewski on 09.03.20.
//

#ifndef UNTITELED1_SPEED_TEST_EXPRESSIONTEMP_REORDER_H
#define UNTITELED1_SPEED_TEST_EXPRESSIONTEMP_REORDER_H


#define GPU_COMPILE_MACRO
#define NVIDIA_COMPILE_MACRO

#include <src/tensor_templates.hh>


#include "speed_test_tensors.h"
#include <chrono>
#include <tuple>
#include <stdlib.h>     /* srand, rand */

#include <random>

using namespace tensors;

template<typename T>
auto speed_test_expressionTemp_reorder2D(){

    //std::cout << "_________________START SPEED TEST:__expressionTemp_reorder2D____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> tensor_generator;

    std::array<tensor3_t<T, upper_t, lower_t>, 10> et_tensors2D;

    for(auto& ele : et_tensors2D){
        ele.m_data = tensor_generator.pick_random_tensor_2D().data;
    }

    srand(time(0));

    std::size_t times = 0;


    for(int val = 0; val < reps; val++){
        auto t1 = std::chrono::high_resolution_clock::now();
         auto result = reorder_index<1,0>(et_tensors2D[random() % 10]);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();

        times += duration1;
    }

    //std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;


    //std::cout << std::endl;

    return times/reps;
}


template<typename T>
auto speed_test_expressionTemp_reorder3D(){

    //std::cout << "_________________START SPEED TEST:__expressionTemp_reorder3D____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> tensor_generator;

    std::array<tensor3_t<T, upper_t, lower_t, lower_t>, 10> et_tensors3D;

    for(auto& ele : et_tensors3D){
        ele.m_data = tensor_generator.pick_random_tensor_3D().data;
    }

    srand(time(0));
    std::size_t times = 0;


    for(int val = 0; val < reps; val++){
        auto t1 = std::chrono::high_resolution_clock::now();
         auto result = reorder_index<0,2,1>(et_tensors3D[random() % 10]);
        auto t2 = std::chrono::high_resolution_clock::now();

        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        times += duration1;

    }
    //std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;
    //std::cout << std::endl;

    return times/reps;
}


/****************************************************************************+
 * **********************LOOOK UP ********************************************
 */


template<typename T>
auto speed_test_expressionTemp_LUP_reorder2D(){

    //std::cout << "_________________START SPEED TEST:__expressionTemp_reorder2D____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> tensor_generator;

    std::array<tensor3_t<T, upper_t, lower_t>, 10> et_tensors2D;

    for(auto& ele : et_tensors2D){
        ele.m_data = tensor_generator.pick_random_tensor_2D().data;
    }

    srand(time(0));
    std::size_t times = 0;


    for(int val = 0; val < reps; val++){
        auto t1 = std::chrono::high_resolution_clock::now();
         auto result = reorder_index<1,0>(et_tensors2D[random() % 10]);

        tensor3_t<T, lower_t, upper_t> temp(result);
        for(int i = 0; i < temp.m_data.size(); i++){
            temp[i];
        }

        auto t2 = std::chrono::high_resolution_clock::now();

        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        times += duration1;
    }

    return times/reps;
}


template<typename T>
auto speed_test_expressionTemp_LUP_reorder3D(){

    //std::cout << "_________________START SPEED TEST:__expressionTemp_reorder3D____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> tensor_generator;

    std::array<tensor3_t<T, upper_t, lower_t, lower_t>, 10> et_tensors3D;

    for(auto& ele : et_tensors3D){
        ele.m_data = tensor_generator.pick_random_tensor_3D().data;
    }

    srand(time(0));
    std::size_t times = 0;


    for(int val = 0; val < reps; val++){
        auto t1 = std::chrono::high_resolution_clock::now();
        auto result = reorder_index<0,2,1>(et_tensors3D[random() % 10]);

        tensor3_t<T, upper_t, lower_t, lower_t> temp(result);
        for(int i = 0; i < temp.m_data.size(); i++){
            temp[i];
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        times += duration1;
    }

    return times/reps;
}

#endif //UNTITELED1_SPEED_TEST_EXPRESSIONTEMP_REORDER_H
