# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Lucas\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Lucas\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Lucas\Desktop\Study\algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Lucas\Desktop\Study\algorithm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/algorithm_Array_bubbleSort.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/algorithm_Array_bubbleSort.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/algorithm_Array_bubbleSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algorithm_Array_bubbleSort.dir/flags.make

CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.obj: CMakeFiles/algorithm_Array_bubbleSort.dir/flags.make
CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.obj: C:/Users/Lucas/Desktop/Study/algorithm/Array_bubbleSort.cpp
CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.obj: CMakeFiles/algorithm_Array_bubbleSort.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Lucas\Desktop\Study\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.obj"
	C:\Users\Lucas\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.obj -MF CMakeFiles\algorithm_Array_bubbleSort.dir\Array_bubbleSort.cpp.obj.d -o CMakeFiles\algorithm_Array_bubbleSort.dir\Array_bubbleSort.cpp.obj -c C:\Users\Lucas\Desktop\Study\algorithm\Array_bubbleSort.cpp

CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.i"
	C:\Users\Lucas\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Lucas\Desktop\Study\algorithm\Array_bubbleSort.cpp > CMakeFiles\algorithm_Array_bubbleSort.dir\Array_bubbleSort.cpp.i

CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.s"
	C:\Users\Lucas\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Lucas\Desktop\Study\algorithm\Array_bubbleSort.cpp -o CMakeFiles\algorithm_Array_bubbleSort.dir\Array_bubbleSort.cpp.s

# Object files for target algorithm_Array_bubbleSort
algorithm_Array_bubbleSort_OBJECTS = \
"CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.obj"

# External object files for target algorithm_Array_bubbleSort
algorithm_Array_bubbleSort_EXTERNAL_OBJECTS =

algorithm_Array_bubbleSort.exe: CMakeFiles/algorithm_Array_bubbleSort.dir/Array_bubbleSort.cpp.obj
algorithm_Array_bubbleSort.exe: CMakeFiles/algorithm_Array_bubbleSort.dir/build.make
algorithm_Array_bubbleSort.exe: CMakeFiles/algorithm_Array_bubbleSort.dir/linkLibs.rsp
algorithm_Array_bubbleSort.exe: CMakeFiles/algorithm_Array_bubbleSort.dir/objects1.rsp
algorithm_Array_bubbleSort.exe: CMakeFiles/algorithm_Array_bubbleSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Lucas\Desktop\Study\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algorithm_Array_bubbleSort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algorithm_Array_bubbleSort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algorithm_Array_bubbleSort.dir/build: algorithm_Array_bubbleSort.exe
.PHONY : CMakeFiles/algorithm_Array_bubbleSort.dir/build

CMakeFiles/algorithm_Array_bubbleSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algorithm_Array_bubbleSort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/algorithm_Array_bubbleSort.dir/clean

CMakeFiles/algorithm_Array_bubbleSort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Lucas\Desktop\Study\algorithm C:\Users\Lucas\Desktop\Study\algorithm C:\Users\Lucas\Desktop\Study\algorithm\cmake-build-debug C:\Users\Lucas\Desktop\Study\algorithm\cmake-build-debug C:\Users\Lucas\Desktop\Study\algorithm\cmake-build-debug\CMakeFiles\algorithm_Array_bubbleSort.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/algorithm_Array_bubbleSort.dir/depend

