cmake_minimum_required(VERSION 3.15)
project(untiteled1 C CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(./tensor-lib/tensor-builder-utilities)
include_directories(./tensor-lib/tensor-builder-utilities-ranges)
include_directories(./tensor-lib/tensor-definition)
include_directories(./tensor-lib/tensor-operations)
include_directories(./tensor-lib/tensor-concepts)
include_directories(./tensor-lib/tensor-operations-ranges)
include_directories(./tensor-lib/tensor-definition-ranges)
include_directories(tensor-lib/speed_test)
include_directories(tensor-lib/math)

set(SOURCE_FILES main.cpp
        tensor-lib/tensor-operations/reorder_ct.h
        tensor-lib/tensor-operations/reorder.h
        tensor-lib/tensor-operations/trace_ct.h
        tensor-lib/tensor-operations/trace.h
        tensor-lib/tensor-operations/contraction.h
        tensor-lib/tensor-operations/contraction_ct.h

        tensor-lib/tensor-builder-utilities-ranges/cartesian_product_ranges.h
        tensor-lib/tensor-builder-utilities-ranges/cartesian_product_ranges_to_vec.h

        tensor-lib/tensor-builder-utilities/positive_natural_compiletime_pow.h
        tensor-lib/tensor-builder-utilities/pos_nd_to_1d.h
        tensor-lib/tensor-builder-utilities/tuple_show.h
        tensor-lib/tensor-builder-utilities/tuple_split.h
        tensor-lib/tensor-builder-utilities/make_index_sequence_from.h
        tensor-lib/tensor-builder-utilities/tuple_split_from.h
        tensor-lib/tensor-builder-utilities/recreate_index_tuple.h
        tensor-lib/tensor-builder-utilities/recreate_for_index_sequence.h
        tensor-lib/tensor-builder-utilities/tuple_helpers.h
        tensor-lib/tensor-builder-utilities/random_number.h
        tensor-lib/tensor-builder-utilities/cartesian_product.h
        tensor-lib/tensor-builder-utilities/cartesian_product_adv.h
        tensor-lib/tensor-builder-utilities/tuple_type_list.h

        tensor-lib/tensor-definition/tensor.h
        tensor-lib/tensor-definition/tensor_specification.h

        tensor-lib/tensor-operations-ranges/trace_ranges.h
        tensor-lib/tensor-definition-ranges/tensor_range.h

        tensor-lib/tensor-concepts/tensor-concepts.h

        tensor-lib/speed_test/speed_test_expressionTemp_contraction.h
        tensor-lib/speed_test/speed_test_expressionTemp_reorder.h
        tensor-lib/speed_test/speed_test_expressionTemp_trace.h

        tensor-lib/speed_test/speed_test_forLoop_reorder.h
        tensor-lib/speed_test/speed_test_forLoop_trace.h
        tensor-lib/speed_test/speed_test_forLoop_contraction.h
        tensor-lib/speed_test/speed_test_compileTime_reorder.h
        tensor-lib/speed_test/speed_test_compileTime_trace.h
        tensor-lib/speed_test/speed_test_compileTime_contraction.h
        tensor-lib/speed_test/speed_test_runtime_contraction.h
        tensor-lib/speed_test/speed_test_tensors.h
        tensor-lib/speed_test/speed_test_ranges_contraction.h

        tensor-lib/math/math_utilities.h
        )

add_library(range_v3 INTERFACE IMPORTED)
set_target_properties(range_v3 PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/ranges-lib/range-v3/range-v3-master/include)


#add_library(ep_tensor_lib INTERFACE IMPORTED)
#set_target_properties(ep_tensor_lib PROPERTIES
#        INTERFACE_INCLUDE_DIRECTORIES /home/martin/CLionProjects/ET_Tensor_Library)

add_compile_options(-fconcepts) #enables concepts(unstable). Stable versions will be released with gcc/g++ 10
add_compile_options(-fpermissive)
add_compile_options(-ftemplate-depth=2000)


add_executable(untiteled1 ${SOURCE_FILES} ${SOURCE_FILES2})

target_link_libraries(untiteled1 range_v3) #link libraries to exe
#target_link_libraries(untiteled1 ep_tensor_lib) #link libraries to exe