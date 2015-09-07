/*
 *  guidriverCEGUIOpenGL: glue module for the MyGUI GUI backend using OpenGL
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

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#ifndef GUCEF_VFS_CVFSGLOBAL_H
#include "gucefVFS_CVfsGlobal.h"
#define GUCEF_VFS_CVFSGLOBAL_H
#endif /* GUCEF_VFS_CVFSGLOBAL_H ? */

#ifndef GUCEF_VFS_CVFS_H
#include "gucefVFS_CVFS.h"
#define GUCEF_VFS_CVFS_H
#endif /* GUCEF_VFS_CVFS_H ? */

#include "guidriverCEGUIOpenGL_CImageLoader.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace GUIDRIVERCEGUIGL {

/*-------------------------------------------------------------------------//
//                                                                         //
//      UTILITIES                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

CImageLoader::CImageLoader( void )
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/

CImageLoader::~CImageLoader()
{GUCEF_TRACE;

}

/*-------------------------------------------------------------------------*/

GUIDRIVERCEGUI::PixelFormat
CImageLoader::ConvertPixelFormat( IMAGE::TPixelMapPtr pixelMap )
{
    if ( pixelMap->GetPixelChannelSize() == 1 )
    {
        switch ( pixelMap->GetPixelStorageFormat() )
        {
            case IMAGE::PSF_RGB : return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::R8G8B8 );
            case IMAGE::PSF_RGBA : return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::R8G8B8A8 );
            case IMAGE::PSF_BGR :
            {
                pixelMap->ConvertPixelStorageFormatTo( IMAGE::PSF_RGB );
                return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::R8G8B8 );
            }
            case IMAGE::PSF_BGRA :
            {
                pixelMap->ConvertPixelStorageFormatTo( IMAGE::PSF_RGBA );
                return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::R8G8B8A8 );
            }
            case IMAGE::PSF_SINGLE_CHANNEL : return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::L8 );
            case IMAGE::PSF_SINGLE_CHANNEL_RED : return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::L8 );
            case IMAGE::PSF_SINGLE_CHANNEL_GREEN : return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::L8 );
            case IMAGE::PSF_SINGLE_CHANNEL_BLUE : return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::L8 );
            case IMAGE::PSF_SINGLE_CHANNEL_ALPHA : return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::L8 );
            case IMAGE::PSF_SINGLE_CHANNEL_LUMINANCE : return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::L8 );

            case IMAGE::PSF_LUMINANCE_ALPHA : return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::L8A8 );

            default:
            {
                return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::Unknow );
            }
        }
    }
    // else: MyGui cannot handle multi-byte channels
    return GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::Unknow );
}

/*-------------------------------------------------------------------------*/

IMAGE::TPixelStorageFormat
CImageLoader::TranslatePixelFormat( const GUIDRIVERCEGUI::PixelFormat myGuiPixelFormat )
{
    if ( myGuiPixelFormat == GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::R8G8B8 ) ) return IMAGE::PSF_RGB;
    if ( myGuiPixelFormat == GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::R8G8B8A8 ) ) return IMAGE::PSF_RGBA;
    if ( myGuiPixelFormat == GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::L8 ) ) return IMAGE::PSF_SINGLE_CHANNEL_LUMINANCE;
    if ( myGuiPixelFormat == GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::L8A8 ) ) return IMAGE::PSF_LUMINANCE_ALPHA;
    return IMAGE::PSF_UNKNOWN;
}

/*-------------------------------------------------------------------------*/

void*
CImageLoader::loadImage( int& _width                  ,
                         int& _height                 ,
                         GUIDRIVERCEGUI::PixelFormat& _format  ,
                         const std::string& _filename )
{GUCEF_TRACE;

    CORE::CString dataType = CORE::ExtractFileExtention( _filename ).Lowercase();
    
    VFS::CVFS& vfs = VFS::CVfsGlobal::Instance()->GetVfs();
    VFS::CVFS::CVFSHandlePtr filePtr = vfs.GetFile( _filename );

    if ( 0 != filePtr )
    {
        IMAGE::CImage image;
        if ( image.Load( *filePtr->GetAccess() ,
                         dataType              ) )
        {
            // We don't care about mipmapping or frames, get 0,0
            IMAGE::TPixelMapPtr pixelMap = image.GetPixelMap( 0, 0 );
            if ( 0 != pixelMap )
            {
                // Translate pixel format enum and convert as needed
                _format = ConvertPixelFormat( pixelMap );
                if ( _format != GUIDRIVERCEGUI::PixelFormat( GUIDRIVERCEGUI::PixelFormat::Unknow ) )
                {
                    pixelMap->FlipHorizontal();
                    
                    // We have our data, release to MyGui, it takes ownership
                    _width = (int) pixelMap->GetWidthInPixels();
                    _height = (int) pixelMap->GetHeightInPixels();

                    return pixelMap->RelinquishPixelDataOwnership();
                }
            }
        }
    }

    return NULL;
}

/*-------------------------------------------------------------------------*/

void
CImageLoader::saveImage( int _width                   ,
                         int _height                  ,
                         GUIDRIVERCEGUI::PixelFormat _format   ,
                         void* _texture               ,
                         const std::string& _filename )
{
    CORE::CString dataType = CORE::ExtractFileExtention( _filename ).Lowercase();
    
    VFS::CVFS& vfs = VFS::CVfsGlobal::Instance()->GetVfs();
    VFS::CVFS::CVFSHandlePtr filePtr = vfs.GetFile( _filename, "wb" );

    if ( 0 != filePtr )
    {
        IMAGE::TPixelMapPtr pixelMap = new IMAGE::CPixelMap( _texture                         , 
                                                             _width                           ,
                                                             _height                          ,
                                                             TranslatePixelFormat( _format )  ,
                                                             MT::DATATYPE_UINT8               );
        
        IMAGE::CImage image;
        image.Assign( pixelMap );
        image.Save( *filePtr->GetAccess() ,
                    dataType              );
    }
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace MYGUI */
}; /* namespace GUCE */

/*-------------------------------------------------------------------------*/
