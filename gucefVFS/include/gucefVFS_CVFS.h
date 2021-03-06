/*
 *  gucefVFS: GUCEF module implementing a Virtual File System
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */

#ifndef GUCEF_VFS_CVFS_H
#define GUCEF_VFS_CVFS_H

/*-------------------------------------------------------------------------//
//                                                                         //
//      INCLUDES                                                           //
//                                                                         //
//-------------------------------------------------------------------------*/

#ifndef GUCEF_MT_GUCEFMT_H
#include "gucefMT.h"                 /* gucefMT library API */
#define GUCEF_MT_GUCEFMT_H
#endif /* GUCEF_MT_GUCEFMT_H ? */

#ifndef GUCEF_CORE_CICONFIGURABLE_H
#include "CIConfigurable.h"          /* abstract base class interface for configurable objects */
#define GUCEF_CORE_CICONFIGURABLE_H
#endif /* GUCEF_CORE_CICONFIGURABLE_H ? */

#ifndef GUCEF_CORE_CTABSTRACTFACTORY_H
#include "CTAbstractFactory.h"
#define GUCEF_CORE_CTABSTRACTFACTORY_H
#endif /* GUCEF_CORE_CTABSTRACTFACTORY_H ? */

#ifndef GUCEF_VFS_CIARCHIVE_H
#include "gucefVFS_CIArchive.h"
#define GUCEF_VFS_CIARCHIVE_H
#endif /* GUCEF_VFS_CIARCHIVE_H ? */

#ifndef GUCEF_VFS_CIARCHIVE_H
#include "gucefVFS_CVFSURLHandler.h"
#define GUCEF_VFS_CIARCHIVE_H
#endif /* GUCEF_VFS_CIARCHIVE_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

namespace GUCEF {
namespace VFS {

/*-------------------------------------------------------------------------//
//                                                                         //
//      CLASSES                                                            //
//                                                                         //
//-------------------------------------------------------------------------*/

/**
 *      Threadsafe Virtual File System
 */
class GUCEF_VFS_PUBLIC_CPP CVFS : public CORE::CIConfigurable
{
    public:
    
    typedef CORE::CTAbstractFactory< CString, CIArchive > TAbstractArchiveFactory;
    typedef TAbstractArchiveFactory::TConcreteFactory     TArchiveFactory;
    typedef CIArchive::CVFSHandlePtr                      CVFSHandlePtr;
    typedef CIArchive::TStringList                        TStringList;
    typedef CIArchive::TStringSet                         TStringSet;
    
    void AddRoot( const CString& rootdir                     ,
                  const CString& archiveName                 ,
                  const bool writeable = false               ,
                  const bool autoMountArchives = false       ,
                  const CString& mountPoint = CString::Empty );

    bool MountArchive( const CString& archiveName  ,
                       const CString& archivePath  ,
                       const bool writeableRequest );
                  
    bool MountArchive( const CString& archiveName  ,
                       const CString& archivePath  ,
                       const CString& mountPoint   ,
                       const bool writeableRequest );
    
    bool MountArchive( const CString& archiveName  ,
                       const CString& archivePath  ,
                       const CString& archiveType  ,
                       const CString& mountPoint   ,
                       const bool writeableRequest );

    bool UnmountArchiveByName( const CString& archiveName );
                  
    void RegisterArchiveFactory( const CString& archiveType      ,
                                 TArchiveFactory& archiveFactory );
    
    void UnregisterArchiveFactory( const CString& archiveType );
    
    CVFSHandlePtr GetFile( const CORE::CString& file    ,
                           const char* mode = "rb"      ,
                           const bool overwrite = false );
                                  
    void GetList( TStringSet& outputList             ,
                  const CORE::CString& location      , 
                  bool recursive = false             ,
                  bool includePathInFilename = false ,
                  const CORE::CString& filter = ""   ,
                  bool addFiles = true               ,
                  bool addDirs  = false              ) const;

    void GetList( CORE::CDataNode& outputDataTree    ,
                  const CORE::CString& location      , 
                  bool recursive = false             ,
                  const CORE::CString& filter = ""   ,
                  const bool addHash = false         ) const;
                  
    /**
     *  Checks if the item pointed at is a mounted archive
     */
    bool IsMountedArchive( const CString& location ) const;
    
    /**
     *  Searches for archives mounted at the "location"
     *  directory and below (if recursive is true) and filters the results.
     */
    void GetMountedArchiveList( const CString& location ,
                                const CString& filter   ,
                                const bool recursive    ,
                                TStringSet& outputList  ) const;
    
    bool FileExists( const CString& filePath ) const;
    
    UInt32 GetFileSize( const CString& filePath ) const;
    
    CORE::CString GetFileHash( const CString& filename ) const;
    
    time_t GetFileModificationTime( const CString& filename ) const;

    bool GetActualFilePath( const CString& file ,
                            CString& path       ) const;

    bool GetVfsPathForAbsolutePath( const CString& absolutePath ,
                                    CString& relativePath       ) const;

    void SetMemloadSize( UInt32 bytesize );
    
    UInt32 GetMemloadSize( void ) const;
    
    /**
     *      Attempts to store the given tree in the file
     *      given according to the method of the codec metadata
     *
     *      @param tree the data tree you wish to store
     *      @return wheter storing the tree was successfull
     */
    virtual bool SaveConfig( CORE::CDataNode& tree );
                                
    /**
     *      Attempts to load data from the given file to the 
     *      root node given. The root data will be replaced 
     *      and any children the node may already have will be deleted.
     *
     *      @param treeroot pointer to the node that is to act as root of the data tree
     *      @return whether building the tree from the given file was successfull.
     */                                    
    virtual bool LoadConfig( const CORE::CDataNode& treeroot );                                             

    static bool FilterValidation( const CString& filename , 
                                  const CString& filter   );

    private:
    friend class CVfsGlobal;

    CVFS( void );

    virtual ~CVFS();
    
    private:

    struct SMountEntry
    {
        CORE::CString abspath;
        CORE::CString path;
        bool writeable;
        CIArchive* archive;
        CORE::CString mountPath;
    };
    typedef struct SMountEntry TMountEntry;
    
    struct SConstMountLink
    {
        const TMountEntry* mountEntry;
        CString remainder;
    };
    typedef struct SConstMountLink TConstMountLink;
    
    typedef std::vector< TMountEntry >                   TMountVector;
    typedef std::vector< TConstMountLink >               TConstMountLinkVector;
    typedef CORE::CTSharedPtr< CORE::CDynamicBuffer >    TDynamicBufferPtr;
    
    static MT::CMutex m_datalock;
    
    CVFS( const CVFS& src );                /**< not implemented, must be unique */
    CVFS& operator=( const CVFS& src );     /**< not implemented, must be unique */

    void GetEligableMounts( const CString& location                ,
                            TConstMountLinkVector& mountLinkVector ) const;
    private:    
    
    TMountVector m_mountList;
    UInt32 _maxmemloadsize;
    TAbstractArchiveFactory m_abstractArchiveFactory;
};

/*-------------------------------------------------------------------------//
//                                                                         //
//      NAMESPACE                                                          //
//                                                                         //
//-------------------------------------------------------------------------*/

}; /* namespace VFS */
}; /* namespace GUCEF */

/*-------------------------------------------------------------------------*/
          
#endif /* GUCEF_VFS_CVFS_H ? */

/*-------------------------------------------------------------------------//
//                                                                         //
//      Info & Changes                                                     //
//                                                                         //
//-------------------------------------------------------------------------//

- 03-05-2008 :
        - Dinand: Reworked the VFS system to support a mounting system that
          groups resources in archives that become part of the resource tree in
          a transparent manner. This rework allows the VFS plugins to become 
          operational again as archive factories.
- 24-08-2005 :
        - Dinand: implemented GetNewFile()
        - Dinand: reworked the AddRoot() and root administration mechanisms. This allows
          support for writeable roots and storage of the relative paths without
          data duplication.
        - Dinand: Added support for new writeable files (exclusive access only)
        - Dinand: Added support for read & write files (exclusive access only)
- 18-05-2005 :
        - Dinand: Fixed a bug in FileExists(): If the recource didn't exist the code would get
          stuck in a loop.
- 01-05-2005 :
        - Dinand: Fixed array bounds write violation in LoadFromDiskCache()
        - Dinand: Fixed a bug in Unload(): The last cached item's access object was
          deleted twice.
        - Dinand: Unload() no longer has to search for the handle entry saving us some time           
- 26-04-2005 :
        - Dinand: Fixed a bug in LoadFromDisk(): file information storage accessed an
          invalid heap entry if no storage space was available.
        - Dinand: Fixed a bug in Unload(): The last cached item's access object was
          deleted twice.  
- 12-02-2005 :
        - Dinand: Initial implementation

-----------------------------------------------------------------------------*/
