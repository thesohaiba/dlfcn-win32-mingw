@echo off

if exist ".\build\" goto skip_creating_build_folder
	echo Creating build directory...
	mkdir build
:skip_creating_build_folder

echo Building sources...
gcc -c ./dlfcn.c -o ./dlfcn.o
if not exist ".\dlfcn.o" goto end

echo Creating static library...
ar rcs ./build/libdlfcn.a ./dlfcn.o

echo Linking dynamic library...
gcc -fPIC -shared ./dlfcn.o -o ./build/dlfcn.dll

del .\dlfcn.o
echo Finished successfully.

:end