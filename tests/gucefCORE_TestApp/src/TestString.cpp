/*
 *  gucefCORE_TestApp: GUCEF test application for the CORE module
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

#include <iostream>

#ifndef GUCEF_CORE_CDVSTRING_H
#include "CDVString.h"
#define GUCEF_CORE_CDVSTRING_H
#endif /* GUCEF_CORE_CDVSTRING_H ? */

#include "TestString.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      MACROS                                                             //
//                                                                         //
//-------------------------------------------------------------------------*/

#if GUCEF_PLATFORM == GUCEF_PLATFORM_LINUX || GUCEF_PLATFORM == GUCEF_PLATFORM_ANDROID
  #define DEBUGBREAK __builtin_trap()
#elif GUCEF_PLATFORM == GUCEF_PLATFORM_MSWIN
  #define DEBUGBREAK DebugBreak()
#else
  #define DEBUGBREAK
#endif

#define ERRORHERE { std::cout << "Test failed @ " << __FILE__ << "(" << __LINE__ << ")\n"; DEBUGBREAK; }
#define ASSERT_TRUE( test ) if ( !(test) ) { ERRORHERE; } 
#define ASSERT_FALSE( test ) if ( (test) ) { ERRORHERE; }

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

using namespace GUCEF;

/*-------------------------------------------------------------------------*/

void
PerformStringTests( void )
{
    std::cout << "\n\n**** COMMENCING CString TESTS ****\n";
    
    try
    {
        CORE::CString testStr1;
        CORE::CString testStr2;
        static const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
        
        // test const char* assignment & == operator   
        testStr1 = alphabet;
        ASSERT_TRUE( testStr1 == alphabet );
         
        // test HasSubstr
        testStr1 = alphabet;
        CORE::Int32 testIndex = testStr1.HasSubstr( "fghi", true );
        ASSERT_TRUE( 5 == testIndex );
        testIndex = testStr1.HasSubstr( "fghi", false );
        ASSERT_TRUE( 5 == testIndex );
                
        // test SubstrToSubstr
        testStr1 = alphabet;
        testStr2 = testStr1.SubstrToSubstr( "fghi", true );
        ASSERT_TRUE( "abcde" == testStr2 );
        testStr2 = testStr1.SubstrToSubstr( "fghi", false );
        ASSERT_TRUE( "jklmnopqrstuvwxyz" == testStr2 );
        testStr2 = testStr1.SubstrToSubstr( "ghi", 3, true );
        ASSERT_TRUE( "def" == testStr2 );
        testStr2 = testStr1.SubstrToSubstr( "rst", 22, false );
        ASSERT_TRUE( "uvw" == testStr2 );
                
        // test FindMaxSubstrEquality
        //testStr2 = "jklmnopqrstuvwxyz";
        //testStr1.FindMaxSubstrEquality( testStr2, 0, true, true );

        // test ReplaceEnvelopingSubstr
        testStr1 = "$MYVAR:VALUE$";
        testStr2 = testStr1.ReplaceEnvelopingSubstr( "$MYVAR:", "$", "{{", "}}" );
        ASSERT_TRUE( testStr2 == "{{VALUE}}" );
        testStr1 = "blablabla$MYVAR:VALUE$foobar";
        testStr2 = testStr1.ReplaceEnvelopingSubstr( "$MYVAR:", "$", "{{", "}}" );
        ASSERT_TRUE( testStr2 == "blablabla{{VALUE}}foobar" );
        testStr2 = testStr1.ReplaceEnvelopingSubstr( "$NOT_HERE:", "$", "{{", "}}" );
        ASSERT_TRUE( testStr2 == testStr1 );
    }
    catch( ... )
    {
        ERRORHERE;
    }

    std::cout << "\n\n**** FINISHED CString TESTS ****\n";
}

/*-------------------------------------------------------------------------*/
