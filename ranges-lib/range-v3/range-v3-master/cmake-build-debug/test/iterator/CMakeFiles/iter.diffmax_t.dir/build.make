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
include test/iterator/CMakeFiles/iter.diffmax_t.dir/depend.make

# Include the progress variables for this target.
include test/iterator/CMakeFiles/iter.diffmax_t.dir/progress.make

# Include the compile flags for this target's objects.
include test/iterator/CMakeFiles/iter.diffmax_t.dir/flags.make

test/iterator/CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.o: test/iterator/CMakeFiles/iter.diffmax_t.dir/flags.make
test/iterator/CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.o: ../test/iterator/diffmax_t.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/iterator/CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.o"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/iterator && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.o -c /home/martin/CLionProjects/range-v3/range-v3-master/test/iterator/diffmax_t.cpp

test/iterator/CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.i"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/iterator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martin/CLionProjects/range-v3/range-v3-master/test/iterator/diffmax_t.cpp > CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.i

test/iterator/CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.s"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/iterator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martin/CLionProjects/range-v3/range-v3-master/test/iterator/diffmax_t.cpp -o CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.s

# Object files for target iter.diffmax_t
iter_diffmax_t_OBJECTS = \
"CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.o"

# External object files for target iter.diffmax_t
iter_diffmax_t_EXTERNAL_OBJECTS =

test/iterator/iter.diffmax_t: test/iterator/CMakeFiles/iter.diffmax_t.dir/diffmax_t.cpp.o
test/iterator/iter.diffmax_t: test/iterator/CMakeFiles/iter.diffmax_t.dir/build.make
test/iterator/iter.diffmax_t: test/iterator/CMakeFiles/iter.diffmax_t.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable iter.diffmax_t"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/iterator && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iter.diffmax_t.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/iterator/CMakeFiles/iter.diffmax_t.dir/build: test/iterator/iter.diffmax_t

.PHONY : test/iterator/CMakeFiles/iter.diffmax_t.dir/build

test/iterator/CMakeFiles/iter.diffmax_t.dir/clean:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/iterator && $(CMAKE_COMMAND) -P CMakeFiles/iter.diffmax_t.dir/cmake_clean.cmake
.PHONY : test/iterator/CMakeFiles/iter.diffmax_t.dir/clean

test/iterator/CMakeFiles/iter.diffmax_t.dir/depend:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/martin/CLionProjects/range-v3/range-v3-master /home/martin/CLionProjects/range-v3/range-v3-master/test/iterator /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/iterator /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/iterator/CMakeFiles/iter.diffmax_t.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/iterator/CMakeFiles/iter.diffmax_t.dir/depend

