# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProject\cplusplus_memory_manager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProject\cplusplus_memory_manager\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cplusplus_memory_manager.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cplusplus_memory_manager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cplusplus_memory_manager.dir/flags.make

CMakeFiles/cplusplus_memory_manager.dir/main.cpp.obj: CMakeFiles/cplusplus_memory_manager.dir/flags.make
CMakeFiles/cplusplus_memory_manager.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProject\cplusplus_memory_manager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cplusplus_memory_manager.dir/main.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cplusplus_memory_manager.dir\main.cpp.obj -c D:\CLionProject\cplusplus_memory_manager\main.cpp

CMakeFiles/cplusplus_memory_manager.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cplusplus_memory_manager.dir/main.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProject\cplusplus_memory_manager\main.cpp > CMakeFiles\cplusplus_memory_manager.dir\main.cpp.i

CMakeFiles/cplusplus_memory_manager.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cplusplus_memory_manager.dir/main.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProject\cplusplus_memory_manager\main.cpp -o CMakeFiles\cplusplus_memory_manager.dir\main.cpp.s

CMakeFiles/cplusplus_memory_manager.dir/perClassAllocator.cpp.obj: CMakeFiles/cplusplus_memory_manager.dir/flags.make
CMakeFiles/cplusplus_memory_manager.dir/perClassAllocator.cpp.obj: ../perClassAllocator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProject\cplusplus_memory_manager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cplusplus_memory_manager.dir/perClassAllocator.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cplusplus_memory_manager.dir\perClassAllocator.cpp.obj -c D:\CLionProject\cplusplus_memory_manager\perClassAllocator.cpp

CMakeFiles/cplusplus_memory_manager.dir/perClassAllocator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cplusplus_memory_manager.dir/perClassAllocator.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProject\cplusplus_memory_manager\perClassAllocator.cpp > CMakeFiles\cplusplus_memory_manager.dir\perClassAllocator.cpp.i

CMakeFiles/cplusplus_memory_manager.dir/perClassAllocator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cplusplus_memory_manager.dir/perClassAllocator.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProject\cplusplus_memory_manager\perClassAllocator.cpp -o CMakeFiles\cplusplus_memory_manager.dir\perClassAllocator.cpp.s

# Object files for target cplusplus_memory_manager
cplusplus_memory_manager_OBJECTS = \
"CMakeFiles/cplusplus_memory_manager.dir/main.cpp.obj" \
"CMakeFiles/cplusplus_memory_manager.dir/perClassAllocator.cpp.obj"

# External object files for target cplusplus_memory_manager
cplusplus_memory_manager_EXTERNAL_OBJECTS =

cplusplus_memory_manager.exe: CMakeFiles/cplusplus_memory_manager.dir/main.cpp.obj
cplusplus_memory_manager.exe: CMakeFiles/cplusplus_memory_manager.dir/perClassAllocator.cpp.obj
cplusplus_memory_manager.exe: CMakeFiles/cplusplus_memory_manager.dir/build.make
cplusplus_memory_manager.exe: CMakeFiles/cplusplus_memory_manager.dir/linklibs.rsp
cplusplus_memory_manager.exe: CMakeFiles/cplusplus_memory_manager.dir/objects1.rsp
cplusplus_memory_manager.exe: CMakeFiles/cplusplus_memory_manager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProject\cplusplus_memory_manager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cplusplus_memory_manager.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cplusplus_memory_manager.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cplusplus_memory_manager.dir/build: cplusplus_memory_manager.exe

.PHONY : CMakeFiles/cplusplus_memory_manager.dir/build

CMakeFiles/cplusplus_memory_manager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cplusplus_memory_manager.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cplusplus_memory_manager.dir/clean

CMakeFiles/cplusplus_memory_manager.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProject\cplusplus_memory_manager D:\CLionProject\cplusplus_memory_manager D:\CLionProject\cplusplus_memory_manager\cmake-build-debug D:\CLionProject\cplusplus_memory_manager\cmake-build-debug D:\CLionProject\cplusplus_memory_manager\cmake-build-debug\CMakeFiles\cplusplus_memory_manager.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cplusplus_memory_manager.dir/depend

