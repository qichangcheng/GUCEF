/*
 *  guidriverMyGUIOpenGL: glue module for the MyGUI GUI backend using OpenGL
 *  Copyright (C) 2002 - 2008.  Dinand Vanvelzen
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

#ifndef GUCEF_MYGUIGL_CGUICONTEXTGL_H
#define GUCEF_MYGUIGL_CGUICONTEXTGL_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_COBSERVINGNOTIFIER_H
#include "CObservingNotifier.h"
#define GUCEF_CORE_COBSERVINGNOTIFIER_H
#endif /* GUCEF_CORE_COBSERVINGNOTIFIER_H ? */

#ifndef GUCEF_GUI_CWINDOWCONTEXT_H
#include "gucefGUI_CWindowContext.h"
#define GUCEF_GUI_CWINDOWCONTEXT_H
#endif /* GUCEF_GUI_CWINDOWCONTEXT_H ? */

#ifndef __MYGUI_OPENGL_RENDER_MANAGER_H__
#include "MyGUI_OpenGLRenderManager.h"
#define __MYGUI_OPENGL_RENDER_MANAGER_H__
#endif /* __MYGUI_OPENGL_RENDER_MANAGER_H__ ? */

#ifndef GUCEF_MYGUI_CGUICONTEXT_H
#include "guceMyGUI_CGUIContext.h"
#define GUCEF_MYGUI_CGUICONTEXT_H
#endif /* GUCEF_MYGUI_CGUICONTEXT_H ? */

#ifndef GUCEF_MYGUIGL_MACROS_H
#include "guidriverMyGUIOpenGL_macros.h"
#define GUCEF_MYGUIGL_MACROS_H
#endif /* GUCEF_MYGUIGL_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace MYGUIGL {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

class CGUIDriverGL;

/*-------------------------------------------------------------------------*/

/**
 *  Implementation of the GUI context for the MyGUI & OpenGL combo
 */
class GUCEF_MYGUIGL_EXPORT_CPP CGUIContextGL : public MYGUI::CGUIContext ,
                                               public CORE::CObserver
{
    public:

    CGUIContextGL( CGUIDriverGL& guiDriver                   ,
                   MyGUI::OpenGLRenderManager* renderManager ,
                   GUI::TWindowContextPtr windowContext      ,
                   INPUT::CInputContext* inputContext        );

    virtual ~CGUIContextGL();

    virtual const CORE::CString& GetClassTypeName( void ) const;

    protected:

    virtual void OnNotify( CORE::CNotifier* notifier          ,
                           const CORE::CEvent& eventID        ,
                           CORE::CICloneable* evenData = NULL );

    private:

    CGUIContextGL( const CGUIContextGL& src );
    CGUIContextGL& operator=( const CGUIContextGL& src );

    private:

    MyGUI::OpenGLRenderManager* m_renderManager;
    GUI::TWindowContextPtr m_windowContext;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

} /* namespace MYGUIGL */
} /* namespace GUCEF */

/*-------------------------------------------------------------------------*/

#endif /* GUCEF_MYGUIGL_CGUICONTEXTGL_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 08-04-2007 :
        - Initial implementation

---------------------------------------------------------------------------*/
