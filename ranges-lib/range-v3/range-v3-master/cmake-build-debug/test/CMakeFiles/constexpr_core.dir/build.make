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
include test/CMakeFiles/constexpr_core.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/constexpr_core.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/constexpr_core.dir/flags.make

test/CMakeFiles/constexpr_core.dir/constexpr_core.cpp.o: test/CMakeFiles/constexpr_core.dir/flags.make
test/CMakeFiles/constexpr_core.dir/constexpr_core.cpp.o: ../test/constexpr_core.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/constexpr_core.dir/constexpr_core.cpp.o"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/constexpr_core.dir/constexpr_core.cpp.o -c /home/martin/CLionProjects/range-v3/range-v3-master/test/constexpr_core.cpp

test/CMakeFiles/constexpr_core.dir/constexpr_core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/constexpr_core.dir/constexpr_core.cpp.i"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martin/CLionProjects/range-v3/range-v3-master/test/constexpr_core.cpp > CMakeFiles/constexpr_core.dir/constexpr_core.cpp.i

test/CMakeFiles/constexpr_core.dir/constexpr_core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/constexpr_core.dir/constexpr_core.cpp.s"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martin/CLionProjects/range-v3/range-v3-master/test/constexpr_core.cpp -o CMakeFiles/constexpr_core.dir/constexpr_core.cpp.s

# Object files for target constexpr_core
constexpr_core_OBJECTS = \
"CMakeFiles/constexpr_core.dir/constexpr_core.cpp.o"

# External object files for target constexpr_core
constexpr_core_EXTERNAL_OBJECTS =

test/constexpr_core: test/CMakeFiles/constexpr_core.dir/constexpr_core.cpp.o
test/constexpr_core: test/CMakeFiles/constexpr_core.dir/build.make
test/constexpr_core: test/CMakeFiles/constexpr_core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable constexpr_core"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/constexpr_core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/constexpr_core.dir/build: test/constexpr_core

.PHONY : test/CMakeFiles/constexpr_core.dir/build

test/CMakeFiles/constexpr_core.dir/clean:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/constexpr_core.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/constexpr_core.dir/clean

test/CMakeFiles/constexpr_core.dir/depend:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/martin/CLionProjects/range-v3/range-v3-master /home/martin/CLionProjects/range-v3/range-v3-master/test /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/CMakeFiles/constexpr_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/constexpr_core.dir/depend
