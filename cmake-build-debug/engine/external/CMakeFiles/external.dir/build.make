# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/edge/clion-2019.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/edge/clion-2019.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/edge/BangDesktop/project/Bang

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edge/BangDesktop/project/Bang/cmake-build-debug

# Include any dependencies generated for this target.
include engine/external/CMakeFiles/external.dir/depend.make

# Include the progress variables for this target.
include engine/external/CMakeFiles/external.dir/progress.make

# Include the compile flags for this target's objects.
include engine/external/CMakeFiles/external.dir/flags.make

engine/external/CMakeFiles/external.dir/empty.cpp.o: engine/external/CMakeFiles/external.dir/flags.make
engine/external/CMakeFiles/external.dir/empty.cpp.o: ../cocos2d/external/empty.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edge/BangDesktop/project/Bang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object engine/external/CMakeFiles/external.dir/empty.cpp.o"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/external.dir/empty.cpp.o -c /home/edge/BangDesktop/project/Bang/cocos2d/external/empty.cpp

engine/external/CMakeFiles/external.dir/empty.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/external.dir/empty.cpp.i"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edge/BangDesktop/project/Bang/cocos2d/external/empty.cpp > CMakeFiles/external.dir/empty.cpp.i

engine/external/CMakeFiles/external.dir/empty.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/external.dir/empty.cpp.s"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edge/BangDesktop/project/Bang/cocos2d/external/empty.cpp -o CMakeFiles/external.dir/empty.cpp.s

# Object files for target external
external_OBJECTS = \
"CMakeFiles/external.dir/empty.cpp.o"

# External object files for target external
external_EXTERNAL_OBJECTS =

lib/libexternal.a: engine/external/CMakeFiles/external.dir/empty.cpp.o
lib/libexternal.a: engine/external/CMakeFiles/external.dir/build.make
lib/libexternal.a: engine/external/CMakeFiles/external.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/edge/BangDesktop/project/Bang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libexternal.a"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external && $(CMAKE_COMMAND) -P CMakeFiles/external.dir/cmake_clean_target.cmake
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/external.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/external/CMakeFiles/external.dir/build: lib/libexternal.a

.PHONY : engine/external/CMakeFiles/external.dir/build

engine/external/CMakeFiles/external.dir/clean:
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external && $(CMAKE_COMMAND) -P CMakeFiles/external.dir/cmake_clean.cmake
.PHONY : engine/external/CMakeFiles/external.dir/clean

engine/external/CMakeFiles/external.dir/depend:
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edge/BangDesktop/project/Bang /home/edge/BangDesktop/project/Bang/cocos2d/external /home/edge/BangDesktop/project/Bang/cmake-build-debug /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/CMakeFiles/external.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/external/CMakeFiles/external.dir/depend

