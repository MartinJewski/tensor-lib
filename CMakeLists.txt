cmake_minimum_required(VERSION 3.15)
project(untiteled1 C CXX)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp
        header/ranges.h
        header/tensor.h
        header/tensor_specification.h
        tensor-lib/tensor-builder/tensor_cartesian_product.h
        tensor-lib/tensor-builder/tuple_show.h
        tensor-lib/tensor-builder/range_of_nonviewable_container_show.h
        tensor-lib/tensor-builder/tensor_enumerate_range.h tensor-lib/tensor-builder/tuple_split.h tensor-lib/tensor-builder/make_index_sequence_from.h tensor-lib/tensor-builder/tuple_split_from.h tensor-lib/tensor-builder/recreate_index_tuple.h tensor-lib/tensor-builder/recreate_for_index_sequence.h)

add_library(range_v3 INTERFACE IMPORTED)
set_target_properties(range_v3 PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES /home/martin/CLionProjects/Libraries/range-v3/range-v3-master/include)

add_compile_options(-fconcepts) #enables concepts(unstable). Stable versions will be released with gcc/g++ 10


add_executable(untiteled1 ${SOURCE_FILES} ${SOURCE_FILES2})

target_link_libraries(untiteled1 range_v3) #link libraries to exe