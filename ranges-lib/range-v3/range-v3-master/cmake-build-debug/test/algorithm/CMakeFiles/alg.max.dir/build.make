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
include test/algorithm/CMakeFiles/alg.max.dir/depend.make

# Include the progress variables for this target.
include test/algorithm/CMakeFiles/alg.max.dir/progress.make

# Include the compile flags for this target's objects.
include test/algorithm/CMakeFiles/alg.max.dir/flags.make

test/algorithm/CMakeFiles/alg.max.dir/max.cpp.o: test/algorithm/CMakeFiles/alg.max.dir/flags.make
test/algorithm/CMakeFiles/alg.max.dir/max.cpp.o: ../test/algorithm/max.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/algorithm/CMakeFiles/alg.max.dir/max.cpp.o"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/algorithm && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/alg.max.dir/max.cpp.o -c /home/martin/CLionProjects/range-v3/range-v3-master/test/algorithm/max.cpp

test/algorithm/CMakeFiles/alg.max.dir/max.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alg.max.dir/max.cpp.i"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/algorithm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martin/CLionProjects/range-v3/range-v3-master/test/algorithm/max.cpp > CMakeFiles/alg.max.dir/max.cpp.i

test/algorithm/CMakeFiles/alg.max.dir/max.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alg.max.dir/max.cpp.s"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/algorithm && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martin/CLionProjects/range-v3/range-v3-master/test/algorithm/max.cpp -o CMakeFiles/alg.max.dir/max.cpp.s

# Object files for target alg.max
alg_max_OBJECTS = \
"CMakeFiles/alg.max.dir/max.cpp.o"

# External object files for target alg.max
alg_max_EXTERNAL_OBJECTS =

test/algorithm/alg.max: test/algorithm/CMakeFiles/alg.max.dir/max.cpp.o
test/algorithm/alg.max: test/algorithm/CMakeFiles/alg.max.dir/build.make
test/algorithm/alg.max: test/algorithm/CMakeFiles/alg.max.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable alg.max"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/algorithm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alg.max.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/algorithm/CMakeFiles/alg.max.dir/build: test/algorithm/alg.max

.PHONY : test/algorithm/CMakeFiles/alg.max.dir/build

test/algorithm/CMakeFiles/alg.max.dir/clean:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/algorithm && $(CMAKE_COMMAND) -P CMakeFiles/alg.max.dir/cmake_clean.cmake
.PHONY : test/algorithm/CMakeFiles/alg.max.dir/clean

test/algorithm/CMakeFiles/alg.max.dir/depend:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/martin/CLionProjects/range-v3/range-v3-master /home/martin/CLionProjects/range-v3/range-v3-master/test/algorithm /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/algorithm /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/algorithm/CMakeFiles/alg.max.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/algorithm/CMakeFiles/alg.max.dir/depend

