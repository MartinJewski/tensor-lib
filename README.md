[Alpha]My bachelor thesis in which I am implementing tensors 
and the operations contraction, trace and reordering, with a special
focus on compile time vs. runtime execution. 

It contains an implementation at compile time
and runtime, where the runtime version is implemented using standard C++17
or the ranges-v3 library(C++20) and the compile time version is implemented
using only C++17 features.



tested on my machine using:

Compiler GCC 9.2

ranges-v3 by ericnibler https://github.com/ericniebler/range-v3

CLion IDE project option to use C++20
-CMAKE minimum VERSION 3.15
-CMAKE_CXX_STANDARD 20


Kubuntu 19.04