# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Project\Cpp_\Remote-Connection-Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio

# Utility rule file for Window_autogen.

# Include any custom commands dependencies for this target.
include Sources\Window\CMakeFiles\Window_autogen.dir\compiler_depend.make

# Include the progress variables for this target.
include Sources\Window\CMakeFiles\Window_autogen.dir\progress.make

Sources\Window\CMakeFiles\Window_autogen: Sources\Window\Window_autogen\timestamp
	cd D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio\Sources\Window
	cd D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio

Sources\Window\Window_autogen\timestamp: C:\Qt\6.4.3\msvc2019_64\.\bin\moc.exe
Sources\Window\Window_autogen\timestamp: C:\Qt\6.4.3\msvc2019_64\.\bin\uic.exe
Sources\Window\Window_autogen\timestamp: Sources\Window\CMakeFiles\Window_autogen.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target Window"
	cd D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio\Sources\Window
	echo >nul && "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E cmake_autogen D:/Project/Cpp_/Remote-Connection-Client/cmake-build-debug-visual-studio/Sources/Window/CMakeFiles/Window_autogen.dir/AutogenInfo.json Debug
	echo >nul && "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E touch D:/Project/Cpp_/Remote-Connection-Client/cmake-build-debug-visual-studio/Sources/Window/Window_autogen/timestamp
	cd D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio

Window_autogen: Sources\Window\CMakeFiles\Window_autogen
Window_autogen: Sources\Window\Window_autogen\timestamp
Window_autogen: Sources\Window\CMakeFiles\Window_autogen.dir\build.make
.PHONY : Window_autogen

# Rule to build all files generated by this target.
Sources\Window\CMakeFiles\Window_autogen.dir\build: Window_autogen
.PHONY : Sources\Window\CMakeFiles\Window_autogen.dir\build

Sources\Window\CMakeFiles\Window_autogen.dir\clean:
	cd D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio\Sources\Window
	$(CMAKE_COMMAND) -P CMakeFiles\Window_autogen.dir\cmake_clean.cmake
	cd D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio
.PHONY : Sources\Window\CMakeFiles\Window_autogen.dir\clean

Sources\Window\CMakeFiles\Window_autogen.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Project\Cpp_\Remote-Connection-Client D:\Project\Cpp_\Remote-Connection-Client\Sources\Window D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio\Sources\Window D:\Project\Cpp_\Remote-Connection-Client\cmake-build-debug-visual-studio\Sources\Window\CMakeFiles\Window_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : Sources\Window\CMakeFiles\Window_autogen.dir\depend

