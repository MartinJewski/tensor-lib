//
// Created by martin on 06.03.20.
//

#ifndef UNTITELED1_SPEED_TEST_RUN_H
#define UNTITELED1_SPEED_TEST_RUN_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "speed_test_expressionTemp_reorder.h"
#include "speed_test_expressionTemp_trace.h"
#include "speed_test_expressionTemp_contraction.h"

#include "speed_test_forLoop_reorder.h"
#include "speed_test_forLoop_trace.h"
#include "speed_test_forLoop_contraction.h"
#include "speed_test_compileTime_reorder.h"
#include "speed_test_compileTime_trace.h"
#include "speed_test_compileTime_contraction.h"
#include "speed_test_runtime_contraction.h"
#include "speed_test_ranges_contraction.h"
#include "speed_test_tensors.h"
#include "speed_test_ranges_reorder.h"
#include "speed_test_runtime_reorder.h"
#include "speed_test_ranges_trace.h"
#include "speed_test_runtime_trace.h"

template<std::size_t amount>
void speed_test_run_2D(std::string input_path){

    std::cout << "start speed test 2D tensors" << std::endl;

    static_assert(!(amount < 0));
    std::ofstream output_file;
    output_file.open (input_path);

    output_file << "ct_1x_contraction" << "\t";
    output_file << "ct_2x_contraction" << "\t";
    output_file << "ct_3x_contraction" << "\t";
    output_file << "ct_4x_contraction" << "\t";
    output_file << "ct_reorder" << "\t";
    output_file << "ct_trace" << "\t";

    output_file << "rt_1x_contraction" << "\t";
    output_file << "rt_2x_contraction" << "\t";
    output_file << "rt_3x_contraction" << "\t";
    output_file << "rt_reorder" << "\t";
    output_file << "rt_trace" << "\t";

    output_file << "range_1x_contraction" << "\t";
    output_file << "range_2x_contraction" << "\t";
    output_file << "range_3x_contraction" << "\t";
    output_file << "range_reorder" << "\t";
    output_file << "range_trace" << "\t";

    output_file << "ET_1x_contraction" << "\t";
    output_file << "ET_2x_contraction" << "\t";
    output_file << "ET_3x_contraction" << "\t";
    output_file << "ET_reorder" << "\t";
    output_file << "ET_trace" << "\t";


    output_file << std::endl;

    for(int i = 0; i <= amount; i++){

        if((i % 2) == 0){
            std::cout << "iteration: " <<  i << "/" << amount << std::endl;
        }

        output_file << speed_test_compileTime_contraction<int>() << "\t";
        output_file << speed_test_double_compileTime_contraction<int>() << "\t";
        output_file << speed_test_triple_compileTime_contraction<int>() << "\t";
        output_file << speed_test_quadruple_compileTime_contraction<int>() << "\t";
        output_file << speed_test_compileTime_reorder<int>() << "\t";
        output_file << speed_test_compileTime_trace<int>() << "\t";

        output_file << speed_test_runtime_contraction<int>() << "\t";
        output_file << speed_test_runtime_double_contraction<int>() << "\t";
        output_file << speed_test_runtime_triple_contraction<int>() << "\t";
        output_file << speed_test_runtime_reorder<int>() << "\t";
        output_file << speed_test_runtime_trace<int>() << "\t";

        output_file << speed_test_ranges_contraction<int>() << "\t";
        output_file << speed_test_ranges_double_contraction<int>() << "\t";
        output_file << speed_test_ranges_triple_contraction<int>() << "\t";
        output_file << speed_test_ranges_reorder<int>() << "\t";
        output_file << speed_test_ranges_trace<int>() << "\t";

        output_file << speed_test_forLoop_contraction<int>() << "\t";
        output_file << speed_test_double_forLoop_contraction<int>() << "\t";
        output_file << speed_test_triple_forLoop_contraction<int>() << "\t";
        output_file << speed_test_forLoop_reorder<int>() << "\t";
        output_file << speed_test_forLoop_trace<int>() << "\t";

        output_file << speed_test_expressionTemp_contraction2D<int>() << "\t";
        output_file << speed_test_double_expressionTemp_contraction2D<int>() << "\t";
        output_file << speed_test_triple_expressionTemp_contraction2D<int>() << "\t";
        output_file << speed_test_expressionTemp_reorder2D<int>() << "\t";
        output_file << speed_test_expressionTemp_trace2D<int>() << "\t";

        output_file << std::endl;
    }
    output_file.close();

}

template<std::size_t amount>
void speed_test_run_3D(std::string input_path){

    std::cout << "start speed test 3D tensors" << std::endl;

    static_assert(!(amount < 0));
    std::ofstream output_file;
    output_file.open (input_path);

    output_file << "ct_1x_contraction_3D" << "\t";
    output_file << "ct_2x_contraction_3D" << "\t";
    output_file << "ct_reorder_3D" << "\t";
    output_file << "ct_trace_3D" << "\t";

    output_file << "rt_1x_contraction_3D" << "\t";
    output_file << "rt_2x_contraction_3D" << "\t";
    output_file << "rt_reorder_3D" << "\t";
    output_file << "rt_trace_3D" << "\t";

    output_file << "range_1x_contraction_3D" << "\t";
    output_file << "range_2x_contraction_3D" << "\t";
    output_file << "range_reorder_3D" << "\t";
    output_file << "range_trace_3D" << "\t";

    output_file << "forLoop_1x_contraction_3D" << "\t";
    output_file << "forLoop_2x_contraction_3D" << "\t";
    output_file << "forLoop_reorder_3D" << "\t";
    output_file << "forLoop_trace_3D" << "\t";

    output_file << "ET_1x_contraction_3D" << "\t";
    output_file << "ET_2x_contraction_3D" << "\t";
    output_file << "ET_reorder_3D" << "\t";
    output_file << "ET_trace_3D" << "\t";
    output_file << std::endl;

    for(int i = 0; i <= amount; i++){

        if((i % 2) == 0){
            std::cout << "iteration: " <<  i << "/" << amount << std::endl;
        }

        output_file << speed_test_compileTime_contraction3D<int>() << "\t";
        output_file << speed_test_double_compileTime_contraction3D<int>() << "\t";
        output_file << speed_test_compileTime_reorder3D<int>() << "\t";
        output_file << speed_test_compileTime_trace3D<int>() << "\t";

        output_file << speed_test_runtime_contraction3D<int>() << "\t";
        output_file << speed_test_runtime_double_contraction3D<int>() << "\t";
        output_file << speed_test_runtime_reorder3D<int>() << "\t";
        output_file << speed_test_runtime_trace3D<int>() << "\t";

        output_file << speed_test_ranges_contraction3D<int>() << "\t";
        output_file << speed_test_ranges_double_contraction3D<int>() << "\t";
        output_file << speed_test_ranges_reorder3D<int>() << "\t";
        output_file << speed_test_ranges_trace3D<int>() << "\t";

        output_file << speed_test_forLoop_contraction3D<int>() << "\t";
        output_file << speed_test_double_forLoop_contraction3D<int>() << "\t";
        output_file << speed_test_forLoop_reorder3D<int>() << "\t";
        output_file << speed_test_forLoop_trace3D<int>() << "\t";

        output_file << speed_test_expressionTemp_contraction3D<int>() << "\t";
        output_file << speed_test_double_expressionTemp_contraction3D<int>() << "\t";
        output_file << speed_test_expressionTemp_reorder3D<int>() << "\t";
        output_file << speed_test_expressionTemp_trace3D<int>() << "\t";

        output_file << std::endl;
    }

    output_file.close();
}


/****************************************************************************************
 * **************************LOOK UP****************************************************
 */

template<std::size_t amount>
void speed_test_run_LUP_2D(std::string input_path){

    std::cout << "start speed test 2D tensors" << std::endl;

    static_assert(!(amount < 0));
    std::ofstream output_file;
    output_file.open (input_path);

    output_file << "ct_1x_contraction" << "\t";
    output_file << "ct_2x_contraction" << "\t";
    output_file << "ct_3x_contraction" << "\t";
    output_file << "ct_4x_contraction" << "\t";
    output_file << "ct_reorder" << "\t";
    output_file << "ct_trace" << "\t";

    output_file << "rt_1x_contraction" << "\t";
    output_file << "rt_2x_contraction" << "\t";
    output_file << "rt_3x_contraction" << "\t";
    output_file << "rt_reorder" << "\t";
    output_file << "rt_trace" << "\t";

    output_file << "range_1x_contraction" << "\t";
    output_file << "range_2x_contraction" << "\t";
    output_file << "range_3x_contraction" << "\t";
    output_file << "range_reorder" << "\t";
    output_file << "range_trace" << "\t";

    output_file << "ET_1x_contraction" << "\t";
    output_file << "ET_2x_contraction" << "\t";
    output_file << "ET_3x_contraction" << "\t";
    output_file << "ET_reorder" << "\t";
    output_file << "ET_trace" << "\t";


    output_file << std::endl;

    for(int i = 0; i <= amount; i++){

        if((i % 2) == 0){
            std::cout << "iteration: " <<  i << "/" << amount << std::endl;
        }

        output_file << speed_test_compileTime_contraction<int>() << "\t";
        output_file << speed_test_double_compileTime_contraction<int>() << "\t";
        output_file << speed_test_triple_compileTime_contraction<int>() << "\t";
        output_file << speed_test_quadruple_compileTime_contraction<int>() << "\t";
        output_file << speed_test_compileTime_reorder<int>() << "\t";
        output_file << speed_test_compileTime_trace<int>() << "\t";

        output_file << speed_test_runtime_contraction<int>() << "\t";
        output_file << speed_test_runtime_double_contraction<int>() << "\t";
        output_file << speed_test_runtime_triple_contraction<int>() << "\t";
        output_file << speed_test_runtime_reorder<int>() << "\t";
        output_file << speed_test_runtime_trace<int>() << "\t";

        output_file << speed_test_ranges_contraction<int>() << "\t";
        output_file << speed_test_ranges_double_contraction<int>() << "\t";
        output_file << speed_test_ranges_triple_contraction<int>() << "\t";
        output_file << speed_test_ranges_reorder<int>() << "\t";
        output_file << speed_test_ranges_trace<int>() << "\t";

        output_file << speed_test_forLoop_contraction<int>() << "\t";
        output_file << speed_test_double_forLoop_contraction<int>() << "\t";
        output_file << speed_test_triple_forLoop_contraction<int>() << "\t";
        output_file << speed_test_forLoop_reorder<int>() << "\t";
        output_file << speed_test_forLoop_trace<int>() << "\t";

        output_file << speed_test_expressionTemp_LUP_contraction2D<int>() << "\t";
        output_file << speed_test_double_expressionTemp_LUP_contraction2D<int>() << "\t";
        output_file << speed_test_triple_expressionTemp_LUP_contraction2D<int>() << "\t";
        output_file << speed_test_expressionTemp_LUP_reorder2D<int>() << "\t";
        output_file << speed_test_expressionTemp_LUP_trace2D<int>() << "\t";

        output_file << std::endl;
    }
    output_file.close();

}

template<std::size_t amount>
void speed_test_run_LUP_3D(std::string input_path){

    std::cout << "start speed test 3D tensors" << std::endl;

    static_assert(!(amount < 0));
    std::ofstream output_file;
    output_file.open (input_path);

    output_file << "ct_1x_contraction_3D" << "\t";
    output_file << "ct_2x_contraction_3D" << "\t";
    output_file << "ct_reorder_3D" << "\t";
    output_file << "ct_trace_3D" << "\t";

    output_file << "rt_1x_contraction_3D" << "\t";
    output_file << "rt_2x_contraction_3D" << "\t";
    output_file << "rt_reorder_3D" << "\t";
    output_file << "rt_trace_3D" << "\t";

    output_file << "range_1x_contraction_3D" << "\t";
    output_file << "range_2x_contraction_3D" << "\t";
    output_file << "range_reorder_3D" << "\t";
    output_file << "range_trace_3D" << "\t";

    output_file << "forLoop_1x_contraction_3D" << "\t";
    output_file << "forLoop_2x_contraction_3D" << "\t";
    output_file << "forLoop_reorder_3D" << "\t";
    output_file << "forLoop_trace_3D" << "\t";

    output_file << "ET_1x_contraction_3D" << "\t";
    output_file << "ET_2x_contraction_3D" << "\t";
    output_file << "ET_reorder_3D" << "\t";
    output_file << "ET_trace_3D" << "\t";
    output_file << std::endl;

    for(int i = 0; i <= amount; i++){

        if((i % 2) == 0){
            std::cout << "iteration: " <<  i << "/" << amount << std::endl;
        }

        output_file << speed_test_compileTime_contraction3D<int>() << "\t";
        output_file << speed_test_double_compileTime_contraction3D<int>() << "\t";
        output_file << speed_test_compileTime_reorder3D<int>() << "\t";
        output_file << speed_test_compileTime_trace3D<int>() << "\t";

        output_file << speed_test_runtime_contraction3D<int>() << "\t";
        output_file << speed_test_runtime_double_contraction3D<int>() << "\t";
        output_file << speed_test_runtime_reorder3D<int>() << "\t";
        output_file << speed_test_runtime_trace3D<int>() << "\t";

        output_file << speed_test_ranges_contraction3D<int>() << "\t";
        output_file << speed_test_ranges_double_contraction3D<int>() << "\t";
        output_file << speed_test_ranges_reorder3D<int>() << "\t";
        output_file << speed_test_ranges_trace3D<int>() << "\t";

        output_file << speed_test_forLoop_contraction3D<int>() << "\t";
        output_file << speed_test_double_forLoop_contraction3D<int>() << "\t";
        output_file << speed_test_forLoop_reorder3D<int>() << "\t";
        output_file << speed_test_forLoop_trace3D<int>() << "\t";

        output_file << speed_test_expressionTemp_LUP_contraction3D<int>() << "\t";
        output_file << speed_test_double_expressionTemp_LUP_contraction3D<int>() << "\t";
        output_file << speed_test_expressionTemp_LUP_reorder3D<int>() << "\t";
        output_file << speed_test_expressionTemp_LUP_trace3D<int>() << "\t";

        output_file << std::endl;
    }

    output_file.close();
}






#endif //UNTITELED1_SPEED_TEST_RUN_H
