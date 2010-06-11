/*
 *  gucefSMDRN: GUCEF module providing sector managed DRN
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

#ifndef GUCEF_SMDRN_CSECTORVECTOR_H
#define GUCEF_SMDRN_CSECTORVECTOR_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_DRN_CDRNNODE_H
#include "gucefDRN_CDRNNode.h"
#define GUCEF_DRN_CDRNNODE_H
#endif /* GUCEF_DRN_CDRNNODE_H ? */

#ifndef GUCEF_SMDRN_MACROS_H
#include "gucefSMDRN_macros.h"         /* often used gucefSMDRN macros */
#define GUCEF_SMDRN_MACROS_H
#endif /* GUCEF_SMDRN_MACROS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace SMDRN {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

/**
 *  Class that stores a sector vector
 */
class GUCEF_SMDRN_EXPORT_CPP CSectorVector
{
    public
    
    CSectorVector( CSectorGrid* sectorGrid );
    
    CSectorPosition& GetPosition( void );
    
    const CSectorPosition& GetPosition( void ) const;
    
    UInt32 GetDistanceX( void ) const;
    
    UInt32 GetDistanceY( void ) const;
    
    UInt32 GetDistanceZ( void ) const;
    
    private:

    UInt32 m_distanceX;
    UInt32 m_distanceY;
    UInt32 m_distanceZ;
    CSectorPosition m_position;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace SMDRN */
}; /* namespace GUCEF */

/*-------------------------------------------------------------------------*/
          
#endif /* GUCEF_SMDRN_CSECTORVECTOR_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 12-02-2005 :
        - Initial implementation

-----------------------------------------------------------------------------*/