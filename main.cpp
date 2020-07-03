/*
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
*/
/*
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
*/
/*
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
*/
/*
#include "tensor-lib/tensor-builder-utilities/save_recreated_index_sequence.h"
#include "tensor-lib/tensor-builder-utilities/pos_nd_to_1d.h"
*/

#include "tensor-lib/tensor-definition/tensor.h"
/*
#include "tensor-lib/tensor-definition/tensor_specification.h"
*/
#include "tensor-lib/tensor-operations/contraction_ct.h"
#include "tensor-lib/tensor-operations/trace_contraction_ct.h"
#include "tensor-lib/tensor-operations/trace_contraction.h"
#include "tensor-lib/tensor-operations/reorder_ct.h"
#include "tensor-lib/tensor-operations/contraction.h"
#include "tensor-lib/tensor-operations/reorder.h"

#include "tensor-lib/tensor-operations-ranges/reorder_ranges.h"
#include "tensor-lib/tensor-operations-ranges/contraction_ranges.h"
#include "tensor-lib/tensor-operations-ranges/trace_contraction_ranges.h"

#include "tensor_range.h"

/*
#include "tensor-lib/tensor-builder-utilities-ranges/cartesian_product_ranges_to_vec.h"

#include "tensor-lib/tensor-concepts/tensor-concepts.h"
*/
/*
#include "tensor-lib/tensor-builder-utilities/tuple_helpers.h"

#include "random_number.h"

#include <unordered_set>

#include "math_utilities.h"
*/
/*
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
#include "speed_test_ranges_reorder.h"
#include "speed_test_runtime_reorder.h"
#include "speed_test_ranges_trace.h"
#include "speed_test_runtime_trace.h"

#include "speed_test_run.h"

#include "speed_test_tensors.h"
*/


int main() {


    //-------------------------CPP 17-----------------------------------------
  //  tensor<int, up_t, low_t> tensor_rt{0,1,2,3,4,5,6,7,8};


    constexpr tensor<int, up_t, low_t> tensor1{0,1,2,3,4,5,6,7,8};
    constexpr auto tensor2_ct = contraction<0,1, tensor1, tensor1>();
    auto tensor2_rt = contraction<0,1>(tensor1, tensor1);

    constexpr auto tensor1_reorder_ct = reorder<tensor1, 1,0>();
    auto tensor1_reorder = reorder<1,0>(tensor1);

    constexpr auto tensor3_ct = trace_contraction<tensor1, 0,1>();
    auto tensor3_rt = trace_contraction<0,1>(tensor1);

    //-------------------------C++20 Ranges-------------------------------------------

    tensorRange<int, up_t, low_t> tensorR1{0,1,2,3,4,5,6,7,8};
    auto tensorR2_rt = contraction_ranges<0,1>(tensorR1, tensorR1);

    auto tensorR1_reorder = reorder_ranges<1,0>(tensorR1);

    auto tensorR3_rt = trace_contraction_ranges<0,1>(tensorR1);


    constexpr std::array<std::tuple<int,int,int,int>, 2> arr{std::tuple(1,2,3,4)};

    constexpr auto ct_sris_tensor2 = save_recreated_index_sequence<0, 3, 0, 4, 3> (arr);
    //decltype(ct_sris_tensor2)::foo = 1
    std::cout << std::get<0>(std::get<0>(ct_sris_tensor2)) << std::endl;
    std::cout << std::get<1>(std::get<0>(ct_sris_tensor2)) << std::endl;
    std::cout << std::get<2>(std::get<0>(ct_sris_tensor2)) << std::endl;

    std::cout << " "<< std::endl;

    //start value, steps
    constexpr auto ct_sris_tensor3 = save_recreated_index_sequence<3, 1, 0, 2, 3> (arr);
    //decltype(ct_sris_tensor2)::foo = 1
    std::cout << std::get<0>(std::get<0>(ct_sris_tensor3)) << std::endl;
    std::cout << std::get<1>(std::get<0>(ct_sris_tensor3)) << std::endl;
    std::cout << std::get<2>(std::get<0>(ct_sris_tensor3)) << std::endl;


    return 0;
}
