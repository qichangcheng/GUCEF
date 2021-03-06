///*
// *  guidriverCEGUI: glue module for the CEGUI GUI backend
// *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
// *
// *  This library is free software; you can redistribute it and/or
// *  modify it under the terms of the GNU Lesser General Public
// *  License as published by the Free Software Foundation; either
// *  version 2.1 of the License, or (at your option) any later version.
// *
// *  This library is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// *  Lesser General Public License for more details.
// *
// *  You should have received a copy of the GNU Lesser General Public
// *  License along with this library; if not, write to the Free Software
// *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
// */
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      INCLUDES                                                           //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//#include "guceMyGUIOgre_CTabContentPaneImp.h"
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      NAMESPACE                                                          //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//namespace GUCEF {
//namespace GUIDRIVERCEGUI {
//
///*-------------------------------------------------------------------------//
////                                                                         //
////      UTILITIES                                                          //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//CTabContentPaneImp::CTabContentPaneImp( void )
//    : CWidgetImp< GUCEF::GUI::CTabContentPane >() ,
//      m_tabContentPane( NULL )
//{GUCEF_TRACE;
//
//}
//    
///*-------------------------------------------------------------------------*/
//    
//CTabContentPaneImp::~CTabContentPaneImp()
//{GUCEF_TRACE;
//
//}
//
///*-------------------------------------------------------------------------*/
//    
//GUCEF::GUI::CTabControl*
//CTabContentPaneImp::GetParentTabControl( void )
//{GUCEF_TRACE;
//
//    return NULL;
//}
//
///*-------------------------------------------------------------------------*/
//    
//const CString&
//CTabContentPaneImp::GetClassTypeName( void ) const
//{GUCEF_TRACE;
//
//    static const CString classTypeName = "GUCE::CEGUIOGRE::CTabContentPaneImp";
//    return classTypeName;
//}
//
///*-------------------------------------------------------------------------*/
//
//void
//CTabContentPaneImp::Hook( CEGUI::Window* tabContentPane )
//{GUCEF_TRACE;
//
//    m_tabContentPane = tabContentPane;
//    CWidgetImp< GUCEF::GUI::CTabContentPane >::Hook( tabContentPane );
//}
//    
///*-------------------------------------------------------------------------//
////                                                                         //
////      NAMESPACE                                                          //
////                                                                         //
////-------------------------------------------------------------------------*/
//
//}; /* namespace GUIDRIVERCEGUI */
//}; /* namespace GUCEF */
//
///*-------------------------------------------------------------------------*/
