# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/sohayla/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sohayla/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sohayla/CLionProjects/HTTP_Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HTTP_Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HTTP_Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HTTP_Client.dir/flags.make

CMakeFiles/HTTP_Client.dir/main.cpp.o: CMakeFiles/HTTP_Client.dir/flags.make
CMakeFiles/HTTP_Client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HTTP_Client.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HTTP_Client.dir/main.cpp.o -c /home/sohayla/CLionProjects/HTTP_Client/main.cpp

CMakeFiles/HTTP_Client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HTTP_Client.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sohayla/CLionProjects/HTTP_Client/main.cpp > CMakeFiles/HTTP_Client.dir/main.cpp.i

CMakeFiles/HTTP_Client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HTTP_Client.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sohayla/CLionProjects/HTTP_Client/main.cpp -o CMakeFiles/HTTP_Client.dir/main.cpp.s

CMakeFiles/HTTP_Client.dir/Client.cpp.o: CMakeFiles/HTTP_Client.dir/flags.make
CMakeFiles/HTTP_Client.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HTTP_Client.dir/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HTTP_Client.dir/Client.cpp.o -c /home/sohayla/CLionProjects/HTTP_Client/Client.cpp

CMakeFiles/HTTP_Client.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HTTP_Client.dir/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sohayla/CLionProjects/HTTP_Client/Client.cpp > CMakeFiles/HTTP_Client.dir/Client.cpp.i

CMakeFiles/HTTP_Client.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HTTP_Client.dir/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sohayla/CLionProjects/HTTP_Client/Client.cpp -o CMakeFiles/HTTP_Client.dir/Client.cpp.s

CMakeFiles/HTTP_Client.dir/FileSystem.cpp.o: CMakeFiles/HTTP_Client.dir/flags.make
CMakeFiles/HTTP_Client.dir/FileSystem.cpp.o: ../FileSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/HTTP_Client.dir/FileSystem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HTTP_Client.dir/FileSystem.cpp.o -c /home/sohayla/CLionProjects/HTTP_Client/FileSystem.cpp

CMakeFiles/HTTP_Client.dir/FileSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HTTP_Client.dir/FileSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sohayla/CLionProjects/HTTP_Client/FileSystem.cpp > CMakeFiles/HTTP_Client.dir/FileSystem.cpp.i

CMakeFiles/HTTP_Client.dir/FileSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HTTP_Client.dir/FileSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sohayla/CLionProjects/HTTP_Client/FileSystem.cpp -o CMakeFiles/HTTP_Client.dir/FileSystem.cpp.s

CMakeFiles/HTTP_Client.dir/Structs.cpp.o: CMakeFiles/HTTP_Client.dir/flags.make
CMakeFiles/HTTP_Client.dir/Structs.cpp.o: ../Structs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/HTTP_Client.dir/Structs.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HTTP_Client.dir/Structs.cpp.o -c /home/sohayla/CLionProjects/HTTP_Client/Structs.cpp

CMakeFiles/HTTP_Client.dir/Structs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HTTP_Client.dir/Structs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sohayla/CLionProjects/HTTP_Client/Structs.cpp > CMakeFiles/HTTP_Client.dir/Structs.cpp.i

CMakeFiles/HTTP_Client.dir/Structs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HTTP_Client.dir/Structs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sohayla/CLionProjects/HTTP_Client/Structs.cpp -o CMakeFiles/HTTP_Client.dir/Structs.cpp.s

CMakeFiles/HTTP_Client.dir/Actions.cpp.o: CMakeFiles/HTTP_Client.dir/flags.make
CMakeFiles/HTTP_Client.dir/Actions.cpp.o: ../Actions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/HTTP_Client.dir/Actions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HTTP_Client.dir/Actions.cpp.o -c /home/sohayla/CLionProjects/HTTP_Client/Actions.cpp

CMakeFiles/HTTP_Client.dir/Actions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HTTP_Client.dir/Actions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sohayla/CLionProjects/HTTP_Client/Actions.cpp > CMakeFiles/HTTP_Client.dir/Actions.cpp.i

CMakeFiles/HTTP_Client.dir/Actions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HTTP_Client.dir/Actions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sohayla/CLionProjects/HTTP_Client/Actions.cpp -o CMakeFiles/HTTP_Client.dir/Actions.cpp.s

CMakeFiles/HTTP_Client.dir/Parser.cpp.o: CMakeFiles/HTTP_Client.dir/flags.make
CMakeFiles/HTTP_Client.dir/Parser.cpp.o: ../Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/HTTP_Client.dir/Parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HTTP_Client.dir/Parser.cpp.o -c /home/sohayla/CLionProjects/HTTP_Client/Parser.cpp

CMakeFiles/HTTP_Client.dir/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HTTP_Client.dir/Parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sohayla/CLionProjects/HTTP_Client/Parser.cpp > CMakeFiles/HTTP_Client.dir/Parser.cpp.i

CMakeFiles/HTTP_Client.dir/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HTTP_Client.dir/Parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sohayla/CLionProjects/HTTP_Client/Parser.cpp -o CMakeFiles/HTTP_Client.dir/Parser.cpp.s

CMakeFiles/HTTP_Client.dir/Request.cpp.o: CMakeFiles/HTTP_Client.dir/flags.make
CMakeFiles/HTTP_Client.dir/Request.cpp.o: ../Request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/HTTP_Client.dir/Request.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HTTP_Client.dir/Request.cpp.o -c /home/sohayla/CLionProjects/HTTP_Client/Request.cpp

CMakeFiles/HTTP_Client.dir/Request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HTTP_Client.dir/Request.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sohayla/CLionProjects/HTTP_Client/Request.cpp > CMakeFiles/HTTP_Client.dir/Request.cpp.i

CMakeFiles/HTTP_Client.dir/Request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HTTP_Client.dir/Request.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sohayla/CLionProjects/HTTP_Client/Request.cpp -o CMakeFiles/HTTP_Client.dir/Request.cpp.s

# Object files for target HTTP_Client
HTTP_Client_OBJECTS = \
"CMakeFiles/HTTP_Client.dir/main.cpp.o" \
"CMakeFiles/HTTP_Client.dir/Client.cpp.o" \
"CMakeFiles/HTTP_Client.dir/FileSystem.cpp.o" \
"CMakeFiles/HTTP_Client.dir/Structs.cpp.o" \
"CMakeFiles/HTTP_Client.dir/Actions.cpp.o" \
"CMakeFiles/HTTP_Client.dir/Parser.cpp.o" \
"CMakeFiles/HTTP_Client.dir/Request.cpp.o"

# External object files for target HTTP_Client
HTTP_Client_EXTERNAL_OBJECTS =

HTTP_Client: CMakeFiles/HTTP_Client.dir/main.cpp.o
HTTP_Client: CMakeFiles/HTTP_Client.dir/Client.cpp.o
HTTP_Client: CMakeFiles/HTTP_Client.dir/FileSystem.cpp.o
HTTP_Client: CMakeFiles/HTTP_Client.dir/Structs.cpp.o
HTTP_Client: CMakeFiles/HTTP_Client.dir/Actions.cpp.o
HTTP_Client: CMakeFiles/HTTP_Client.dir/Parser.cpp.o
HTTP_Client: CMakeFiles/HTTP_Client.dir/Request.cpp.o
HTTP_Client: CMakeFiles/HTTP_Client.dir/build.make
HTTP_Client: CMakeFiles/HTTP_Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable HTTP_Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HTTP_Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HTTP_Client.dir/build: HTTP_Client

.PHONY : CMakeFiles/HTTP_Client.dir/build

CMakeFiles/HTTP_Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HTTP_Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HTTP_Client.dir/clean

CMakeFiles/HTTP_Client.dir/depend:
	cd /home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sohayla/CLionProjects/HTTP_Client /home/sohayla/CLionProjects/HTTP_Client /home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug /home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug /home/sohayla/CLionProjects/HTTP_Client/cmake-build-debug/CMakeFiles/HTTP_Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HTTP_Client.dir/depend

