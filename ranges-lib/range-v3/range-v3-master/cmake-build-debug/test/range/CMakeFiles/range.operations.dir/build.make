# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/martin/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5233.10/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/martin/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5233.10/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/martin/CLionProjects/range-v3/range-v3-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug

# Include any dependencies generated for this target.
include test/range/CMakeFiles/range.operations.dir/depend.make

# Include the progress variables for this target.
include test/range/CMakeFiles/range.operations.dir/progress.make

# Include the compile flags for this target's objects.
include test/range/CMakeFiles/range.operations.dir/flags.make

test/range/CMakeFiles/range.operations.dir/operations.cpp.o: test/range/CMakeFiles/range.operations.dir/flags.make
test/range/CMakeFiles/range.operations.dir/operations.cpp.o: ../test/range/operations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/range/CMakeFiles/range.operations.dir/operations.cpp.o"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/range && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/range.operations.dir/operations.cpp.o -c /home/martin/CLionProjects/range-v3/range-v3-master/test/range/operations.cpp

test/range/CMakeFiles/range.operations.dir/operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/range.operations.dir/operations.cpp.i"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/range && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martin/CLionProjects/range-v3/range-v3-master/test/range/operations.cpp > CMakeFiles/range.operations.dir/operations.cpp.i

test/range/CMakeFiles/range.operations.dir/operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/range.operations.dir/operations.cpp.s"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/range && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martin/CLionProjects/range-v3/range-v3-master/test/range/operations.cpp -o CMakeFiles/range.operations.dir/operations.cpp.s

# Object files for target range.operations
range_operations_OBJECTS = \
"CMakeFiles/range.operations.dir/operations.cpp.o"

# External object files for target range.operations
range_operations_EXTERNAL_OBJECTS =

test/range/range.operations: test/range/CMakeFiles/range.operations.dir/operations.cpp.o
test/range/range.operations: test/range/CMakeFiles/range.operations.dir/build.make
test/range/range.operations: test/range/CMakeFiles/range.operations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable range.operations"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/range && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/range.operations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/range/CMakeFiles/range.operations.dir/build: test/range/range.operations

.PHONY : test/range/CMakeFiles/range.operations.dir/build

test/range/CMakeFiles/range.operations.dir/clean:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/range && $(CMAKE_COMMAND) -P CMakeFiles/range.operations.dir/cmake_clean.cmake
.PHONY : test/range/CMakeFiles/range.operations.dir/clean

test/range/CMakeFiles/range.operations.dir/depend:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/martin/CLionProjects/range-v3/range-v3-master /home/martin/CLionProjects/range-v3/range-v3-master/test/range /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/range /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/range/CMakeFiles/range.operations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/range/CMakeFiles/range.operations.dir/depend
