# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jamesdonnelly/Desktop/CS50/ceasar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jamesdonnelly/Desktop/CS50/ceasar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ceasar.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ceasar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ceasar.dir/flags.make

CMakeFiles/ceasar.dir/main.c.o: CMakeFiles/ceasar.dir/flags.make
CMakeFiles/ceasar.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jamesdonnelly/Desktop/CS50/ceasar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ceasar.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ceasar.dir/main.c.o -c /Users/jamesdonnelly/Desktop/CS50/ceasar/main.c

CMakeFiles/ceasar.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ceasar.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jamesdonnelly/Desktop/CS50/ceasar/main.c > CMakeFiles/ceasar.dir/main.c.i

CMakeFiles/ceasar.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ceasar.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jamesdonnelly/Desktop/CS50/ceasar/main.c -o CMakeFiles/ceasar.dir/main.c.s

# Object files for target ceasar
ceasar_OBJECTS = \
"CMakeFiles/ceasar.dir/main.c.o"

# External object files for target ceasar
ceasar_EXTERNAL_OBJECTS =

ceasar: CMakeFiles/ceasar.dir/main.c.o
ceasar: CMakeFiles/ceasar.dir/build.make
ceasar: CMakeFiles/ceasar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jamesdonnelly/Desktop/CS50/ceasar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ceasar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ceasar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ceasar.dir/build: ceasar
.PHONY : CMakeFiles/ceasar.dir/build

CMakeFiles/ceasar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ceasar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ceasar.dir/clean

CMakeFiles/ceasar.dir/depend:
	cd /Users/jamesdonnelly/Desktop/CS50/ceasar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jamesdonnelly/Desktop/CS50/ceasar /Users/jamesdonnelly/Desktop/CS50/ceasar /Users/jamesdonnelly/Desktop/CS50/ceasar/cmake-build-debug /Users/jamesdonnelly/Desktop/CS50/ceasar/cmake-build-debug /Users/jamesdonnelly/Desktop/CS50/ceasar/cmake-build-debug/CMakeFiles/ceasar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ceasar.dir/depend
