# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tayboonl/PACKT_OpenCL_Book

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tayboonl/PACKT_OpenCL_Book

# Include any dependencies generated for this target.
include src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/depend.make

# Include the progress variables for this target.
include src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/progress.make

# Include the compile flags for this target's objects.
include src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/flags.make

src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o: src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/flags.make
src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o: src/Ch4/simple_vector_load/vector_load.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/tayboonl/PACKT_OpenCL_Book/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/VectorLoad.dir/vector_load.c.o   -c /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load/vector_load.c

src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/VectorLoad.dir/vector_load.c.i"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load/vector_load.c > CMakeFiles/VectorLoad.dir/vector_load.c.i

src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/VectorLoad.dir/vector_load.c.s"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load/vector_load.c -o CMakeFiles/VectorLoad.dir/vector_load.c.s

src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o.requires:
.PHONY : src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o.requires

src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o.provides: src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o.requires
	$(MAKE) -f src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/build.make src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o.provides.build
.PHONY : src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o.provides

src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o.provides.build: src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o

# Object files for target VectorLoad
VectorLoad_OBJECTS = \
"CMakeFiles/VectorLoad.dir/vector_load.c.o"

# External object files for target VectorLoad
VectorLoad_EXTERNAL_OBJECTS =

src/Ch4/simple_vector_load/VectorLoad: src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o
src/Ch4/simple_vector_load/VectorLoad: src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/build.make
src/Ch4/simple_vector_load/VectorLoad: src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable VectorLoad"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VectorLoad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/build: src/Ch4/simple_vector_load/VectorLoad
.PHONY : src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/build

src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/requires: src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/vector_load.c.o.requires
.PHONY : src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/requires

src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/clean:
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load && $(CMAKE_COMMAND) -P CMakeFiles/VectorLoad.dir/cmake_clean.cmake
.PHONY : src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/clean

src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/depend:
	cd /Users/tayboonl/PACKT_OpenCL_Book && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load /Users/tayboonl/PACKT_OpenCL_Book/src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Ch4/simple_vector_load/CMakeFiles/VectorLoad.dir/depend
