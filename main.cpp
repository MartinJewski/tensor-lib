#include <iostream>
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

#include "tensor-lib/tensor-builder-utilities/positive_natural_compiletime_pow.h"

#include <cmath>

#include <tuple>

#include "tensor-lib/tensor-builder-utilities/cartesian_product.h"
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

#include "tensor-lib/unitTest/unitTest_runtime.h"
#include "tensor-lib/unitTest/unitTest_ranges.h"

#include "random_number.h"

int main() {


    myStruct myStructObj;
    auto myvalue = myfunction(myStructObj.aC);


    //------------------------------C++17-------------------------------
    constexpr tensor<double, up_t, up_t> tensor1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    constexpr tensor<double, up_t, up_t, up_t> tensor1_3D(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    constexpr tensor<double, up_t> tensor2(5.0, 5.0, 5.0);
    constexpr tensor<double> tensor23(1.0);

    tensor_rt<double, up_t, up_t> ten(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    constexpr auto contraction_value_ct = contraction<0,0, tensor1, tensor2>();
    auto contraction_value_rt = contraction<0,0>(tensor1.to_runtime_tensor(), tensor2.to_runtime_tensor());

    constexpr auto contraction_value_ct2 = contraction<1,0, tensor1, tensor1>();
    auto contraction_value_rt2 = contraction<1,0>(tensor1.to_runtime_tensor(), tensor1.to_runtime_tensor());

    constexpr auto contraction_value_ct3 = contraction<1,1>();
    auto contraction_value_rt3 = contraction(1,1);

    constexpr auto contraction_value_ct4 = contraction<tensor1, 1>();

    constexpr auto contraction_value_ct5 = contraction<1, tensor1>();

    constexpr auto reorder_value_ct = reorder<tensor1, 1,0>();
    auto reorder_value_rt = reorder<1,0>(tensor1.to_runtime_tensor());

    constexpr auto trace_value_ct = trace<tensor1>();
    auto trace_value_rt = trace(tensor1.to_runtime_tensor());

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
/*
    unitTest_runtime();
    unitTest_ranges();
*/
    srand(time(0));
   auto randomTensor1 = tensor_rt<int, up_t, up_t>::random_tensor_rt(0, 10);
    srand(time(0));
   auto randomTensor2 = tensor_rt<int, up_t, up_t>::random_tensor_rt(0, 10);
    srand(time(0));
   auto randomTensor3 = tensor_rt<int, up_t, up_t>::random_tensor_rt(0, 10);
   for(auto i : randomTensor1.data){
       std::cout << " " << i << " ";
   }
   std::cout << std::endl;
    for(auto i : randomTensor2.data){
        std::cout << " " << i << " ";
    }
    std::cout << std::endl;
    for(auto i : randomTensor3.data){
        std::cout << " " << i << " ";
    }





    return 0;
}
