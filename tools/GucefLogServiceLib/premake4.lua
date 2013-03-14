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

-- Configuration for module: GucefLogServiceLib


project( "GucefLogServiceLib" )
location( os.getenv( "PM4OUTPUTDIR" ) )

configuration( {} )
language( "C++" )

configuration( { "ANDROID" } )
language( "C" )

configuration( { "LINUX" } )
language( "C" )

configuration( { "OSX" } )
language( "C" )

configuration( { "WIN32" } )
language( "C" )

configuration( { "WIN64" } )
language( "C" )



configuration( {} )
kind( "SharedLib" )

configuration( {} )
links( { "gucefCOM", "gucefCOMCORE", "gucefCORE", "gucefMT" } )
links( { "gucefCOM", "gucefCOMCORE", "gucefCORE", "gucefMT" } )


configuration( {} )
defines( { "GUCEF_LOGSERVICELIB_BUILD_MODULE" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "include/GucefLogServiceLib.h",
  "include/GucefLogServiceLib_CClientInitMessage.h",
  "include/GucefLogServiceLib_CILogSvcServerLogger.h",
  "include/GucefLogServiceLib_CLogSvcClient.h",
  "include/GucefLogServiceLib_CLogSvcServer.h",
  "include/GucefLogServiceLib_CLogSvcServerFileLogger.h",
  "include/GucefLogServiceLib_config.h",
  "include/GucefLogServiceLib_macros.h",
  "include/GucefLogServiceLib_protocol.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/GucefLogServiceLib.cpp",
  "src/GucefLogServiceLib_CClientInitMessage.cpp",
  "src/GucefLogServiceLib_CILogSvcServerLogger.cpp",
  "src/GucefLogServiceLib_CLogSvcClient.cpp",
  "src/GucefLogServiceLib_CLogSvcServer.cpp",
  "src/GucefLogServiceLib_CLogSvcServerFileLogger.cpp"
 } )


configuration( {} )
includedirs( { "../../common/include", "../../gucefCOM/include", "../../gucefCOMCORE/include", "../../gucefCORE/include", "../../gucefMT/include", "include" } )

configuration( { "ANDROID" } )
includedirs( { "../../gucefCORE/include/android" } )

configuration( { "LINUX" } )
includedirs( { "../../gucefCORE/include/linux" } )

configuration( { "WIN32" } )
includedirs( { "../../gucefCOMCORE/include/mswin", "../../gucefCORE/include/mswin" } )

configuration( { "WIN64" } )
includedirs( { "../../gucefCOMCORE/include/mswin", "../../gucefCORE/include/mswin" } )
