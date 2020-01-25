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
#include "cartesian_product_ranges_to_vec.h"
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

#include "tensor-lib/tensor-operations/contraction.h"
#include "tensor-lib/tensor-operations/trace.h"
#include "tensor-lib/tensor-operations/reorder.h"

#include "tensor-lib/tensor-concepts/tensor-concepts.h"

#include "tensor-lib/tensor-builder-utilities/tuple_helpers.h"

using std::cout;

int main() {

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


    constexpr auto tup_work = std::make_tuple(0,1,2,3,4,5);
    std::cout << "----start------" << tup << std::endl;
    std::cout << "tup: " << tup << std::endl;
    //tuple of tuples
    constexpr auto look = recreate_for_index_sequence<0,3,2,4,3>(tup_work);
    constexpr auto look2 = recreate_for_index_sequence<2,1,0,2,3>(tup_work);
    //decltype(look)::foo = 1;
    std::cout <<"split 1: "<< look << std::endl;
    std::cout <<"split 2: "<< look2 << std::endl;

    //decltype(look)::foo = 1;

    std::cout << "-----------" << std::endl;

    auto temp_l = std::make_tuple(1,2,3);
    std::array<decltype(temp_l), 3> cart1{temp_l,temp_l,temp_l};
    //RIGHT NOW IT TAKES A CARTESIAN PRODUCT AND DOES A OPERATION FOR EVERY TUPLE
    //tuple(tuple 1,...,tuple times), ...,
    auto eloo = save_recreated_index_sequence<0,3,0,4,2>(cart1);

    constexpr tensor<double, up_t, low_t, low_t> tensorTest1(11.0, 22.0, 33.0, 44.0, 55.0, 66.0, 77.0, 88.0, 99.0);
    constexpr tensor<double, up_t, low_t> tensorTest2(0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9);

    auto cartesii = cartesian_product<1,4>(); //<1,1> is a scalar

    for(int i = 0; i < cartesii.size(); i++){

        std::cout << cartesii[i] << std::endl;

    }

    constexpr tensor<double, up_t, up_t> tensor1(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    constexpr tensor<double, up_t> tensor2(0.1, 0.2, 0.3);

    constexpr auto copyObj1 = tensor1;
    constexpr auto indices = tensor1.indices_amount;
    constexpr auto indices1 = tensor1.calculate_indices();

    //constexpr auto contract = contraction<0,0, tensor1, tensor2>();
    constexpr auto contract = contraction<10, tensor2>();
    //decltype(contract)::foo = 1;
    for(auto i : contract.data){
        std::cout << i << std::endl;
    }

    //---------------------------------------------------------
    auto l = std::make_tuple(1);
    auto d = std::make_tuple(1);
    remove_ith_concat_tuple<0,0,decltype(l),decltype(d)> bono;
    decltype(bono)::type a;
    //---------------------------------------------------------

    auto dd = a;

    return 0;
}

