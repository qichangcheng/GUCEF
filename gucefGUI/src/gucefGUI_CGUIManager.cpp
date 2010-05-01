/*
 *  gucefGUI: GUCEF module providing a uniform interface towards GUI backends
 *  Copyright (C) 2002 - 2007.  Dinand Vanvelzen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
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

#ifndef GUCEF_CORE_CTRACER_H
#include "CTracer.h"
#define GUCEF_CORE_CTRACER_H
#endif /* GUCEF_CORE_CTRACER_H ? */

#include "gucefGUI_CGUIManager.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace GUI {

/*-------------------------------------------------------------------------//
//                                                                         //
//      GLOBAL VARS                                                        //
//                                                                         //
//-------------------------------------------------------------------------*/

CGUIManager* CGUIManager::g_instance = NULL;

const CORE::CEvent CGUIManager::DriverRegisteredEvent = "GUCEF::GUI::CGUIManager::DriverRegisteredEvent";
const CORE::CEvent CGUIManager::DriverUnregisteredEvent = "GUCEF::GUI::CGUIManager::DriverUnregisteredEvent";
const CORE::CEvent CGUIManager::FormFactoryRegisteredEvent = "GUCEF::GUI::CGUIManager::FormFactoryRegisteredEvent";
const CORE::CEvent CGUIManager::FormFactoryUnregisteredEvent = "GUCEF::GUI::CGUIManager::FormFactoryUnregisteredEvent";

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CGUIManager*
CGUIManager::Instance( void )
{GUCEF_TRACE;

    if ( g_instance == NULL )
    {
        g_instance = new CGUIManager();
    }
    return g_instance;
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::Deinstance( void )
{GUCEF_TRACE;

    delete g_instance;
    g_instance = NULL; 
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::RegisterEvents( void )
{GUCEF_TRACE;

    DriverRegisteredEvent.Initialize();
    DriverUnregisteredEvent.Initialize();
    FormFactoryRegisteredEvent.Initialize();
    FormFactoryUnregisteredEvent.Initialize();
}

/*-------------------------------------------------------------------------*/

CGUIManager::CGUIManager( void )
    : CObservingNotifier()   ,
      m_genericFormFactory() ,
      m_guiDrivers()
{GUCEF_TRACE;

    RegisterEvents();
}

/*-------------------------------------------------------------------------*/

CGUIManager::~CGUIManager()
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/

CIGUIContext*
CGUIManager::CreateGUIContext( const CString& guiDriverName )
{GUCEF_TRACE;

    TGUIDriverMap::iterator i = m_guiDrivers.find( guiDriverName );
    if ( i != m_guiDrivers.end() )
    {
        CGUIDriver* guiDriver = (*i).second;
        return guiDriver->CreateGUIContext();
    }
    return NULL;
}
/*-------------------------------------------------------------------------*/

void
CGUIManager::DestroyGUIContext( CIGUIContext* context )
{GUCEF_TRACE;

    CGUIDriver* guiDriver = context->GetDriver();
    guiDriver->DestroyGUIContext( context );
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::RegisterGUIDriver( const CString& guiDriverName ,
                                CGUIDriver* guiDriver        )
{GUCEF_TRACE;

    m_guiDrivers.insert( std::pair< CString, CGUIDriver* >( guiDriverName, guiDriver ) );
    GUCEF_SYSTEM_LOG( CORE::LOGLEVEL_NORMAL, "CGUIManager: Registered GUI driver (" + PointerToString( guiDriver ) + ") with name \"" + guiDriverName + "\"" );
    NotifyObservers( DriverRegisteredEvent );
}

/*-------------------------------------------------------------------------*/
    
void
CGUIManager::UnregisterGUIDriverByName( const CString& guiDriverName )
{GUCEF_TRACE;

    m_guiDrivers.erase( guiDriverName );
    GUCEF_SYSTEM_LOG( CORE::LOGLEVEL_NORMAL, "CGUIManager: Unregistered GUI driver with name \"" + guiDriverName + "\"" );
    NotifyObservers( DriverUnregisteredEvent );
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::RegisterGenericFormFactory( const CString& formTypeName   ,
                                         TConcreteFormFactory* factory )
{GUCEF_TRACE;

    m_genericFormFactory.RegisterConcreteFactory( formTypeName, factory );
    GUCEF_SYSTEM_LOG( CORE::LOGLEVEL_BELOW_NORMAL, "CGUIManager: Registered Generic form factory (" + PointerToString( factory ) + ") with type name \"" + formTypeName + "\"" );
}    

/*-------------------------------------------------------------------------*/

void
CGUIManager::UnregisterGenericFormFactory( const CString& formTypeName )
{GUCEF_TRACE;

    m_genericFormFactory.UnregisterConcreteFactory( formTypeName );
    GUCEF_SYSTEM_LOG( CORE::LOGLEVEL_BELOW_NORMAL, "CGUIManager: Unregistered Generic form factory with type name \"" + formTypeName + "\"" );
}

/*-------------------------------------------------------------------------*/
    
CGUIManager::TFormTypeSet
CGUIManager::GetGenericFormTypes( void ) const
{GUCEF_TRACE;

    TFormTypeSet formTypes;
    m_genericFormFactory.ObtainKeySet( formTypes );
    return formTypes;
}

/*-------------------------------------------------------------------------*/
    
bool
CGUIManager::HasGenericFormType( const CString& formTypeName )
{GUCEF_TRACE;

    return m_genericFormFactory.IsConstructible( formTypeName );
}

/*-------------------------------------------------------------------------*/
    
CForm*
CGUIManager::CreateGenericForm( const CString& formTypeName )
{GUCEF_TRACE;

    return m_genericFormFactory.Create( formTypeName );
}

/*-------------------------------------------------------------------------*/
    
void
CGUIManager::DestroyGenericForm( CForm* genericForm )
{GUCEF_TRACE;

    m_genericFormFactory.Destroy( genericForm );
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::OnFormFactoryRegistered( CORE::CNotifier* notifier    ,
                                      const CORE::CEvent& eventid  ,
                                      CORE::CICloneable* eventdata )
{GUCEF_TRACE;

    NotifyObservers( FormFactoryRegisteredEvent, eventdata );
}

/*-------------------------------------------------------------------------*/

void
CGUIManager::OnFormFactoryUnregistered( CORE::CNotifier* notifier    ,
                                        const CORE::CEvent& eventid  ,
                                        CORE::CICloneable* eventdata )
{GUCEF_TRACE;

    NotifyObservers( FormFactoryUnregisteredEvent, eventdata );
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace GUI */
}; /* namespace GUCEF */

/*-------------------------------------------------------------------------*/
