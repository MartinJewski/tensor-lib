#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <random>

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

#include "random_number.h"

#include <unordered_set>



constexpr int get_seed()
{
    int hour = std::atoi(__TIME__);
    int min = std::atoi(__TIME__ + 3);
    int sec = std::atoi(__TIME__ + 6);
    return 10000 * hour + 100 * min + sec;
}

int main() {

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

    constexpr auto values = cartesian_product<3,3>();

    random_tensor_generator<int, 10> tensor_generator(0, 10);

    auto tensor_rnd_0D = tensor_generator.pick_random_tensor_0D();
    auto tensor_rnd_1D = tensor_generator.pick_random_tensor_1D();
    auto tensor_rnd_2D = tensor_generator.pick_random_tensor_2D();
    auto tensor_rnd_3D = tensor_generator.pick_random_tensor_3D();

    srand(time(0));
    auto tensor_rnd_2D_1 = tensor_generator.pick_random_tensor_2D();
    auto tensor_rnd_2D_2 = tensor_generator.pick_random_tensor_2D();

    srand(time(0));
    auto tensor_rnd_3D_1 = tensor_generator.pick_random_tensor_3D();
    auto tensor_rnd_3D_2 = tensor_generator.pick_random_tensor_3D();

    for_loop_contraction fl_contraction;

    std::cout << "----------" << std::endl;
    std::cout << contraction<0,1>(tensor_rnd_2D_1, tensor_rnd_2D_2);
    std::cout << fl_contraction.for_loop_contraction_2D(tensor_rnd_2D_1, tensor_rnd_2D_2) << std::endl;
    std::cout << "----------" << std::endl;

    std::cout << contraction<0,1>(tensor_rnd_3D_1, tensor_rnd_3D_2) << std::endl;
    std::cout << fl_contraction.for_loop_contraction_3D(tensor_rnd_3D_1, tensor_rnd_3D_2) << std::endl;

    //-----------------------------------------

    auto st_rt_trace_int = speed_test_runtime_trace<int>();

    /*
    auto st_rt_contraction_int = speed_test_runtime_contraction<int>();
    auto st_rt_double_contraction_int = speed_test_runtime_double_contraction<int>();
    auto st_rt_triple_contraction_int = speed_test_runtime_triple_contraction<int>();
    std::cout << std::endl;
    auto st_range_contraction_int = speed_test_ranges_contraction<int>();
    auto st_range_double_contraction_int = speed_test_ranges_double_contraction<int>();
    auto st_range_triple_contraction_int = speed_test_ranges_triple_contraction<int>();

    auto st_rt_reorder_int = speed_test_runtime_reorder<int>();
    auto st_range_reorder_int = speed_test_ranges_reorder<int>();

    auto st_rt_trace_int = speed_test_runtime_trace<int>();
    auto st_range_trace_int = speed_test_ranges_reorder<int>();
*/
    /*********************************+
     *
     *
     *
     *
     */

     /*
    auto st_rt_contraction_float = speed_test_runtime_contraction<float>();
    auto st_rt_double_contraction_float = speed_test_runtime_double_contraction<float>();
    auto st_rt_triple_contraction_float = speed_test_runtime_triple_contraction<float>();
    std::cout << std::endl;
    auto st_range_contraction_float = speed_test_ranges_contraction<float>();
    auto st_range_double_contraction_float = speed_test_ranges_double_contraction<float>();
    auto st_range_triple_contraction_float = speed_test_ranges_triple_contraction<float>();

    auto st_rt_reorder_float = speed_test_runtime_reorder<float>();
    auto st_range_reorder_float = speed_test_ranges_reorder<float>();

    auto st_rt_trace_float = speed_test_runtime_trace<float>();
    auto st_range_trace_float = speed_test_ranges_reorder<float>();
*/

    /*
    std::cout << std::endl;
    std::cout << "RUNTIME SPEED UP FACTOR COMPARED TO RANGES:" << std::endl;
    std::cout << (float)(ut_range_contraction[0] / ut_rt_contraction[0]) << std::endl;
    */

/*
    std::ofstream output_file;
    output_file.open ("/home/martin/Schreibtisch/speedtest_output_int.txt");

    output_file << "time in nano seconds" << std::endl;
    output_file << "<ALGO> <FOR-LOOP>" << std::endl;
    output_file << "contraction" << std::endl;
    output_file << st_rt_contraction_int[0] << " " << st_rt_contraction_int[1] << std::endl;
    output_file << "double contraction" << std::endl;
    output_file << st_rt_double_contraction_int[0] << " " << st_rt_double_contraction_int[1] << std::endl;
    output_file << "triple contraction" << std::endl;
    output_file << st_rt_triple_contraction_int[0] << " " << st_rt_triple_contraction_int[1] << std::endl;

    output_file << "contraction_ranges" << std::endl;
    output_file << st_range_contraction_int[0] << " " << st_range_contraction_int[1] << std::endl;
    output_file << "double contraction_ranges" << std::endl;
    output_file << st_range_double_contraction_int[0] << " " << st_range_double_contraction_int[1] << std::endl;
    output_file << "triple contraction_ranges" << std::endl;
    output_file << st_range_triple_contraction_int[0] << " " << st_range_triple_contraction_int[1] << std::endl;

    output_file << "reorder" << std::endl;
    output_file << st_rt_reorder_int[0] << " " << st_rt_reorder_int[1] << std::endl;
    output_file << "reorder_ranges" << std::endl;
    output_file << st_range_reorder_int[0] << " " << st_range_reorder_int[1] << std::endl;

    output_file << "trace" << std::endl;
    output_file << st_rt_trace_int[0] << " " << st_rt_trace_int[1] << std::endl;
    output_file << "trace_ranges" << std::endl;
    output_file << st_range_trace_int[0] << " " << st_range_trace_int[1] << std::endl;

    output_file.close();


    std::ofstream output_file2;
    output_file2.open ("/home/martin/Schreibtisch/speedtest_output_float.txt");

    output_file2 << "time in nano seconds" << std::endl;
    output_file2 << "<ALGO> <FOR-LOOP>" << std::endl;
    output_file2 << "contraction" << std::endl;
    output_file2 << st_rt_contraction_float[0] << " " << st_rt_contraction_float[1] << std::endl;
    output_file2 << "double contraction" << std::endl;
    output_file2 << st_rt_double_contraction_float[0] << " " << st_rt_double_contraction_float[1] << std::endl;
    output_file2 << "triple contraction" << std::endl;
    output_file2 << st_rt_triple_contraction_float[0] << " " << st_rt_triple_contraction_float[1] << std::endl;

    output_file2 << "contraction_ranges" << std::endl;
    output_file2 << st_range_contraction_float[0] << " " << st_range_contraction_float[1] << std::endl;
    output_file2 << "double contraction_ranges" << std::endl;
    output_file2 << st_range_double_contraction_float[0] << " " << st_range_double_contraction_float[1] << std::endl;
    output_file2 << "triple contraction_ranges" << std::endl;
    output_file2 << st_range_triple_contraction_float[0] << " " << st_range_triple_contraction_float[1] << std::endl;

    output_file2 << "reorder" << std::endl;
    output_file2 << st_rt_reorder_float[0] << " " << st_rt_reorder_float[1] << std::endl;
    output_file2 << "reorder_ranges" << std::endl;
    output_file2 << st_range_reorder_float[0] << " " << st_range_reorder_float[1] << std::endl;

    output_file2 << "trace" << std::endl;
    output_file2 << st_rt_trace_float[0] << " " << st_rt_trace_float[1] << std::endl;
    output_file2 << "trace_ranges" << std::endl;
    output_file2 << st_range_trace_float[0] << " " << st_range_trace_float[1] << std::endl;

    output_file2.close();
*/

    constexpr auto distri = uniform_distribution<int, 100>(0,20);

    //constexpr tensor<int, up_t, up_t> ctTensor(distri[0],distri[1],distri[2],distri[3],distri[4],distri[5],distri[6],distri[7],distri[8]);

    auto random_ct_tensor = tensor<int, up_t, up_t>::random_tensor_ct(0, 20);

    constexpr tensor<int, up_t, up_t> ctTensor(
            uniform_distribution<int>(0,5),
            uniform_distribution<int>(0,5),
            uniform_distribution<int>(0,5),
            uniform_distribution<int>(0,5),
            uniform_distribution<int>(0,5),
            uniform_distribution<int>(0,5));


    speed_test_compileTime_contraction<int>();
    speed_test_double_compileTime_contraction<int>();
    speed_test_triple_compileTime_contraction<int>();
    speed_test_quadruple_compileTime_contraction<int>();

    speed_test_compileTime_reorder<int>();
    speed_test_compileTime_trace<int>();

    return 0;
}
