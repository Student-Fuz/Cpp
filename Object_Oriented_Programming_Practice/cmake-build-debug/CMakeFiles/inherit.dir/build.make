# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "D:\IDE\Clion\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\IDE\Clion\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/inherit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/inherit.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/inherit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inherit.dir/flags.make

CMakeFiles/inherit.dir/inherit/inherit.cpp.obj: CMakeFiles/inherit.dir/flags.make
CMakeFiles/inherit.dir/inherit/inherit.cpp.obj: ../inherit/inherit.cpp
CMakeFiles/inherit.dir/inherit/inherit.cpp.obj: CMakeFiles/inherit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/inherit.dir/inherit/inherit.cpp.obj"
	D:\IDE\Clion\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/inherit.dir/inherit/inherit.cpp.obj -MF CMakeFiles\inherit.dir\inherit\inherit.cpp.obj.d -o CMakeFiles\inherit.dir\inherit\inherit.cpp.obj -c "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\inherit\inherit.cpp"

CMakeFiles/inherit.dir/inherit/inherit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inherit.dir/inherit/inherit.cpp.i"
	D:\IDE\Clion\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\inherit\inherit.cpp" > CMakeFiles\inherit.dir\inherit\inherit.cpp.i

CMakeFiles/inherit.dir/inherit/inherit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inherit.dir/inherit/inherit.cpp.s"
	D:\IDE\Clion\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\inherit\inherit.cpp" -o CMakeFiles\inherit.dir\inherit\inherit.cpp.s

# Object files for target inherit
inherit_OBJECTS = \
"CMakeFiles/inherit.dir/inherit/inherit.cpp.obj"

# External object files for target inherit
inherit_EXTERNAL_OBJECTS =

inherit.exe: CMakeFiles/inherit.dir/inherit/inherit.cpp.obj
inherit.exe: CMakeFiles/inherit.dir/build.make
inherit.exe: CMakeFiles/inherit.dir/linklibs.rsp
inherit.exe: CMakeFiles/inherit.dir/objects1.rsp
inherit.exe: CMakeFiles/inherit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable inherit.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\inherit.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inherit.dir/build: inherit.exe
.PHONY : CMakeFiles/inherit.dir/build

CMakeFiles/inherit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\inherit.dir\cmake_clean.cmake
.PHONY : CMakeFiles/inherit.dir/clean

CMakeFiles/inherit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice" "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice" "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug" "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug" "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug\CMakeFiles\inherit.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/inherit.dir/depend
