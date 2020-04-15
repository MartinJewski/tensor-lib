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
#include_directories(tensor-lib/speed_test)
include_directories(tensor-lib/math)

set(SOURCE_FILES main.cpp
        tensor-lib/tensor-operations/reorder_ct.h
        tensor-lib/tensor-operations/reorder.h
        tensor-lib/tensor-operations/trace_ct.h
        tensor-lib/tensor-operations/trace.h
        tensor-lib/tensor-operations/contraction.h
        tensor-lib/tensor-operations/contraction_ct.h
        tensor-lib/tensor-operations/trace_contraction_ct.h
        tensor-lib/tensor-operations/trace_contraction.h


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
        tensor-lib/tensor-operations-ranges/trace_contraction_ranges.h

        tensor-lib/tensor-concepts/tensor-concepts.h

        #tensor-lib/speed_test/speed_test_expressionTemp_contraction.h
        #tensor-lib/speed_test/speed_test_expressionTemp_reorder.h
        #tensor-lib/speed_test/speed_test_expressionTemp_trace.h

        #tensor-lib/speed_test/speed_test_forLoop_reorder.h
        #tensor-lib/speed_test/speed_test_forLoop_trace.h
        #tensor-lib/speed_test/speed_test_forLoop_contraction.h
        #tensor-lib/speed_test/speed_test_compileTime_reorder.h
        #tensor-lib/speed_test/speed_test_compileTime_trace.h
        #tensor-lib/speed_test/speed_test_compileTime_contraction.h
        #tensor-lib/speed_test/speed_test_runtime_contraction.h
        #tensor-lib/speed_test/speed_test_tensors.h
        #tensor-lib/speed_test/speed_test_ranges_contraction.h

        tensor-lib/math/math_utilities.h
        )

#original
#add_library(range_v3 TAGS)
#set_target_properties(range_v3 TAGS ${PROJECT_SOURCE_DIR}/ranges-lib/range-v3/range-v3-master/include)

#verwende add_library(name_der_variable INTERFACE IMPORTED)
#und set_target_properties(name_der_variable INTERFACE_INCLUDE_DIRECTORIES  PATH_TO_tensor-library-v1)
#
#
add_library(range_v3 INTERFACE IMPORTED)
set_target_properties(range_v3 PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/ranges-lib-update/range-v3/range-v3-master/include)


#add_library(ep_tensor_lib INTERFACE IMPORTED)
#set_target_properties(ep_tensor_lib PROPERTIES
#        INTERFACE_INCLUDE_DIRECTORIES /home/martin/CLionProjects/ET_Tensor_Library)

add_compile_options(-fconcepts) #enables concepts(unstable). Stable versions will be released with gcc/g++ 10
add_compile_options(-fpermissive)
add_compile_options(-ftemplate-depth=2000)


add_executable(untiteled1 ${SOURCE_FILES} ${SOURCE_FILES2})

#nachdem add_executable befehl verlinkst du die libraries mit deiner exe
target_link_libraries(untiteled1 range_v3) #link libraries to exe
#target_link_libraries(untiteled1 ep_tensor_lib) #link libraries to exe


#-----------kurzgefasster--- CMakeList aufbau-------------------
#
#
# cmake_minimum_required(VERSION <NUMBER>)
# project(proj_name C CXX)
#
# set(CMAKE_CXX_STANDARD 20)
#
# add_library(name_der_variable TAGS)   -füge deine externe library ein
# set_target_properties(name_der_variable TAGS PATH_TO_tensor-library-v1) - setzt eigenschaften der library
#
# add_executable(proj_name dirs_to_source_files) -erzeuge deine exe
#
# target_link_libraries(proj_name name_der_variable) - verlinke externe libraries zur exe
#-----------------------------------------------------------------

#wichtig: alle tieferen ordner, d.h SUBPATH nach dem PATH_TO_tensor-library-v1 müssen beim Zugriff
#auf die header files angegeben werden. Damit man z.B die tensor.h verwenden kann, müsste man
#         #include <SUBPATH/tensor.h>
#angeben