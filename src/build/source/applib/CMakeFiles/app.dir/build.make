# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = E:/CppSoft/CMake/bin/cmake.exe

# The command to remove a file.
RM = E:/CppSoft/CMake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:/CppProject/TinyOs/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:/CppProject/TinyOs/src/build

# Include any dependencies generated for this target.
include source/applib/CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/applib/CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include source/applib/CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include source/applib/CMakeFiles/app.dir/flags.make

source/applib/CMakeFiles/app.dir/codegen:
.PHONY : source/applib/CMakeFiles/app.dir/codegen

source/applib/CMakeFiles/app.dir/crt0.S.obj: source/applib/CMakeFiles/app.dir/flags.make
source/applib/CMakeFiles/app.dir/crt0.S.obj: source/applib/CMakeFiles/app.dir/includes_ASM.rsp
source/applib/CMakeFiles/app.dir/crt0.S.obj: E:/CppProject/TinyOs/src/source/applib/crt0.S
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:/CppProject/TinyOs/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ASM object source/applib/CMakeFiles/app.dir/crt0.S.obj"
	cd E:/CppProject/TinyOs/src/build/source/applib && E:/CppSoft/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/app.dir/crt0.S.obj -c E:/CppProject/TinyOs/src/source/applib/crt0.S

source/applib/CMakeFiles/app.dir/crt0.S.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing ASM source to CMakeFiles/app.dir/crt0.S.i"
	cd E:/CppProject/TinyOs/src/build/source/applib && E:/CppSoft/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E E:/CppProject/TinyOs/src/source/applib/crt0.S > CMakeFiles/app.dir/crt0.S.i

source/applib/CMakeFiles/app.dir/crt0.S.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling ASM source to assembly CMakeFiles/app.dir/crt0.S.s"
	cd E:/CppProject/TinyOs/src/build/source/applib && E:/CppSoft/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S E:/CppProject/TinyOs/src/source/applib/crt0.S -o CMakeFiles/app.dir/crt0.S.s

source/applib/CMakeFiles/app.dir/cstart.c.obj: source/applib/CMakeFiles/app.dir/flags.make
source/applib/CMakeFiles/app.dir/cstart.c.obj: source/applib/CMakeFiles/app.dir/includes_C.rsp
source/applib/CMakeFiles/app.dir/cstart.c.obj: E:/CppProject/TinyOs/src/source/applib/cstart.c
source/applib/CMakeFiles/app.dir/cstart.c.obj: source/applib/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:/CppProject/TinyOs/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object source/applib/CMakeFiles/app.dir/cstart.c.obj"
	cd E:/CppProject/TinyOs/src/build/source/applib && E:/CppSoft/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/applib/CMakeFiles/app.dir/cstart.c.obj -MF CMakeFiles/app.dir/cstart.c.obj.d -o CMakeFiles/app.dir/cstart.c.obj -c E:/CppProject/TinyOs/src/source/applib/cstart.c

source/applib/CMakeFiles/app.dir/cstart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/app.dir/cstart.c.i"
	cd E:/CppProject/TinyOs/src/build/source/applib && E:/CppSoft/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:/CppProject/TinyOs/src/source/applib/cstart.c > CMakeFiles/app.dir/cstart.c.i

source/applib/CMakeFiles/app.dir/cstart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/app.dir/cstart.c.s"
	cd E:/CppProject/TinyOs/src/build/source/applib && E:/CppSoft/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:/CppProject/TinyOs/src/source/applib/cstart.c -o CMakeFiles/app.dir/cstart.c.s

source/applib/CMakeFiles/app.dir/lib_syscall.c.obj: source/applib/CMakeFiles/app.dir/flags.make
source/applib/CMakeFiles/app.dir/lib_syscall.c.obj: source/applib/CMakeFiles/app.dir/includes_C.rsp
source/applib/CMakeFiles/app.dir/lib_syscall.c.obj: E:/CppProject/TinyOs/src/source/applib/lib_syscall.c
source/applib/CMakeFiles/app.dir/lib_syscall.c.obj: source/applib/CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:/CppProject/TinyOs/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object source/applib/CMakeFiles/app.dir/lib_syscall.c.obj"
	cd E:/CppProject/TinyOs/src/build/source/applib && E:/CppSoft/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT source/applib/CMakeFiles/app.dir/lib_syscall.c.obj -MF CMakeFiles/app.dir/lib_syscall.c.obj.d -o CMakeFiles/app.dir/lib_syscall.c.obj -c E:/CppProject/TinyOs/src/source/applib/lib_syscall.c

source/applib/CMakeFiles/app.dir/lib_syscall.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/app.dir/lib_syscall.c.i"
	cd E:/CppProject/TinyOs/src/build/source/applib && E:/CppSoft/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:/CppProject/TinyOs/src/source/applib/lib_syscall.c > CMakeFiles/app.dir/lib_syscall.c.i

source/applib/CMakeFiles/app.dir/lib_syscall.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/app.dir/lib_syscall.c.s"
	cd E:/CppProject/TinyOs/src/build/source/applib && E:/CppSoft/x86_64-elf-tools-windows/bin/x86_64-elf-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:/CppProject/TinyOs/src/source/applib/lib_syscall.c -o CMakeFiles/app.dir/lib_syscall.c.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/crt0.S.obj" \
"CMakeFiles/app.dir/cstart.c.obj" \
"CMakeFiles/app.dir/lib_syscall.c.obj"

# External object files for target app
app_EXTERNAL_OBJECTS =

source/applib/libapp.a: source/applib/CMakeFiles/app.dir/crt0.S.obj
source/applib/libapp.a: source/applib/CMakeFiles/app.dir/cstart.c.obj
source/applib/libapp.a: source/applib/CMakeFiles/app.dir/lib_syscall.c.obj
source/applib/libapp.a: source/applib/CMakeFiles/app.dir/build.make
source/applib/libapp.a: source/applib/CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:/CppProject/TinyOs/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libapp.a"
	cd E:/CppProject/TinyOs/src/build/source/applib && $(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean_target.cmake
	cd E:/CppProject/TinyOs/src/build/source/applib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)
	cd E:/CppProject/TinyOs/src/build/source/applib && x86_64-elf-objdump -x -d -S -m i386 E:/CppProject/TinyOs/src/build/source/applib/libapp.a > app_dis.txt
	cd E:/CppProject/TinyOs/src/build/source/applib && x86_64-elf-readelf -a E:/CppProject/TinyOs/src/build/source/applib/libapp.a > app_elf.txt

# Rule to build all files generated by this target.
source/applib/CMakeFiles/app.dir/build: source/applib/libapp.a
.PHONY : source/applib/CMakeFiles/app.dir/build

source/applib/CMakeFiles/app.dir/clean:
	cd E:/CppProject/TinyOs/src/build/source/applib && $(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : source/applib/CMakeFiles/app.dir/clean

source/applib/CMakeFiles/app.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" E:/CppProject/TinyOs/src E:/CppProject/TinyOs/src/source/applib E:/CppProject/TinyOs/src/build E:/CppProject/TinyOs/src/build/source/applib E:/CppProject/TinyOs/src/build/source/applib/CMakeFiles/app.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : source/applib/CMakeFiles/app.dir/depend

