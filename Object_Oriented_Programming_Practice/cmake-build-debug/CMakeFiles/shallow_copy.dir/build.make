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
include CMakeFiles/shallow_copy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/shallow_copy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/shallow_copy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shallow_copy.dir/flags.make

CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.obj: CMakeFiles/shallow_copy.dir/flags.make
CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.obj: ../deepshallow_copy/Person.cpp
CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.obj: CMakeFiles/shallow_copy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.obj"
	D:\IDE\Clion\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.obj -MF CMakeFiles\shallow_copy.dir\deepshallow_copy\Person.cpp.obj.d -o CMakeFiles\shallow_copy.dir\deepshallow_copy\Person.cpp.obj -c "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\deepshallow_copy\Person.cpp"

CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.i"
	D:\IDE\Clion\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\deepshallow_copy\Person.cpp" > CMakeFiles\shallow_copy.dir\deepshallow_copy\Person.cpp.i

CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.s"
	D:\IDE\Clion\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\deepshallow_copy\Person.cpp" -o CMakeFiles\shallow_copy.dir\deepshallow_copy\Person.cpp.s

# Object files for target shallow_copy
shallow_copy_OBJECTS = \
"CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.obj"

# External object files for target shallow_copy
shallow_copy_EXTERNAL_OBJECTS =

shallow_copy.exe: CMakeFiles/shallow_copy.dir/deepshallow_copy/Person.cpp.obj
shallow_copy.exe: CMakeFiles/shallow_copy.dir/build.make
shallow_copy.exe: CMakeFiles/shallow_copy.dir/linklibs.rsp
shallow_copy.exe: CMakeFiles/shallow_copy.dir/objects1.rsp
shallow_copy.exe: CMakeFiles/shallow_copy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable shallow_copy.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\shallow_copy.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shallow_copy.dir/build: shallow_copy.exe
.PHONY : CMakeFiles/shallow_copy.dir/build

CMakeFiles/shallow_copy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\shallow_copy.dir\cmake_clean.cmake
.PHONY : CMakeFiles/shallow_copy.dir/clean

CMakeFiles/shallow_copy.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice" "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice" "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug" "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug" "D:\Code&Algorithm\Cpp\Object_Oriented_Programming_Practice\cmake-build-debug\CMakeFiles\shallow_copy.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/shallow_copy.dir/depend

