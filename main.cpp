#include <iostream>
#include <string>
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

#include "positive_natural_compiletime_pow.h"

#include <cmath>

#include <tuple>

#include "tensor-lib/tensor-builder-utilities/cartesian_product.h"
#include "tensor-lib/tensor-builder-utilities-ranges/cartesian_product_ranges_to_vec.h"
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


#include "tensor-lib/tensor-ranges/tensor-operations-ranges/trace_ranges.h"

#include "tensor-lib/tensor-concepts/tensor-concepts.h"

#include "tensor-lib/tensor-builder-utilities/tuple_helpers.h"

using std::cout;

int main() {

    constexpr tensor<double, up_t, up_t> tensor1(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    constexpr tensor<double, up_t> tensor2(5, 5, 5);

    constexpr auto contraction_value_ct = contraction<0,0, tensor1, tensor2>();
    auto contraction_value_rt = contraction<0,0>(tensor1.to_runtime_tensor(), tensor2.to_runtime_tensor());

    constexpr auto contraction_value_ct2 = contraction<0,0, tensor2, tensor2>();
    auto contraction_value_rt2 = contraction<0,0>(tensor2.to_runtime_tensor(), tensor2.to_runtime_tensor());

    constexpr auto contraction_value_ct3 = contraction<1,1>();
    auto contraction_value_rt3 = contraction(1,1);

    constexpr auto reorder_value_ct = reorder<tensor1, 1,0>();
    auto reorder_value_rt = reorder<1,0>(tensor1.to_runtime_tensor());

    constexpr auto trace_value_ct = trace<tensor1>();
    auto trace_value_rt = trace(tensor1.to_runtime_tensor());

    return 0;
}

