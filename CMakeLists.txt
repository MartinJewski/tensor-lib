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

        tensor-lib/tensor-definition/tensor.h
        tensor-lib/tensor-definition/tensor_specification.h

        tensor-lib/tensor-operations-ranges/trace_ranges.h
        tensor-lib/tensor-definition-ranges/tensor_range.h

        tensor-lib/tensor-concepts/tensor-concepts.h
        )

add_library(range_v3 INTERFACE IMPORTED)
set_target_properties(range_v3 PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES /home/martin/CLionProjects/Libraries/range-v3/range-v3-master/include)

add_compile_options(-fconcepts) #enables concepts(unstable). Stable versions will be released with gcc/g++ 10
add_compile_options(-fpermissive)
add_compile_options(-ftemplate-depth=2000)


add_executable(untiteled1 ${SOURCE_FILES} ${SOURCE_FILES2})

target_link_libraries(untiteled1 range_v3) #link libraries to exe