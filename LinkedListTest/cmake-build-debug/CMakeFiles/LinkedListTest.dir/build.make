# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProjects\LinkedListTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\LinkedListTest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LinkedListTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LinkedListTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkedListTest.dir/flags.make

CMakeFiles/LinkedListTest.dir/main.cpp.obj: CMakeFiles/LinkedListTest.dir/flags.make
CMakeFiles/LinkedListTest.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\LinkedListTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LinkedListTest.dir/main.cpp.obj"
	"D:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LinkedListTest.dir\main.cpp.obj -c D:\CLionProjects\LinkedListTest\main.cpp

CMakeFiles/LinkedListTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkedListTest.dir/main.cpp.i"
	"D:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\LinkedListTest\main.cpp > CMakeFiles\LinkedListTest.dir\main.cpp.i

CMakeFiles/LinkedListTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkedListTest.dir/main.cpp.s"
	"D:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\LinkedListTest\main.cpp -o CMakeFiles\LinkedListTest.dir\main.cpp.s

# Object files for target LinkedListTest
LinkedListTest_OBJECTS = \
"CMakeFiles/LinkedListTest.dir/main.cpp.obj"

# External object files for target LinkedListTest
LinkedListTest_EXTERNAL_OBJECTS =

LinkedListTest.exe: CMakeFiles/LinkedListTest.dir/main.cpp.obj
LinkedListTest.exe: CMakeFiles/LinkedListTest.dir/build.make
LinkedListTest.exe: CMakeFiles/LinkedListTest.dir/linklibs.rsp
LinkedListTest.exe: CMakeFiles/LinkedListTest.dir/objects1.rsp
LinkedListTest.exe: CMakeFiles/LinkedListTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\LinkedListTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LinkedListTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LinkedListTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkedListTest.dir/build: LinkedListTest.exe

.PHONY : CMakeFiles/LinkedListTest.dir/build

CMakeFiles/LinkedListTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LinkedListTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LinkedListTest.dir/clean

CMakeFiles/LinkedListTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\LinkedListTest D:\CLionProjects\LinkedListTest D:\CLionProjects\LinkedListTest\cmake-build-debug D:\CLionProjects\LinkedListTest\cmake-build-debug D:\CLionProjects\LinkedListTest\cmake-build-debug\CMakeFiles\LinkedListTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinkedListTest.dir/depend

