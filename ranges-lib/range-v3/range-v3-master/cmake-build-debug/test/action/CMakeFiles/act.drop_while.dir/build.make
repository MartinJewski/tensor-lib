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
include test/action/CMakeFiles/act.drop_while.dir/depend.make

# Include the progress variables for this target.
include test/action/CMakeFiles/act.drop_while.dir/progress.make

# Include the compile flags for this target's objects.
include test/action/CMakeFiles/act.drop_while.dir/flags.make

test/action/CMakeFiles/act.drop_while.dir/drop_while.cpp.o: test/action/CMakeFiles/act.drop_while.dir/flags.make
test/action/CMakeFiles/act.drop_while.dir/drop_while.cpp.o: ../test/action/drop_while.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/action/CMakeFiles/act.drop_while.dir/drop_while.cpp.o"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/action && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/act.drop_while.dir/drop_while.cpp.o -c /home/martin/CLionProjects/range-v3/range-v3-master/test/action/drop_while.cpp

test/action/CMakeFiles/act.drop_while.dir/drop_while.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/act.drop_while.dir/drop_while.cpp.i"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/action && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martin/CLionProjects/range-v3/range-v3-master/test/action/drop_while.cpp > CMakeFiles/act.drop_while.dir/drop_while.cpp.i

test/action/CMakeFiles/act.drop_while.dir/drop_while.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/act.drop_while.dir/drop_while.cpp.s"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/action && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martin/CLionProjects/range-v3/range-v3-master/test/action/drop_while.cpp -o CMakeFiles/act.drop_while.dir/drop_while.cpp.s

# Object files for target act.drop_while
act_drop_while_OBJECTS = \
"CMakeFiles/act.drop_while.dir/drop_while.cpp.o"

# External object files for target act.drop_while
act_drop_while_EXTERNAL_OBJECTS =

test/action/act.drop_while: test/action/CMakeFiles/act.drop_while.dir/drop_while.cpp.o
test/action/act.drop_while: test/action/CMakeFiles/act.drop_while.dir/build.make
test/action/act.drop_while: test/action/CMakeFiles/act.drop_while.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable act.drop_while"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/action && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/act.drop_while.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/action/CMakeFiles/act.drop_while.dir/build: test/action/act.drop_while

.PHONY : test/action/CMakeFiles/act.drop_while.dir/build

test/action/CMakeFiles/act.drop_while.dir/clean:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/action && $(CMAKE_COMMAND) -P CMakeFiles/act.drop_while.dir/cmake_clean.cmake
.PHONY : test/action/CMakeFiles/act.drop_while.dir/clean

test/action/CMakeFiles/act.drop_while.dir/depend:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/martin/CLionProjects/range-v3/range-v3-master /home/martin/CLionProjects/range-v3/range-v3-master/test/action /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/action /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/test/action/CMakeFiles/act.drop_while.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/action/CMakeFiles/act.drop_while.dir/depend

