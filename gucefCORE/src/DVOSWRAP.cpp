/*
 *  gucefCORE: GUCEF module providing O/S abstraction and generic solutions
 *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef GUCEF_CORE_MACROS_H
#include "gucefCORE_macros.h"       /* build configuration */
#define GUCEFCORE_MACROS_H
#endif /* GUCEFCORE_MACROS_H ? */

#ifndef GUCEF_CORE_LOGGING_H
#include "gucefCORE_Logging.h"
#define GUCEF_CORE_LOGGING_H
#endif /* GUCEF_CORE_LOGGING_H ? */

#if ( GUCEF_PLATFORM == GUCEF_PLATFORM_MSWIN )

  /* Do not use WIN32_LEAN_AND_MEAN because it will remove timeBeginPeriod() etc. */
  #undef  WIN32_LEAN_AND_MEAN
  #include <windows.h>                /* Windows API */
  #undef min
  #undef max
  #define MAX_DIR_LENGTH MAX_PATH

#elif ( ( GUCEF_PLATFORM == GUCEF_PLATFORM_LINUX ) || ( GUCEF_PLATFORM == GUCEF_PLATFORM_ANDROID ) )

  #include <sys/times.h>
  #include <limits.h>                 /* Linux OS limits */
  #include <dlfcn.h>                  /* dynamic linking utilities */
  #define MAX_DIR_LENGTH PATH_MAX

#endif

#ifndef GUCEF_CORE_DVSTRUTILS_H
#include "dvstrutils.h"               /* needed for str to int */
#define GUCEF_CORE_DVSTRUTILS_H
#endif /* GUCEF_CORE_DVSTRUTILS_H ? */

#include "DVOSWRAP.h"               /* O/S Wrapping function prototypes*/

#ifndef GUCEF_CORE_GUCEF_ESSENTIALS_H
#include "gucef_essentials.h"
#define GUCEF_CORE_GUCEF_ESSENTIALS_H
#endif /* GUCEF_CORE_GUCEF_ESSENTIALS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifdef __cplusplus
namespace GUCEF {
namespace CORE {
#endif /* __cplusplus ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      IMPLEMENTATION                                                     //
//                                                                         //
//-------------------------------------------------------------------------*/

void*
LoadModuleDynamicly( const char* filename )
{
    char* fName = (char*) filename;
    const char* fileExt = Extract_File_Ext( filename );
    void* modulePtr = NULL;

    /*
     *  If no module extension was given we will add the O/S default
     */
    if ( fileExt == NULL )
    {
        UInt32 sLen = (UInt32) strlen( filename );
        fName = (char*) malloc( sLen + 7 );
        memcpy( fName, filename, sLen );

        #if ( GUCEF_PLATFORM == GUCEF_PLATFORM_MSWIN )
        memcpy( fName+sLen, ".dll\0", 5 );
        #elif ( ( GUCEF_PLATFORM == GUCEF_PLATFORM_LINUX ) || ( GUCEF_PLATFORM == GUCEF_PLATFORM_ANDROID ) )
        memcpy( fName+sLen, ".so\0", 4 );
        #elif ( GUCEF_PLATFORM == GUCEF_PLATFORM_APPLE )
        memcpy( fName+sLen, ".dylib\0", 7 );
        #endif
    }

    #if ( ( GUCEF_PLATFORM == GUCEF_PLATFORM_LINUX ) || ( GUCEF_PLATFORM == GUCEF_PLATFORM_ANDROID ) )

    modulePtr = (void*) dlopen( fName, RTLD_NOW );
    if ( NULL == modulePtr )
    {
        /*
         *  It is possible the load failed due to missing "lib" prefix on linux/android.
         *  Check for this and compensate as needed
         */
        char hasLibPrefix = 0;
        const char* fileOnly = Extract_Filename( fName );
        UInt32 sLength = strlen( fileOnly );
        //if ( sLength >= 3 )
        //{
        //    if ( 0 == memcmp( "lib", fileOnly, 3 ) )
        //    {
        //        hasLibPrefix = 1;
        //    }
        //}

        //if ( 0 == hasLibPrefix )
        {
            /*
             *  No previous "lib" prefix was found, we will add one and try to load again
             */
            UInt32 fNameLen = strlen( fName );
            char* newFilePath = (char*) malloc( fNameLen+3+1 );
            memcpy( newFilePath, fName, fNameLen-sLength );
            memcpy( newFilePath+(fNameLen-sLength), "lib", 3 );
            memcpy( newFilePath+(fNameLen-sLength)+3, fileOnly, sLength+1 );

            modulePtr = (void*) dlopen( newFilePath, RTLD_NOW );

            free( newFilePath );
        }
    }

    if ( NULL == modulePtr )
    {
        GUCEF_DEBUG_LOG( LOGLEVEL_NORMAL, "LoadModuleDynamicly() reports error: " + CString( dlerror() ) );
    }

    #elif ( GUCEF_PLATFORM == GUCEF_PLATFORM_MSWIN )

    modulePtr = (void*) LoadLibrary( fName );

    #endif

    if ( fileExt == NULL )
    {
        free( fName );
    }

    return modulePtr;
}

/*--------------------------------------------------------------------------*/

GUCEF_CORE_PUBLIC_C void*
GetModulePointer( const char* moduleName )
{
    // If no module name is passed we get the pointer to the main process module

    #if ( ( GUCEF_PLATFORM == GUCEF_PLATFORM_LINUX ) || ( GUCEF_PLATFORM == GUCEF_PLATFORM_ANDROID ) )

    // On linux the reference count is always incremented so we must decrement again right away to get
    // the same behaviour as the windows version
    void* modulePtr = (void*) dlopen( moduleName, RTLD_NOW );
    dlclose( modulePtr );
    return modulePtr;

    #elif ( GUCEF_PLATFORM == GUCEF_PLATFORM_MSWIN )

    return (void*) GetModuleHandleA( moduleName );

    #else
    #error Unsupported target platform
    #endif
}

/*--------------------------------------------------------------------------*/

void
UnloadModuleDynamicly( void *sohandle )
{
    if ( NULL == sohandle ) return;

    #if ( ( GUCEF_PLATFORM == GUCEF_PLATFORM_LINUX ) || ( GUCEF_PLATFORM == GUCEF_PLATFORM_ANDROID ) )

    dlclose( sohandle );

    #elif ( GUCEF_PLATFORM == GUCEF_PLATFORM_MSWIN )

    FreeLibrary( (HMODULE)sohandle );

    #else
    #error Unsupported target platform
    #endif
}

/*--------------------------------------------------------------------------*/

TAnyPointer
GetFunctionAddress( void *sohandle           ,
                    const char* functionname ,
                    UInt32 parambytes        )
{
    /*
     *      Calling Convention      Internal*       MSVC DLL (w/ DEF)       MSVC DLL (dllexport)  	DMC DLL         MinGW DLL       BCC DLL
     *      __stdcall               _Function@n  	Function                _Function@n             _Function@n     Function@n      Function
     *      __cdecl                 _Function       Function                Function                Function        Function        _Function
     */
    TAnyPointer fptr;
    if ( NULL == sohandle )
    {
        fptr.funcPtr = 0;
        return fptr;
    }

    #if ( ( GUCEF_PLATFORM == GUCEF_PLATFORM_LINUX ) || ( GUCEF_PLATFORM == GUCEF_PLATFORM_ANDROID ) )

    fptr.objPtr = dlsym( sohandle     ,
                         functionname );
    return fptr;

    #elif ( GUCEF_PLATFORM == GUCEF_PLATFORM_MSWIN )

    /*
     *      First we try a normal load using the given
     *      functionname.
     *
     *      Type: Function
     */
    fptr.funcPtr = (TDefaultFuncPtr) GetProcAddress( (HMODULE)sohandle ,
                                                     functionname      );
    if ( fptr.funcPtr == NULL )
    {
        char buffer[ 1024 ];
        UInt32 len = (UInt32)strlen( functionname );

        /*
         *      Maybe without the param bytes then :(
         *
         *      Type: _Function
         */
        strncpy( buffer+1, functionname, len+1 );
        *buffer = '_';
        fptr.funcPtr = (TDefaultFuncPtr) GetProcAddress( (HMODULE)sohandle ,
                                                         buffer            );

        /*
         *      Try adding the param bytes value
         *      ... So much for naming conventions :/
         *
         *      Type: _Function@n
         */
        if ( fptr.funcPtr == NULL )
        {
            sprintf( buffer+len+1, "@%d", parambytes );
            fptr.funcPtr = (TDefaultFuncPtr) GetProcAddress( (HMODULE)sohandle ,
                                                             buffer            );

            /*
             *      Last but not least try..
             *
             *      Type: Function@n
             */
            if ( fptr.funcPtr == NULL )
            {
                fptr.funcPtr = (TDefaultFuncPtr) GetProcAddress( (HMODULE)sohandle ,
                                                                  buffer+1         );
            }
        }

    }
    return fptr;

    #else
    #error Unsupported target platform
    #endif
}

/*--------------------------------------------------------------------------*/

#ifdef GUCEF_MSWIN_BUILD

static HWND
GetCurrentHWND( void )
{
        const char* hwndstr;
        HWND whandle = NULL;

        #ifdef SDL_SUPPORT

        /*
         *      If SDL is supported we will try to get the HWND from SDL
         */
        SDL_SysWMinfo winfo;
        SDL_GetWMInfo( &winfo );
        whandle = winfo.window;

        if ( !whandle ) {

        #endif

        #pragma warning( disable: 4047 ) // 'HWND' differs in levels of indirection from 'Int32'

        /*
         *      Try to get the HWND from the process environment settings
         */
        hwndstr = GUCEFGetEnv( "HWND" );
        if ( hwndstr )
        {
                whandle = (HWND) Str_To_Int( hwndstr );
        }
        else
        {
                /*
                 *      If all previous attempts failed then try to use the previous
                 *      clipboard owner (if there is one).
                 */
                whandle = GetClipboardOwner();
        }

        #ifdef SDL_SUPPORT
        }
        #endif

        return whandle;
}

#endif /* GUCEF_MSWIN_BUILD ? */

/*--------------------------------------------------------------------------*/

UInt32
StringToClipboard( const char *str )
{
    #ifdef GUCEF_MSWIN_BUILD

    if ( str )
    {
        UInt32 strlength = (UInt32) strlen( str );

        HWND whandle = GetCurrentHWND();
        UInt32 success = OSWRAP_FALSE;
        HGLOBAL hglbcopy;
        LPTSTR lptstrcopy;

        /*
         *      Open the clipboard with the current task as the owner
         */
        if ( !OpenClipboard( whandle ) ) return OSWRAP_FALSE;

        /*
         *      Try to empty the clipboard so that we can get ownership of the
         *      clipboard which is needed for placing data on it.
         */
        EmptyClipboard();

        /*
         *      Allocate global MS windows managed memory for the text
         */
        hglbcopy = GlobalAlloc( GMEM_MOVEABLE                 ,
                                (strlength+1) * sizeof(TCHAR) );
        if ( hglbcopy == NULL )
        {
                CloseClipboard();
                return OSWRAP_FALSE;
        }

        /*
         *      Now we have to lock the memory we just allocated so that
         *      windows keeps it's paws off of it. After that we can copy
         *      our text into the global memory buffer
         */
        lptstrcopy = (LPTSTR) GlobalLock( hglbcopy );
        memcpy( lptstrcopy, str, strlength+1 );
        GlobalUnlock( hglbcopy );

        /*
         *      We now attempt to set the string in the clipboard.
         *      This will fail if the handle we used in OpenClipboard() is
         *      NULL or incorrect.
         */
        if ( SetClipboardData( CF_TEXT, hglbcopy ) )
        {
            success = OSWRAP_TRUE;
        }
        else
        {
            success = OSWRAP_FALSE;
        }

        /*
         *      Close the clipboard so that other tasks have access again
         */
        CloseClipboard();

        return success;
    }
    return OSWRAP_FALSE;

    #else /* GUCEF_MSWIN_BUILD */

    return OSWRAP_FALSE;

    #endif /* OS WRAPPING */
}

/*--------------------------------------------------------------------------*/

/**
 *      Function that attempts to retrieve a string from the O/S clipboard
 *      If this functionality is not implemented for you O/S or if it fails then
 *      OSWRAP_FALSE will be returned. Otherwise OSWRAP_TRUE will be returned.
 *      It is assumed that dest has points to size number of allocated bytes.
 *      The actual number of bytes written into the destination buffer is
 *      written into wbytes. If you wish to retrieve all text on the clipboard
 *      you might want to continue calling this function as long as wbytes
 *      equals size. Do note that any other proccess can empty the clipboard
 *      in between calls.
 */
UInt32
StringFromClipboard( char *dest     ,
                     UInt32 size    ,
                     UInt32 *wbytes )
{
        #ifdef GUCEF_MSWIN_BUILD

        HWND whandle = GetCurrentHWND();
        HGLOBAL hglb;
        UInt32 success = OSWRAP_FALSE;

        #ifdef SDL_SUPPORT

        SDL_SysWMinfo winfo;

        #endif /* SDL_SUPPORT */

        if ( IsClipboardFormatAvailable( CF_TEXT ) )
        {
                /*
                 *      Open the clipboard with the current task as the owner
                 */
                if ( !OpenClipboard( whandle ) ) return OSWRAP_FALSE;

                /*
                 *      Get a pointer to the data using the global handle we will
                 *      obtain if possible. Then copy the data pointed to by the handle
                 *      into the buffer provided by the user
                 */
                hglb = GetClipboardData( CF_TEXT );
                if ( hglb != NULL )
                {
                        LPTSTR lptstr = (LPTSTR) GlobalLock( hglb );
                        if ( lptstr != NULL )
                        {
                                UInt32 offset = *wbytes;
                                UInt32 dsize = (UInt32) strlen( lptstr );
                                if ( dsize > offset )
                                {
                                        dsize -= offset;
                                        if ( dsize > size-1 ) dsize = size-1;
                                        strncpy( dest, lptstr+offset, dsize );
                                        *wbytes += dsize;

                                        success = OSWRAP_TRUE;
                                }
                                GlobalUnlock( hglb );
                        }
                        else
                        {
                                *wbytes = 0;
                        }
                }

                /*
                 *      Close the clipboard so that other tasks have access again
                 */
                CloseClipboard();

                return success;
        }
        return OSWRAP_FALSE;

        #else /* GUCEF_MSWIN_BUILD */

        return OSWRAP_FALSE;

        #endif /* OS WRAPPING */
}

/*--------------------------------------------------------------------------*/

UInt32
GUCEFSetEnv( const char* key   ,
             const char* value )
{GUCEF_TRACE;

    #ifdef GUCEF_MSWIN_BUILD

    UInt32 retval;
    char* envstr = (char*) malloc( strlen( key ) + strlen( value )+2 );
    sprintf( envstr, "%s=%s", key, value );
    retval = _putenv( envstr );
    free( envstr );
    return retval == 0;

    #else

    return setenv( key, value, 1 ) == 0;

    #endif
}

/*--------------------------------------------------------------------------*/

const char*
GUCEFGetEnv( const char* key )
{GUCEF_TRACE;

    return getenv( key );
}

/*--------------------------------------------------------------------------*/

UInt32
GUCEFGetTickCount( void )
{
    #if ( GUCEF_PLATFORM == GUCEF_PLATFORM_MSWIN )

    return GetTickCount();

    #elif ( ( GUCEF_PLATFORM == GUCEF_PLATFORM_LINUX ) || ( GUCEF_PLATFORM == GUCEF_PLATFORM_ANDROID ) )

    #if 1
    struct timespec now;
    clock_gettime( CLOCK_MONOTONIC, &now );
    return (UInt32) ( now.tv_sec*1000000000LL + now.tv_nsec );
    #else
    struct tms timeStorage;
    return (UInt32) times( &timeStorage );
    #endif

    #else
    #error unsupported platform
    #endif
}

/*--------------------------------------------------------------------------*/

void
ShowErrorMessage( const char* message     ,
                  const char* description )
{
    #ifdef GUCEF_MSWIN_BUILD
    MessageBox( GetCurrentHWND()                    ,
                description                         ,
                message                             ,
                MB_OK | MB_ICONERROR | MB_TASKMODAL );
    #else
    fprintf( stderr, "%s : %s\n", message, description );
    #endif
}

/*--------------------------------------------------------------------------*/

UInt32
GetCPUCountPerPackage( void )
{
    /* Number of Logical Cores per Physical Processor */
    UInt32 coreCount = 1;

    /* Initialize to 1 to support older processors. */
    #if ( GUCEF_COMPILER == GUCEF_COMPILER_MSVC )
    _asm
    {
        mov		eax, 1
        cpuid
        /* Test for HTT bit */
        test	edx, 0x10000000
        jz		Unp
        /* Multi-core or Hyperthreading supported...
        // Read the "# of Logical Processors per Physical Processor" field: */
        mov		eax, ebx
        and		eax, 0x00FF0000 /* Mask the "logical core counter" byte */
        shr		eax, 16 // Shift byte to be least-significant
        mov		coreCount, eax
        /* Uniprocessor (i.e. Pentium III or any AMD CPU excluding their new
        dual-core A64)  */
        Unp:
        /* coreCount will contain 1. */
    }
    #endif

    return coreCount;
}

/*--------------------------------------------------------------------------*/

UInt32
GetPhysicalCPUCount( void )
{
    return GetLogicalCPUCount() / GetCPUCountPerPackage();
}

/*--------------------------------------------------------------------------*/

UInt32
GetLogicalCPUCount( void )
{
    #ifdef GUCEF_MSWIN_BUILD
    SYSTEM_INFO systemInfo;
    GetSystemInfo( &systemInfo );
    return systemInfo.dwNumberOfProcessors;
    #else
    return 1;
    #endif
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifdef __cplusplus
}; /* namespace CORE */
}; /* namespace GUCEF */
#endif /* __cplusplus ? */

/*--------------------------------------------------------------------------*/
