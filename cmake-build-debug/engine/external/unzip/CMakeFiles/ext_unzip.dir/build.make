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
include engine/external/unzip/CMakeFiles/ext_unzip.dir/depend.make

# Include the progress variables for this target.
include engine/external/unzip/CMakeFiles/ext_unzip.dir/progress.make

# Include the compile flags for this target's objects.
include engine/external/unzip/CMakeFiles/ext_unzip.dir/flags.make

engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi.cpp.o: engine/external/unzip/CMakeFiles/ext_unzip.dir/flags.make
engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi.cpp.o: ../cocos2d/external/unzip/ioapi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edge/BangDesktop/project/Bang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi.cpp.o"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ext_unzip.dir/ioapi.cpp.o -c /home/edge/BangDesktop/project/Bang/cocos2d/external/unzip/ioapi.cpp

engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ext_unzip.dir/ioapi.cpp.i"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edge/BangDesktop/project/Bang/cocos2d/external/unzip/ioapi.cpp > CMakeFiles/ext_unzip.dir/ioapi.cpp.i

engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ext_unzip.dir/ioapi.cpp.s"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edge/BangDesktop/project/Bang/cocos2d/external/unzip/ioapi.cpp -o CMakeFiles/ext_unzip.dir/ioapi.cpp.s

engine/external/unzip/CMakeFiles/ext_unzip.dir/unzip.cpp.o: engine/external/unzip/CMakeFiles/ext_unzip.dir/flags.make
engine/external/unzip/CMakeFiles/ext_unzip.dir/unzip.cpp.o: ../cocos2d/external/unzip/unzip.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edge/BangDesktop/project/Bang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object engine/external/unzip/CMakeFiles/ext_unzip.dir/unzip.cpp.o"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ext_unzip.dir/unzip.cpp.o -c /home/edge/BangDesktop/project/Bang/cocos2d/external/unzip/unzip.cpp

engine/external/unzip/CMakeFiles/ext_unzip.dir/unzip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ext_unzip.dir/unzip.cpp.i"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edge/BangDesktop/project/Bang/cocos2d/external/unzip/unzip.cpp > CMakeFiles/ext_unzip.dir/unzip.cpp.i

engine/external/unzip/CMakeFiles/ext_unzip.dir/unzip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ext_unzip.dir/unzip.cpp.s"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edge/BangDesktop/project/Bang/cocos2d/external/unzip/unzip.cpp -o CMakeFiles/ext_unzip.dir/unzip.cpp.s

engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.o: engine/external/unzip/CMakeFiles/ext_unzip.dir/flags.make
engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.o: ../cocos2d/external/unzip/ioapi_mem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edge/BangDesktop/project/Bang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.o"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.o -c /home/edge/BangDesktop/project/Bang/cocos2d/external/unzip/ioapi_mem.cpp

engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.i"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edge/BangDesktop/project/Bang/cocos2d/external/unzip/ioapi_mem.cpp > CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.i

engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.s"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edge/BangDesktop/project/Bang/cocos2d/external/unzip/ioapi_mem.cpp -o CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.s

# Object files for target ext_unzip
ext_unzip_OBJECTS = \
"CMakeFiles/ext_unzip.dir/ioapi.cpp.o" \
"CMakeFiles/ext_unzip.dir/unzip.cpp.o" \
"CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.o"

# External object files for target ext_unzip
ext_unzip_EXTERNAL_OBJECTS =

lib/libext_unzip.a: engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi.cpp.o
lib/libext_unzip.a: engine/external/unzip/CMakeFiles/ext_unzip.dir/unzip.cpp.o
lib/libext_unzip.a: engine/external/unzip/CMakeFiles/ext_unzip.dir/ioapi_mem.cpp.o
lib/libext_unzip.a: engine/external/unzip/CMakeFiles/ext_unzip.dir/build.make
lib/libext_unzip.a: engine/external/unzip/CMakeFiles/ext_unzip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/edge/BangDesktop/project/Bang/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../../lib/libext_unzip.a"
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && $(CMAKE_COMMAND) -P CMakeFiles/ext_unzip.dir/cmake_clean_target.cmake
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ext_unzip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/external/unzip/CMakeFiles/ext_unzip.dir/build: lib/libext_unzip.a

.PHONY : engine/external/unzip/CMakeFiles/ext_unzip.dir/build

engine/external/unzip/CMakeFiles/ext_unzip.dir/clean:
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip && $(CMAKE_COMMAND) -P CMakeFiles/ext_unzip.dir/cmake_clean.cmake
.PHONY : engine/external/unzip/CMakeFiles/ext_unzip.dir/clean

engine/external/unzip/CMakeFiles/ext_unzip.dir/depend:
	cd /home/edge/BangDesktop/project/Bang/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edge/BangDesktop/project/Bang /home/edge/BangDesktop/project/Bang/cocos2d/external/unzip /home/edge/BangDesktop/project/Bang/cmake-build-debug /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip /home/edge/BangDesktop/project/Bang/cmake-build-debug/engine/external/unzip/CMakeFiles/ext_unzip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/external/unzip/CMakeFiles/ext_unzip.dir/depend

