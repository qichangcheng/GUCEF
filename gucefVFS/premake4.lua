--------------------------------------------------------------------
-- This file was automatically generated by ProjectGenerator
-- which is tooling part the build system designed for GUCEF
--     (Galaxy Unlimited Framework)
-- For the latest info, see http://www.VanvelzenSoftware.com/
--
-- The contents of this file are placed in the public domain. Feel
-- free to make use of it in any way you like.
--------------------------------------------------------------------
--

-- Configuration for module: gucefVFS


project( "gucefVFS" )
location( os.getenv( "PM4OUTPUTDIR" ) )
kind( "SharedLib" )
links( { "gucefCORE", "gucefMT" } )
links( { "gucefCORE", "gucefMT" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "include/gucefVFS.h",
  "include/gucefVFS_CFileSystemArchive.h",
  "include/gucefVFS_CIArchive.h",
  "include/gucefVFS_CModule.h",
  "include/gucefVFS_config.h",
  "include/gucefVFS_CVFS.h",
  "include/gucefVFS_CVfsGlobal.h",
  "include/gucefVFS_CVFSHandle.h",
  "include/gucefVFS_CVFSURLHandler.h",
  "include/gucefVFS_ETypes.h",
  "include/gucefVFS_macros.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/gucefVFS.cpp",
  "src/gucefVFS_CFileSystemArchive.cpp",
  "src/gucefVFS_CIArchive.cpp",
  "src/gucefVFS_CModule.cpp",
  "src/gucefVFS_CVFS.cpp",
  "src/gucefVFS_CVfsGlobal.cpp",
  "src/gucefVFS_CVFSHandle.cpp",
  "src/gucefVFS_CVFSURLHandler.cpp"
 } )


configuration( {} )
includedirs( { "../common/include", "../gucefCORE/include", "../gucefMT/include", "include" } )

configuration( { "ANDROID" } )
includedirs( { "../gucefCORE/include/android" } )

configuration( { "LINUX" } )
includedirs( { "../gucefCORE/include/linux" } )

configuration( { "WIN32" } )
includedirs( { "../gucefCORE/include/mswin" } )

configuration( { "WIN64" } )
includedirs( { "../gucefCORE/include/mswin" } )
