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
CMAKE_SOURCE_DIR = D:\CLionProjects\Tree2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\Tree2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tree2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tree2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tree2.dir/flags.make

CMakeFiles/Tree2.dir/main.cpp.obj: CMakeFiles/Tree2.dir/flags.make
CMakeFiles/Tree2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\Tree2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tree2.dir/main.cpp.obj"
	"D:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Tree2.dir\main.cpp.obj -c D:\CLionProjects\Tree2\main.cpp

CMakeFiles/Tree2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tree2.dir/main.cpp.i"
	"D:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\Tree2\main.cpp > CMakeFiles\Tree2.dir\main.cpp.i

CMakeFiles/Tree2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tree2.dir/main.cpp.s"
	"D:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\Tree2\main.cpp -o CMakeFiles\Tree2.dir\main.cpp.s

# Object files for target Tree2
Tree2_OBJECTS = \
"CMakeFiles/Tree2.dir/main.cpp.obj"

# External object files for target Tree2
Tree2_EXTERNAL_OBJECTS =

Tree2.exe: CMakeFiles/Tree2.dir/main.cpp.obj
Tree2.exe: CMakeFiles/Tree2.dir/build.make
Tree2.exe: CMakeFiles/Tree2.dir/linklibs.rsp
Tree2.exe: CMakeFiles/Tree2.dir/objects1.rsp
Tree2.exe: CMakeFiles/Tree2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\Tree2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tree2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tree2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tree2.dir/build: Tree2.exe

.PHONY : CMakeFiles/Tree2.dir/build

CMakeFiles/Tree2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tree2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tree2.dir/clean

CMakeFiles/Tree2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\Tree2 D:\CLionProjects\Tree2 D:\CLionProjects\Tree2\cmake-build-debug D:\CLionProjects\Tree2\cmake-build-debug D:\CLionProjects\Tree2\cmake-build-debug\CMakeFiles\Tree2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tree2.dir/depend

