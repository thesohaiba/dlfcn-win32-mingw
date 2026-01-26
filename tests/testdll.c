/*
    dlfcn-win32-mingw - POSIX dlfcn library implementation for Windows (Win32) with MinGW.

	Copyright (C) 2026 Roman Kravchenko
	Based on dlfcn-win32 by dlfcn-win32 (https://github.com/dlfcn-win32/dlfcn-win32).
	Original dlfcn from GNU C Library.

	SPDX-License-Identifier: MIT
*/

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <stdio.h>

int function2( void )
{
    printf( "Hello, world! from original library\n" );
    return 0;
}

int function( void )
{
    printf( "Hello, world!\n" );
    return 0;
}
