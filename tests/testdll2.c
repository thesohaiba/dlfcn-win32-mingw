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

#include "..\dlfcn.h"

int function2( void )
{
    char *error;
    int (*function2_orig)(void);
    printf( "Hello, world! from wrapper library\n" );
    *(void **) (&function2_orig) = dlsym( RTLD_NEXT, "function2" );
    if (!function2_orig)
    {
        error = dlerror( );
        printf( "ERROR\tCould not get symbol from RTLD_NEXT handle: %s\n",
                error ? error : "" );
        return 1;
    }
    if (function2_orig() != 0)
    {
        printf( "ERROR\tOriginal function from RTLD_NEXT handle did not return correct value\n" );
        return 1;
    }
    return 2;
}
