/*
 *  ProjectGenerator: Tool to generate module/project files
 *  Copyright (C) 2002 - 2011.  Dinand Vanvelzen
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

#ifndef GUCEF_CORE_CDSTORECODECPLUGINMANAGER_H
#include "CDStoreCodecPluginManager.h"
#define GUCEF_CORE_CDSTORECODECPLUGINMANAGER_H
#endif /* GUCEF_CORE_CDSTORECODECPLUGINMANAGER_H ? */

#ifndef GUCEF_CORE_LOGGING_H
#include "gucefCORE_Logging.h"
#define GUCEF_CORE_LOGGING_H
#endif /* GUCEF_CORE_LOGGING_H ? */

#ifndef GUCEF_CORE_DVCPPSTRINGUTILS_H
#include "dvcppstringutils.h"
#define GUCEF_CORE_DVCPPSTRINGUTILS_H
#endif /* GUCEF_CORE_DVCPPSTRINGUTILS_H ? */

#ifndef GUCEF_CORE_DVFILEUTILS_H
#include "dvfileutils.h"
#define GUCEF_CORE_DVFILEUTILS_H
#endif /* GUCEF_CORE_DVFILEUTILS_H ? */

#ifndef GUCEF_CORE_DVOSWRAP_H
#include "DVOSWRAP.h"
#define GUCEF_CORE_DVOSWRAP_H
#endif /* GUCEF_CORE_DVOSWRAP_H ? */

#ifndef GUCEF_CORE_LOGGING_H
#include "gucefCORE_Logging.h"
#define GUCEF_CORE_LOGGING_H
#endif /* GUCEF_CORE_LOGGING_H ? */

#include "ProjectGenDependsFilter_CDependsFilter.h"

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace PROJECTGEN {
namespace DEPFILTER {

/*-------------------------------------------------------------------------//
//                                                                         //
//      IMPLEMENTATION                                                     //
//                                                                         //
//-------------------------------------------------------------------------*/

CDependsFilter::CDependsFilter( void )
    : CIProjectPreprocessor()
{GUCEF_TRACE;

}

/*--------------------------------------------------------------------------*/
    
CDependsFilter::CDependsFilter( const CDependsFilter& src )
{GUCEF_TRACE;

}

/*--------------------------------------------------------------------------*/
    
CDependsFilter::~CDependsFilter()
{GUCEF_TRACE;

}

/*--------------------------------------------------------------------------*/
    
CDependsFilter&
CDependsFilter::operator=( const CDependsFilter& src )
{GUCEF_TRACE;

    return *this;
}

/*--------------------------------------------------------------------------*/

CDependsFilter::TStringSet
CDependsFilter::GetListOfModules( const TStringVector& dependsCsvFiles )
{GUCEF_TRACE;

    TStringSet modules;
    TStringVector::const_iterator i = dependsCsvFiles.begin();
    while ( i != dependsCsvFiles.end() )
    {
        CORE::CString csvContent;
        if ( CORE::LoadTextFileAsString( CORE::RelativePath( (*i) ), csvContent, true, "\n" ) )
        {
            TStringVector lines = csvContent.ParseElements( '\n', false );
            csvContent.Clear();

	        TStringSet modules;
	        TStringVector::iterator n = lines.begin();
	        while ( n != lines.end() )
	        {
		        CORE::Int32 firstCommaPos = (*i).HasChar( ',', 0, true );
		        if ( -1 != firstCommaPos )
		        {
			        CORE::Int32 secondCommaPos = (*i).HasChar( ',', firstCommaPos+1, true );
			        if ( -1 != secondCommaPos )
			        {	
				        // Name also has quotes around it, lets strip those
				        CORE::Int32 nameLength = (secondCommaPos-1) - firstCommaPos;
				        if ( nameLength > 2 )
				        {
					        nameLength -= 2;
					        CORE::CString moduleName = (*i).SubstrFromRange( firstCommaPos+2, nameLength );

                            // Strip the extention from the file name
                            Int32 dotIndex = moduleName.HasChar( '.', false );
                            moduleName = moduleName.SubstrToIndex( dotIndex, true );
                            
                            // For easy searches lets make the names lowercase.
                            // Depends is a MS Windows tool so case sensitivity is not an issue anyway
                            moduleName = moduleName.Lowercase();

					        modules.insert( moduleName );

					        GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Found dependency module with name \"" + moduleName + "\"" );
				        }
			        }
		        }
		        ++n;
	        }
	        lines.clear();
        }        
        ++i;
    }

    return modules;
}

/*--------------------------------------------------------------------------*/
    
bool
CDependsFilter::ProccessProjects( TProjectInfo& projectInfo      ,
                                  const CORE::CString& outputDir ,
                                  const CORE::CValueList& params )
{GUCEF_TRACE;
   
    CORE::CString filterFileStr = params.GetValueAlways( "DependsFilter" );
    TStringVector dependsCsvFiles = filterFileStr.ParseElements( ';', false );

    GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Executing Depends filter on the given project info. There are " + CORE::UInt32ToString( dependsCsvFiles.size() ) + " csv files given" );
    
    // Obtain a list of all modules from the Depends generated csv files.
    TStringSet modules = GetListOfModules( dependsCsvFiles );

    // Mark all the modules from the project which are not in the modules list for deletion
    TStringSet deleteList;
    TModuleInfoEntryVector& moduleInfoList = projectInfo.modules;
    TModuleInfoEntryVector::iterator i = moduleInfoList.begin(); 
    while ( i != moduleInfoList.end() )
    {
        CString moduleName = GetConsensusModuleName( (*i) );        
        TStringSet::iterator n = modules.find( moduleName.Lowercase() );
        if ( n == modules.end() )
        {
            // The given module is not in the list of modules we obtained from depends
            // as such we should filter it out
            deleteList.insert( (*i).rootDir + ':' + moduleName );
        }

        ++i;
    }
    GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Based on the Depends filter there are now " + CORE::UInt32ToString( deleteList.size() ) + " modules listed for deletion" );

    if ( !deleteList.empty() )
    {
        TModuleInfoEntryVector::iterator i = moduleInfoList.begin(); 
        while ( i != moduleInfoList.end() )
        {
            CString moduleName = GetConsensusModuleName( (*i) );
            TStringSet::iterator n = deleteList.find( (*i).rootDir + ':' + moduleName );
            if ( n != deleteList.end() )
            {
                moduleInfoList.erase( i );
                i = moduleInfoList.begin();

                GUCEF_LOG( CORE::LOGLEVEL_NORMAL, "Filtered out module with consensus name: " + moduleName );
            }
            ++i;
        }
    }
    return true;
}

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace DEPFILTER */
}; /* namespace PROJECTGEN */
}; /* namespace GUCEF */

/*--------------------------------------------------------------------------*/