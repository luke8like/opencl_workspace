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
include src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/depend.make

# Include the progress variables for this target.
include src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/progress.make

# Include the compile flags for this target's objects.
include src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/flags.make

src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o: src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/flags.make
src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o: src/Ch1/device_extensions/device_extensions.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/tayboonl/PACKT_OpenCL_Book/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/DeviceExtensions.dir/device_extensions.c.o   -c /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions/device_extensions.c

src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DeviceExtensions.dir/device_extensions.c.i"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions/device_extensions.c > CMakeFiles/DeviceExtensions.dir/device_extensions.c.i

src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DeviceExtensions.dir/device_extensions.c.s"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions/device_extensions.c -o CMakeFiles/DeviceExtensions.dir/device_extensions.c.s

src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o.requires:
.PHONY : src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o.requires

src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o.provides: src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o.requires
	$(MAKE) -f src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/build.make src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o.provides.build
.PHONY : src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o.provides

src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o.provides.build: src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o

# Object files for target DeviceExtensions
DeviceExtensions_OBJECTS = \
"CMakeFiles/DeviceExtensions.dir/device_extensions.c.o"

# External object files for target DeviceExtensions
DeviceExtensions_EXTERNAL_OBJECTS =

src/Ch1/device_extensions/DeviceExtensions: src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o
src/Ch1/device_extensions/DeviceExtensions: src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/build.make
src/Ch1/device_extensions/DeviceExtensions: src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable DeviceExtensions"
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DeviceExtensions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/build: src/Ch1/device_extensions/DeviceExtensions
.PHONY : src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/build

src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/requires: src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/device_extensions.c.o.requires
.PHONY : src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/requires

src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/clean:
	cd /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions && $(CMAKE_COMMAND) -P CMakeFiles/DeviceExtensions.dir/cmake_clean.cmake
.PHONY : src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/clean

src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/depend:
	cd /Users/tayboonl/PACKT_OpenCL_Book && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions /Users/tayboonl/PACKT_OpenCL_Book /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions /Users/tayboonl/PACKT_OpenCL_Book/src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Ch1/device_extensions/CMakeFiles/DeviceExtensions.dir/depend
