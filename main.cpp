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



#include <tuple>

#include "tensor-lib/tensor-builder-utilities/cartesian_product.h"
#include "tensor-lib/tensor-builder-utilities/cartesian_product_to_vec.h"
#include "tensor-lib/tensor-builder-utilities/range_of_nonviewable_container_show.h"
#include "tensor-lib/tensor-builder-utilities/enumerate_range.h"
#include "tensor-lib/tensor-builder-utilities/tuple_show.h"
#include "tensor-lib/tensor-builder-utilities/tuple_split.h"
#include "tensor-lib/tensor-builder-utilities/tuple_split_from.h"
#include "tensor-lib/tensor-builder-utilities/make_index_sequence_from.h"
#include "tensor-lib/tensor-builder-utilities/recreate_index_tuple.h"
#include "tensor-lib/tensor-builder-utilities/recreate_for_index_sequence.h"
#include "tensor-lib/tensor-builder-utilities/save_as_array.h"
#include "tensor-lib/tensor-builder-utilities/save_recreated_index_sequence.h"
#include "tensor-lib/tensor-builder-utilities/pos_nd_to_1d.h"


#include "tensor-lib/tensor-definition/tensor.h"
#include "tensor-lib/tensor-definition/tensor_specification.h"

#include "tensor-lib/tensor-operations/contraction.h"
#include "tensor-lib/tensor-operations/trace.h"
#include "tensor-lib/tensor-operations/reorder.h"

#include "tensor-lib/tensor-concepts/tensor-concepts.h"


using std::cout;

int main() {

    auto cart1 = cartesian_product_to_vec<2,2>();

    //constexpr auto cart42 = cartesian_product_new<4,2>();
    //--------------------------------------------------
    //a tuple will contain the position indices
    //E.g C lower, lower, upper, upper
    // A lower lower upper , B upper upper upper = C lower lower upper upper (contract<3,3>)

    constexpr std::size_t skipT1 = 3;
    constexpr std::size_t skipT2 = 3;
    constexpr std::size_t tensorA_indice_amount = 3;
    constexpr std::size_t tensorB_indice_amount = 3;

    //from final tuple, take first elemnts for A and rest is B
    constexpr std::size_t tensorA_indices_amount_reduce = tensorA_indice_amount - 1;
    constexpr std::size_t tensorB_indices_amount_reduce = tensorB_indice_amount - 1;

    constexpr std::tuple<int, int, int> A_3 = std::make_tuple(0, 0, 1);
    constexpr std::tuple<int, int, int> B_3 = std::make_tuple(1, 1, 1);

    //since every contraction removes one indces for every tensor,
    //the recreation of an index position from C could be as follows:
    //      -get amount of indices for the specific tensor
    //      -split tuple into two tuples:
    //              -insert the removed index at the given position
    //      -create index length amount of tuples(removed  index 0 to n)

    constexpr std::tuple<int, int, int, int>  C_4 = std::make_tuple(1,0,1,0);

    constexpr auto splittedVal = std::get<0>(C_4) + std::get<1>(C_4);
    constexpr auto splitted_A = std::make_tuple(get<0>(C_4), get<1>(C_4));
    constexpr auto splitted_B = std::make_tuple(get<2>(C_4), get<3>(C_4));

    std::cout << splitted_A << std::endl;
    std::cout << splitted_B << std::endl;

    constexpr auto tup = std::make_tuple(0,1,2,3,4,5,6,7,8,9,10);

    constexpr auto split1 = tuple_split<11>(tup);
    //decltype(lol)::foo = 1;
    std::cout << "split1 " << split1 << std::endl;

    constexpr auto split2 = tuple_split_from<5,6>(tup);
    std::cout << "split2 " << split2 << std::endl;

    //TODO: split tuple and recreate lost indices
    constexpr auto rec_split1 = recreate_index_tuple<0,3,2,0,4>(tup);
    constexpr auto rec_split2 = recreate_index_tuple<0,3,2,1,4>(tup);
    constexpr auto rec_split3 = recreate_index_tuple<0,3,2,2,4>(tup);
    std::cout << rec_split1 << std::endl;
    std::cout << rec_split2 << std::endl;
    std::cout << rec_split3 << std::endl;


    std::cout << " " << tup << std::endl;
    std::cout << "tup: " << tup << std::endl;
    //tuple of tuples
    constexpr auto look = recreate_for_index_sequence<0,3,2,4,3>(tup);
    constexpr auto look2 = recreate_for_index_sequence<4,7,2,4,3>(tup);
    //decltype(look)::foo = 1;
    std::cout << look << std::endl;
    std::cout << look2 << std::endl;

    auto myArr = save_as_array<decltype(look), 2>(look, look2);
    //decltype(look)::foo = 1;

    std::cout << "-----------" << std::endl;

    //RIGHT NOW IT TAKES A CARTESIAN PRODUCT AND DOES A OPERATION FOR EVERY TUPLE
    auto elooo = save_recreated_index_sequence<0,1,1,2,5>(cart1);
    //auto elooo2 = save_recreated_index_sequence(0,1,1,2,5, cart1);

    tensor<double, up_t, low_t> tensorTest1(11.0, 22.0, 33.0, 44.0, 55.0, 66.0, 77.0, 88.0, 99.0);
    tensor<double, up_t, low_t> tensorTest2(0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9);

    //myfunction<tensorTest1.indices_amount, tensorTest2.indices_amount>();

    //decltype(jop)::type;
    auto t3 = contraction<0,1,0,2,
                0,1,1,2,
                double>(tensorTest1.calculate_indices(), tensorTest1.data, tensorTest2.calculate_indices(), tensorTest2.data);

    trace<2>(tensorTest1.data);

    reorder<1,0>(tensorTest1.calculate_indices(), tensorTest1.data);

    //first var is from 0 to val, second var is the set cound
    constexpr auto cartesii = ct<2,1>();


    std::cout << cartesii << std::endl;



    return 0;
}

