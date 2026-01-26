/*
   dlfcn-win32-mingw - POSIX dlfcn library implementation for Windows (Win32) with MinGW.

   Copyright (C) 2026 Roman Kravchenko
   Based on dlfcn-win32 by dlfcn-win32 (https://github.com/dlfcn-win32/dlfcn-win32).
   Original dlfcn from GNU C Library.

   SPDX-License-Identifier: MIT
*/

#ifndef DLFCN_H
#define DLFCN_H

#ifdef __cplusplus
   extern "C"
   {
#endif

#define RTLD_NOW 0 // Relocations are performed when the object is loaded.

// Relocations are performed at an implementation-defined time.
// Windows API does not support lazy symbol resolving (when first reference
// to a given symbol occurs). So RTLD_LAZY implementation is same as RTLD_NOW.
#define RTLD_LAZY RTLD_NOW

#define RTLD_GLOBAL (1 << 1) // All symbols are available for relocation processing of other modules.
#define RTLD_LOCAL (1 << 2) // All symbols are not made available for relocation processing by other modules.

// These two were added in The Open Group Base Specifications Issue 6.
// Note: All other RTLD_* flags in any dlfcn.h are not standard compliant.
#define RTLD_DEFAULT ((void *)0) // The symbol lookup happens in the normal global scope.
#define RTLD_NEXT ((void *)-1) // Specifies the next object after this one that defines name.

struct dl_info // Structure filled in by dladdr()
{
   const char *dli_fname;  // Filename of defining object (thread unsafe and reused on every call to dladdr)
   void *dli_fbase;  // Load address of that object
   const char *dli_sname;  // Name of nearest lower symbol
   void *dli_saddr;  // Exact value of nearest symbol
} typedef Dl_info;

void *dlopen(const char *file, int mode); // Open a symbol table handle.
int dlclose(void *handle); // Close a symbol table handle.
void *dlsym(void *handle, const char *name); // Get the address of a symbol from a symbol table handle.
char *dlerror(void); // Get diagnostic information.
int dladdr(const void *addr, Dl_info *info); // Translate address to symbolic information (no POSIX standard)

#ifdef __cplusplus
   }
#endif

#endif
