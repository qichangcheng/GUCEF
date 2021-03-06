/*
 *  gucefINPUT: GUCEF module providing input device interaction
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

#ifndef GUCEF_CORE_LOGGING_H
#include "gucefCORE_Logging.h"
#define GUCEF_CORE_LOGGING_H
#endif /* GUCEF_CORE_LOGGING_H ? */

#include "gucefINPUT_CKeyStateChangedEventData.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace INPUT {

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CKeyStateChangedEventData::CKeyStateChangedEventData( const Int32 contextId     ,
                                                      const UInt32 deviceID     ,
                                                      const KeyCode keyCode     ,
                                                      const bool pressedState   ,
                                                      const UInt32 keyModStates )
    : CICloneable()                  ,
      m_contextId( contextId )       ,
      m_deviceID( deviceID )         ,
      m_keyCode( keyCode )           ,
      m_pressedState( pressedState ) ,
      m_modStates( keyModStates )
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/

CKeyStateChangedEventData::CKeyStateChangedEventData( const CKeyStateChangedEventData& src )
    : CICloneable( src )                   ,
      m_contextId( src.m_contextId )       ,
      m_deviceID( src.m_deviceID )         ,
      m_keyCode( src.m_keyCode )           ,
      m_pressedState( src.m_pressedState ) ,
      m_modStates( src.m_modStates )
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/
                        
CKeyStateChangedEventData::~CKeyStateChangedEventData()
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/

Int32
CKeyStateChangedEventData::GetContextId( void ) const
{GUCEF_TRACE;

    return m_contextId;
}

/*-------------------------------------------------------------------------*/

UInt32
CKeyStateChangedEventData::GetDeviceID( void ) const
{GUCEF_TRACE;

    return m_deviceID;
}

/*-------------------------------------------------------------------------*/

KeyCode
CKeyStateChangedEventData::GetKeyCode( void ) const
{GUCEF_TRACE;

    return m_keyCode;
}

/*-------------------------------------------------------------------------*/
    
bool
CKeyStateChangedEventData::GetKeyPressedState( void ) const
{GUCEF_TRACE;

    return m_pressedState;
}

/*-------------------------------------------------------------------------*/
    
bool
CKeyStateChangedEventData::GetKeyModPressedState( const KeyModifier keyModifier ) const
{GUCEF_TRACE;

    return ( m_modStates & keyModifier ) > 0;
}

/*-------------------------------------------------------------------------*/

UInt32
CKeyStateChangedEventData::GetKeyModPressedStates( void ) const
{GUCEF_TRACE;

    return m_modStates;
}

/*-------------------------------------------------------------------------*/

CORE::CICloneable*
CKeyStateChangedEventData::Clone( void ) const
{GUCEF_TRACE;

    return new CKeyStateChangedEventData( *this );
}
    
/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace INPUT */
}; /* namespace GUCEF */

/*-------------------------------------------------------------------------*/