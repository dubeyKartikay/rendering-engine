# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kartikayd/learning-repos/OpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kartikayd/learning-repos/OpenGL/build

# Include any dependencies generated for this target.
include src/tests/CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/tests/CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include src/tests/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include src/tests/CMakeFiles/tests.dir/flags.make

src/tests/CMakeFiles/tests.dir/TestCamera3D.cpp.o: src/tests/CMakeFiles/tests.dir/flags.make
src/tests/CMakeFiles/tests.dir/TestCamera3D.cpp.o: /home/kartikayd/learning-repos/OpenGL/src/tests/TestCamera3D.cpp
src/tests/CMakeFiles/tests.dir/TestCamera3D.cpp.o: src/tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kartikayd/learning-repos/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/tests/CMakeFiles/tests.dir/TestCamera3D.cpp.o"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/tests/CMakeFiles/tests.dir/TestCamera3D.cpp.o -MF CMakeFiles/tests.dir/TestCamera3D.cpp.o.d -o CMakeFiles/tests.dir/TestCamera3D.cpp.o -c /home/kartikayd/learning-repos/OpenGL/src/tests/TestCamera3D.cpp

src/tests/CMakeFiles/tests.dir/TestCamera3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/TestCamera3D.cpp.i"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kartikayd/learning-repos/OpenGL/src/tests/TestCamera3D.cpp > CMakeFiles/tests.dir/TestCamera3D.cpp.i

src/tests/CMakeFiles/tests.dir/TestCamera3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/TestCamera3D.cpp.s"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kartikayd/learning-repos/OpenGL/src/tests/TestCamera3D.cpp -o CMakeFiles/tests.dir/TestCamera3D.cpp.s

src/tests/CMakeFiles/tests.dir/TestCube3D.cpp.o: src/tests/CMakeFiles/tests.dir/flags.make
src/tests/CMakeFiles/tests.dir/TestCube3D.cpp.o: /home/kartikayd/learning-repos/OpenGL/src/tests/TestCube3D.cpp
src/tests/CMakeFiles/tests.dir/TestCube3D.cpp.o: src/tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kartikayd/learning-repos/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/tests/CMakeFiles/tests.dir/TestCube3D.cpp.o"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/tests/CMakeFiles/tests.dir/TestCube3D.cpp.o -MF CMakeFiles/tests.dir/TestCube3D.cpp.o.d -o CMakeFiles/tests.dir/TestCube3D.cpp.o -c /home/kartikayd/learning-repos/OpenGL/src/tests/TestCube3D.cpp

src/tests/CMakeFiles/tests.dir/TestCube3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/TestCube3D.cpp.i"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kartikayd/learning-repos/OpenGL/src/tests/TestCube3D.cpp > CMakeFiles/tests.dir/TestCube3D.cpp.i

src/tests/CMakeFiles/tests.dir/TestCube3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/TestCube3D.cpp.s"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kartikayd/learning-repos/OpenGL/src/tests/TestCube3D.cpp -o CMakeFiles/tests.dir/TestCube3D.cpp.s

src/tests/CMakeFiles/tests.dir/TestFrame.cpp.o: src/tests/CMakeFiles/tests.dir/flags.make
src/tests/CMakeFiles/tests.dir/TestFrame.cpp.o: /home/kartikayd/learning-repos/OpenGL/src/tests/TestFrame.cpp
src/tests/CMakeFiles/tests.dir/TestFrame.cpp.o: src/tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kartikayd/learning-repos/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/tests/CMakeFiles/tests.dir/TestFrame.cpp.o"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/tests/CMakeFiles/tests.dir/TestFrame.cpp.o -MF CMakeFiles/tests.dir/TestFrame.cpp.o.d -o CMakeFiles/tests.dir/TestFrame.cpp.o -c /home/kartikayd/learning-repos/OpenGL/src/tests/TestFrame.cpp

src/tests/CMakeFiles/tests.dir/TestFrame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/TestFrame.cpp.i"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kartikayd/learning-repos/OpenGL/src/tests/TestFrame.cpp > CMakeFiles/tests.dir/TestFrame.cpp.i

src/tests/CMakeFiles/tests.dir/TestFrame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/TestFrame.cpp.s"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kartikayd/learning-repos/OpenGL/src/tests/TestFrame.cpp -o CMakeFiles/tests.dir/TestFrame.cpp.s

src/tests/CMakeFiles/tests.dir/TestLighting.cpp.o: src/tests/CMakeFiles/tests.dir/flags.make
src/tests/CMakeFiles/tests.dir/TestLighting.cpp.o: /home/kartikayd/learning-repos/OpenGL/src/tests/TestLighting.cpp
src/tests/CMakeFiles/tests.dir/TestLighting.cpp.o: src/tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kartikayd/learning-repos/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/tests/CMakeFiles/tests.dir/TestLighting.cpp.o"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/tests/CMakeFiles/tests.dir/TestLighting.cpp.o -MF CMakeFiles/tests.dir/TestLighting.cpp.o.d -o CMakeFiles/tests.dir/TestLighting.cpp.o -c /home/kartikayd/learning-repos/OpenGL/src/tests/TestLighting.cpp

src/tests/CMakeFiles/tests.dir/TestLighting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/TestLighting.cpp.i"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kartikayd/learning-repos/OpenGL/src/tests/TestLighting.cpp > CMakeFiles/tests.dir/TestLighting.cpp.i

src/tests/CMakeFiles/tests.dir/TestLighting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/TestLighting.cpp.s"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kartikayd/learning-repos/OpenGL/src/tests/TestLighting.cpp -o CMakeFiles/tests.dir/TestLighting.cpp.s

src/tests/CMakeFiles/tests.dir/TestModel3D.cpp.o: src/tests/CMakeFiles/tests.dir/flags.make
src/tests/CMakeFiles/tests.dir/TestModel3D.cpp.o: /home/kartikayd/learning-repos/OpenGL/src/tests/TestModel3D.cpp
src/tests/CMakeFiles/tests.dir/TestModel3D.cpp.o: src/tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kartikayd/learning-repos/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/tests/CMakeFiles/tests.dir/TestModel3D.cpp.o"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/tests/CMakeFiles/tests.dir/TestModel3D.cpp.o -MF CMakeFiles/tests.dir/TestModel3D.cpp.o.d -o CMakeFiles/tests.dir/TestModel3D.cpp.o -c /home/kartikayd/learning-repos/OpenGL/src/tests/TestModel3D.cpp

src/tests/CMakeFiles/tests.dir/TestModel3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/TestModel3D.cpp.i"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kartikayd/learning-repos/OpenGL/src/tests/TestModel3D.cpp > CMakeFiles/tests.dir/TestModel3D.cpp.i

src/tests/CMakeFiles/tests.dir/TestModel3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/TestModel3D.cpp.s"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kartikayd/learning-repos/OpenGL/src/tests/TestModel3D.cpp -o CMakeFiles/tests.dir/TestModel3D.cpp.s

src/tests/CMakeFiles/tests.dir/TestRect2D.cpp.o: src/tests/CMakeFiles/tests.dir/flags.make
src/tests/CMakeFiles/tests.dir/TestRect2D.cpp.o: /home/kartikayd/learning-repos/OpenGL/src/tests/TestRect2D.cpp
src/tests/CMakeFiles/tests.dir/TestRect2D.cpp.o: src/tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kartikayd/learning-repos/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/tests/CMakeFiles/tests.dir/TestRect2D.cpp.o"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/tests/CMakeFiles/tests.dir/TestRect2D.cpp.o -MF CMakeFiles/tests.dir/TestRect2D.cpp.o.d -o CMakeFiles/tests.dir/TestRect2D.cpp.o -c /home/kartikayd/learning-repos/OpenGL/src/tests/TestRect2D.cpp

src/tests/CMakeFiles/tests.dir/TestRect2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/TestRect2D.cpp.i"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kartikayd/learning-repos/OpenGL/src/tests/TestRect2D.cpp > CMakeFiles/tests.dir/TestRect2D.cpp.i

src/tests/CMakeFiles/tests.dir/TestRect2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/TestRect2D.cpp.s"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kartikayd/learning-repos/OpenGL/src/tests/TestRect2D.cpp -o CMakeFiles/tests.dir/TestRect2D.cpp.s

src/tests/CMakeFiles/tests.dir/TestTexture2D.cpp.o: src/tests/CMakeFiles/tests.dir/flags.make
src/tests/CMakeFiles/tests.dir/TestTexture2D.cpp.o: /home/kartikayd/learning-repos/OpenGL/src/tests/TestTexture2D.cpp
src/tests/CMakeFiles/tests.dir/TestTexture2D.cpp.o: src/tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kartikayd/learning-repos/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/tests/CMakeFiles/tests.dir/TestTexture2D.cpp.o"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/tests/CMakeFiles/tests.dir/TestTexture2D.cpp.o -MF CMakeFiles/tests.dir/TestTexture2D.cpp.o.d -o CMakeFiles/tests.dir/TestTexture2D.cpp.o -c /home/kartikayd/learning-repos/OpenGL/src/tests/TestTexture2D.cpp

src/tests/CMakeFiles/tests.dir/TestTexture2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/TestTexture2D.cpp.i"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kartikayd/learning-repos/OpenGL/src/tests/TestTexture2D.cpp > CMakeFiles/tests.dir/TestTexture2D.cpp.i

src/tests/CMakeFiles/tests.dir/TestTexture2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/TestTexture2D.cpp.s"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kartikayd/learning-repos/OpenGL/src/tests/TestTexture2D.cpp -o CMakeFiles/tests.dir/TestTexture2D.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/TestCamera3D.cpp.o" \
"CMakeFiles/tests.dir/TestCube3D.cpp.o" \
"CMakeFiles/tests.dir/TestFrame.cpp.o" \
"CMakeFiles/tests.dir/TestLighting.cpp.o" \
"CMakeFiles/tests.dir/TestModel3D.cpp.o" \
"CMakeFiles/tests.dir/TestRect2D.cpp.o" \
"CMakeFiles/tests.dir/TestTexture2D.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

src/tests/libtests.a: src/tests/CMakeFiles/tests.dir/TestCamera3D.cpp.o
src/tests/libtests.a: src/tests/CMakeFiles/tests.dir/TestCube3D.cpp.o
src/tests/libtests.a: src/tests/CMakeFiles/tests.dir/TestFrame.cpp.o
src/tests/libtests.a: src/tests/CMakeFiles/tests.dir/TestLighting.cpp.o
src/tests/libtests.a: src/tests/CMakeFiles/tests.dir/TestModel3D.cpp.o
src/tests/libtests.a: src/tests/CMakeFiles/tests.dir/TestRect2D.cpp.o
src/tests/libtests.a: src/tests/CMakeFiles/tests.dir/TestTexture2D.cpp.o
src/tests/libtests.a: src/tests/CMakeFiles/tests.dir/build.make
src/tests/libtests.a: src/tests/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kartikayd/learning-repos/OpenGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libtests.a"
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean_target.cmake
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/tests/CMakeFiles/tests.dir/build: src/tests/libtests.a
.PHONY : src/tests/CMakeFiles/tests.dir/build

src/tests/CMakeFiles/tests.dir/clean:
	cd /home/kartikayd/learning-repos/OpenGL/build/src/tests && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : src/tests/CMakeFiles/tests.dir/clean

src/tests/CMakeFiles/tests.dir/depend:
	cd /home/kartikayd/learning-repos/OpenGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kartikayd/learning-repos/OpenGL /home/kartikayd/learning-repos/OpenGL/src/tests /home/kartikayd/learning-repos/OpenGL/build /home/kartikayd/learning-repos/OpenGL/build/src/tests /home/kartikayd/learning-repos/OpenGL/build/src/tests/CMakeFiles/tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/tests/CMakeFiles/tests.dir/depend

