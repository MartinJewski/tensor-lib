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
include example/CMakeFiles/any_all_none_of.dir/depend.make

# Include the progress variables for this target.
include example/CMakeFiles/any_all_none_of.dir/progress.make

# Include the compile flags for this target's objects.
include example/CMakeFiles/any_all_none_of.dir/flags.make

example/CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.o: example/CMakeFiles/any_all_none_of.dir/flags.make
example/CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.o: ../example/any_all_none_of.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example/CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.o"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/example && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.o -c /home/martin/CLionProjects/range-v3/range-v3-master/example/any_all_none_of.cpp

example/CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.i"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/martin/CLionProjects/range-v3/range-v3-master/example/any_all_none_of.cpp > CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.i

example/CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.s"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/example && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/martin/CLionProjects/range-v3/range-v3-master/example/any_all_none_of.cpp -o CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.s

# Object files for target any_all_none_of
any_all_none_of_OBJECTS = \
"CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.o"

# External object files for target any_all_none_of
any_all_none_of_EXTERNAL_OBJECTS =

example/any_all_none_of: example/CMakeFiles/any_all_none_of.dir/any_all_none_of.cpp.o
example/any_all_none_of: example/CMakeFiles/any_all_none_of.dir/build.make
example/any_all_none_of: example/CMakeFiles/any_all_none_of.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable any_all_none_of"
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/example && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/any_all_none_of.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example/CMakeFiles/any_all_none_of.dir/build: example/any_all_none_of

.PHONY : example/CMakeFiles/any_all_none_of.dir/build

example/CMakeFiles/any_all_none_of.dir/clean:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/example && $(CMAKE_COMMAND) -P CMakeFiles/any_all_none_of.dir/cmake_clean.cmake
.PHONY : example/CMakeFiles/any_all_none_of.dir/clean

example/CMakeFiles/any_all_none_of.dir/depend:
	cd /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/martin/CLionProjects/range-v3/range-v3-master /home/martin/CLionProjects/range-v3/range-v3-master/example /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/example /home/martin/CLionProjects/range-v3/range-v3-master/cmake-build-debug/example/CMakeFiles/any_all_none_of.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example/CMakeFiles/any_all_none_of.dir/depend

