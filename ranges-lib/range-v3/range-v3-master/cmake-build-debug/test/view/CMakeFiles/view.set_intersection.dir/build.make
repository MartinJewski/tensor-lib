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
include test/view/CMakeFiles/view.set_intersection.dir/depend.make

# Include the progress variables for this target.
include test/view/CMakeFiles/view.set_intersection.dir/progress.make

# Include the compile flags for this target's objects.
include test/view/CMakeFiles/view.set_intersection.dir/flags.make

test/view/CMakeFiles/view.set_intersection.dir/set_intersection.cpp.o: test/view/CMakeFiles/view.set_intersection.dir/flags.make
test/view/CMakeFiles/view.set_intersection.dir/set_intersection.cpp.o: ../test/view/set_intersection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/view/CMakeFiles/view.set_intersection.dir/set_intersection.cpp.o"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/view && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/view.set_intersection.dir/set_intersection.cpp.o -c /home/martin/CLionProjects/range-v3/range-v3-master/test/view/set_intersection.cpp

test/view/CMakeFiles/view.set_intersection.dir/set_intersection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/view.set_intersection.dir/set_intersection.cpp.i"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/view && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martin/CLionProjects/range-v3/range-v3-master/test/view/set_intersection.cpp > CMakeFiles/view.set_intersection.dir/set_intersection.cpp.i

test/view/CMakeFiles/view.set_intersection.dir/set_intersection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/view.set_intersection.dir/set_intersection.cpp.s"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/view && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martin/CLionProjects/range-v3/range-v3-master/test/view/set_intersection.cpp -o CMakeFiles/view.set_intersection.dir/set_intersection.cpp.s

# Object files for target view.set_intersection
view_set_intersection_OBJECTS = \
"CMakeFiles/view.set_intersection.dir/set_intersection.cpp.o"

# External object files for target view.set_intersection
view_set_intersection_EXTERNAL_OBJECTS =

test/view/view.set_intersection: test/view/CMakeFiles/view.set_intersection.dir/set_intersection.cpp.o
test/view/view.set_intersection: test/view/CMakeFiles/view.set_intersection.dir/build.make
test/view/view.set_intersection: test/view/CMakeFiles/view.set_intersection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable view.set_intersection"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/view && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/view.set_intersection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/view/CMakeFiles/view.set_intersection.dir/build: test/view/view.set_intersection

.PHONY : test/view/CMakeFiles/view.set_intersection.dir/build

test/view/CMakeFiles/view.set_intersection.dir/clean:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/view && $(CMAKE_COMMAND) -P CMakeFiles/view.set_intersection.dir/cmake_clean.cmake
.PHONY : test/view/CMakeFiles/view.set_intersection.dir/clean

test/view/CMakeFiles/view.set_intersection.dir/depend:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/martin/CLionProjects/range-v3/range-v3-master /home/martin/CLionProjects/range-v3/range-v3-master/test/view /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/view /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/view/CMakeFiles/view.set_intersection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/view/CMakeFiles/view.set_intersection.dir/depend

