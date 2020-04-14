//
// Created by martin machajewski on 09.03.20.
//

#ifndef UNTITELED1_SPEED_TEST_EXPRESSIONTEMP_TRACE_H
#define UNTITELED1_SPEED_TEST_EXPRESSIONTEMP_TRACE_H



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
auto speed_test_expressionTemp_trace2D(){

    //std::cout << "_________________START SPEED TEST:__expressionTemp_trace2D____________" << std::endl;

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
         auto result =  trace<0,1>(et_tensors2D[random() % 10]);

        auto t2 = std::chrono::high_resolution_clock::now();

        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        times += duration1;
    }


    //std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;


    //std::cout << std::endl;

    //return count1;
    return times/reps;
}


template<typename T>
auto speed_test_expressionTemp_trace3D(){

    //std::cout << "_________________START SPEED TEST:__expressionTemp_trace3D____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> tensor_generator;

    std::array<tensor3_t<T, upper_t, lower_t, lower_t>, 10> et_tensors3D;

    for(auto& ele : et_tensors3D){
        ele.m_data = tensor_generator.pick_random_tensor_3D().data;
    }

    srand(time(0));
    std::size_t times = 0;
    //auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto t1 = std::chrono::high_resolution_clock::now();
         auto result = trace<0,1>(et_tensors3D[random() % 10]);
        auto t2 = std::chrono::high_resolution_clock::now();

        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        times += duration1;
    }


    //std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;


    //std::cout << std::endl;

    //return count1;
    return times/reps;
}


/************************************************************************************+
 * **************************LOOK UP *************************************************
 */


template<typename T>
auto speed_test_expressionTemp_LUP_trace2D(){

    //std::cout << "_________________START SPEED TEST:__expressionTemp_trace2D____________" << std::endl;

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
         auto result =  trace<0,1>(et_tensors2D[random() % 10]);

        auto t2 = std::chrono::high_resolution_clock::now();

        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        times += duration1;
    }

    //count1 = duration1 / reps;


    //std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;
    //std::cout << std::endl;
    //return count1;
    return times/reps;
}


template<typename T>
auto speed_test_expressionTemp_LUP_trace3D(){

    //std::cout << "_________________START SPEED TEST:__expressionTemp_trace3D____________" << std::endl;

    int count1 = 0;
    int reps = REP;

    constexpr random_tensor_generator_compiletime<T, 10, 0, 10> tensor_generator;

    std::array<tensor3_t<T, upper_t, lower_t, lower_t>, 10> et_tensors3D;

    for(auto& ele : et_tensors3D){
        ele.m_data = tensor_generator.pick_random_tensor_3D().data;
    }

    srand(time(0));
    std::size_t times = 0;

    //auto t1 = std::chrono::high_resolution_clock::now();
    for(int val = 0; val < reps; val++){

        auto t1 = std::chrono::high_resolution_clock::now();
         auto result = trace<0,1>(et_tensors3D[random() % 10]);

         tensor3_t<T, lower_t> temp(result);
        for(int i = 0; i < temp.m_data.size(); i++){
            temp[i];
        }

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        times += duration1;
    }
    //auto t2 = std::chrono::high_resolution_clock::now();

    //auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
    //count1 = duration1 / reps;
    //std::cout << "CONTRACTION_ALGO(nano sec) :" << count1 << std::endl;
    //std::cout << std::endl;
    //return count1;
    return times/reps;
}

#endif //UNTITELED1_SPEED_TEST_EXPRESSIONTEMP_TRACE_H
