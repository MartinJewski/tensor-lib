#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include <fstream>
#include <sstream>

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <range/v3/view/empty.hpp>
#include <range/v3/view/repeat_n.hpp>
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/view/cycle.hpp>
#include <range/v3/view/take.hpp>
#include <range/v3/view/chunk.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/cartesian_product.hpp>
#include <range/v3/view/common.hpp>
#include <range/v3/view/all.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/enumerate.hpp>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/counted.hpp>
#include <range/v3/view/move.hpp>
#include <range/v3/view/concat.hpp>

#include <range/v3/action/unique.hpp>
#include <range/v3/action/sort.hpp>
#include <range/v3/action/drop.hpp>
#include <range/v3/action/remove_if.hpp>
#include <range/v3/action/transform.hpp>

#include <range/v3/range/conversion.hpp>
#include <range/v3/algorithm/remove_if.hpp>
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/algorithm/min.hpp>
#include <range/v3/algorithm/max.hpp>


#include "tensor-lib/tensor-builder-utilities/positive_natural_compiletime_pow.h"

#include <cmath>

#include <tuple>

#include "tensor-lib/tensor-builder-utilities/cartesian_product.h"
#include "tensor-lib/tensor-builder-utilities/cartesian_product_adv.h"
#include "tensor-lib/tensor-builder-utilities/tuple_show.h"
#include "tensor-lib/tensor-builder-utilities/tuple_split.h"
#include "tensor-lib/tensor-builder-utilities/tuple_split_from.h"
#include "tensor-lib/tensor-builder-utilities/make_index_sequence_from.h"
#include "tensor-lib/tensor-builder-utilities/recreate_index_tuple.h"
#include "tensor-lib/tensor-builder-utilities/recreate_for_index_sequence.h"

#include "tensor-lib/tensor-builder-utilities/save_recreated_index_sequence.h"
#include "tensor-lib/tensor-builder-utilities/pos_nd_to_1d.h"


#include "tensor-lib/tensor-definition/tensor.h"
#include "tensor-lib/tensor-definition/tensor_specification.h"

#include "tensor-lib/tensor-operations/contraction_ct.h"
#include "tensor-lib/tensor-operations/trace_ct.h"
#include "tensor-lib/tensor-operations/trace_contraction_ct.h"
#include "tensor-lib/tensor-operations/trace_contraction.h"
#include "tensor-lib/tensor-operations/reorder_ct.h"
#include "tensor-lib/tensor-operations/contraction.h"
#include "tensor-lib/tensor-operations/trace.h"
#include "tensor-lib/tensor-operations/reorder.h"


#include "tensor-lib/tensor-operations-ranges/trace_ranges.h"
#include "tensor-lib/tensor-operations-ranges/reorder_ranges.h"
#include "tensor-lib/tensor-operations-ranges/contraction_ranges.h"

#include "tensor_range.h"

#include "tensor-lib/tensor-builder-utilities-ranges/cartesian_product_ranges_to_vec.h"

#include "tensor-lib/tensor-concepts/tensor-concepts.h"

#include "tensor-lib/tensor-builder-utilities/tuple_helpers.h"

#include "random_number.h"

#include <unordered_set>

#include "math_utilities.h"



#include "speed_test_expressionTemp_contraction.h"
#include "speed_test_expressionTemp_reorder.h"
#include "speed_test_expressionTemp_trace.h"

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

#include "speed_test_run.h"

int main() {
/*
    //------------------------------C++17-------------------------------
    constexpr tensor<double, up_t, low_t> tensor1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    tensor<double, up_t, low_t> tensor1_1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    constexpr tensor<double, low_t, up_t, up_t> tensor1_3D(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    constexpr tensor<double, up_t> tensor2(5.0, 5.0, 5.0);
    constexpr tensor<double> tensor23(1.0);

    tensor<double, up_t, low_t> ten(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    constexpr auto contraction_value_ct = contraction<0,0,tensor1_3D, contraction<0,0, tensor1_3D,
                  contraction<0,0, tensor1_3D, tensor1_3D>()>()>();


    auto contraction_value_CTRT = contraction<0,0>(tensor1, tensor1_1);
    auto contraction_value_CTRT1 = contraction<0,0>(tensor1_1, tensor1_1);

    constexpr auto contraction_value_ct2 = contraction<1,0, tensor1, tensor1>();

    constexpr auto contraction_value_ct3 = contraction<1,1>();
    auto contraction_value_rt3 = contraction(1,1);

    constexpr auto contraction_value_ct4 = contraction<tensor1, 1>();

    constexpr auto contraction_value_ct5 = contraction<1, tensor1>();

    constexpr auto trace_value_ct = trace<tensor1>();

    auto trace_value_CTRT = trace(tensor1_1);
    auto trace_value_CTRT1 = trace(tensor1);

    constexpr auto reorder_value_ct = reorder<tensor1, 1,0>();

    auto reorder_value_CTRT = reorder<1,0>(tensor1_1);
    auto reorder_value_CTRT1 = reorder<1,0>(tensor1);


    //----------------------C++20 ranges-------------------------------------------
    tensorRange<double, up_t, up_t> tensorR(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    tensorRange<double, up_t, up_t> tensorR2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    tensorRange<double, up_t> tensorR3(2.0, 2.0, 2.0);
    tensorRange<double, up_t> tensorR4(1.0, 5.0, 1.0);

    auto calculateRange = tensorR.calculate_indices();
    auto cartesianRng = cartesian_product_ranges<3,3>();

    auto cartesianRng2 = cartesian_product_ranges_to_vec<3,3>();

    auto test_trace_ranges = trace_ranges(tensorR);

    auto test_reorder_ranges = reorder_ranges<1,0>(tensorR);

    auto test_contraction_ranges = contraction_ranges<1,0>(tensorR2, tensorR2);

    auto test_contraction_ranges2 = contraction_ranges<0,0>(tensorR3, tensorR4);

    auto test_contraction_ranges3 = contraction_ranges(tensorR3, 2);

    auto test_contraction_ranges4 = contraction_ranges(2, tensorR3);


    auto st_ct_contraction_f = speed_test_compileTime_contraction<float>();
    auto st_ct_double_contraction_f = speed_test_double_compileTime_contraction<float>();
    auto st_ct_triple_contraction_f = speed_test_triple_compileTime_contraction<float>();
    auto st_ct_quadruple_contraction_f = speed_test_quadruple_compileTime_contraction<float>();
    auto st_ct_reorder_f = speed_test_compileTime_reorder<float>();
    auto st_ct_trace_f = speed_test_compileTime_trace<float>();

    auto st_rt_contraction_f = speed_test_runtime_contraction<float>();
    auto st_rt_double_contraction_f = speed_test_runtime_double_contraction<float>();
    auto st_rt_triple_contraction_f = speed_test_runtime_triple_contraction<float>();
    auto st_rt_reorder_f = speed_test_runtime_reorder<float>();
    auto st_rt_trace_f = speed_test_runtime_trace<float>();

    auto st_range_contraction_f = speed_test_ranges_contraction<float>();
    auto st_range_double_contracdtion_f = speed_test_ranges_double_contraction<float>();
    auto st_range_triple_contraction_f = speed_test_ranges_triple_contraction<float>();
    auto st_range_reorder_f = speed_test_ranges_reorder<float>();
    auto st_range_trace_f = speed_test_ranges_reorder<float>();

    auto st_forLoop_contracton_f = speed_test_forLoop_contraction<float>();
    auto st_double_forLoop_contracton_f = speed_test_double_forLoop_contraction<float>();
    auto st_triple_forLoop_contracton_f = speed_test_triple_forLoop_contraction<float>();
*/
    //speed_test_run_2D<30>("/home/martin/Schreibtisch/output2D.txt");
    //speed_test_run_3D<30>("/home/martin/Schreibtisch/output3D.txt");


    std::vector<int> ff_mycontainer{1,1,5,99,6,6,7,8,8,9};
    //auto a = f_mycontainer | ranges::actions::unique | ranges::actions::sort | ranges::actions::drop(5); //**
    auto b = ranges::actions::unique(ranges::actions::sort(ff_mycontainer)); //{1,5,6,7,8,9,99}
    auto c = ranges::to<std::vector>(ranges::actions::drop(b, 3)); // {7,8,9,99}

    constexpr tensor<double, up_t, up_t, low_t> tensoro(1.0, 2.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 2.0, 1.0,

            1.0, 2.0, 0.0,
            0.0, 1.0, 0.0,
            0.0, 2.0, 1.0,
                                                        1.0, 2.0, 0.0,
                                                        0.0, 1.0, 0.0,
                                                        0.0, 2.0, 1.0);
    constexpr auto e6 = trace_contraction_ct<tensoro, 0, 1>();
    auto e7 = trace_contraction<0, 1>(tensoro);


    return 0;
}
