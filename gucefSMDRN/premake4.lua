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

-- Configuration for module: gucefSMDRN


project( "gucefSMDRN" )
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
links( { "gucefCOM", "gucefCOMCORE", "gucefCORE", "gucefDRN", "gucefMT" } )
links( { "gucefCOM", "gucefCOMCORE", "gucefCORE", "gucefDRN", "gucefMT" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "include/gucefSMDRN.h",
  "include/gucefSMDRN_CISectorObject.h",
  "include/gucefSMDRN_CModule.h",
  "include/gucefSMDRN_config.h",
  "include/gucefSMDRN_CSector.h",
  "include/gucefSMDRN_CSectorGrid.h",
  "include/gucefSMDRN_CSectorPosition.h",
  "include/gucefSMDRN_CSectorSegment.h",
  "include/gucefSMDRN_CSectorVector.h",
  "include/gucefSMDRN_CZone.h",
  "include/gucefSMDRN_CZoneArbiter.h",
  "include/gucefSMDRN_CZoneClient.h",
  "include/gucefSMDRN_CZoneGrid.h",
  "include/gucefSMDRN_DLLInit.h",
  "include/gucefSMDRN_ETypes.h",
  "include/gucefSMDRN_macros.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/gucefSMDRN_CModule.cpp",
  "src/gucefSMDRN_CSectorGrid.cpp",
  "src/gucefSMDRN_CSectorPosition.cpp",
  "src/gucefSMDRN_CSectorSegment.cpp",
  "src/gucefSMDRN_CZoneArbiter.cpp",
  "src/gucefSMDRN_CZoneClient.cpp",
  "src/gucefSMDRN_CZoneGrid.cpp"
 } )


configuration( {} )
includedirs( { "../common/include", "../gucefCOM/include", "../gucefCOMCORE/include", "../gucefCORE/include", "../gucefDRN/include", "../gucefMT/include", "include" } )

configuration( { "ANDROID" } )
includedirs( { "../gucefCORE/include/android" } )

configuration( { "LINUX" } )
includedirs( { "../gucefCORE/include/linux" } )

configuration( { "WIN32" } )
includedirs( { "../gucefCOMCORE/include/mswin", "../gucefCORE/include/mswin" } )

configuration( { "WIN64" } )
includedirs( { "../gucefCOMCORE/include/mswin", "../gucefCORE/include/mswin" } )
