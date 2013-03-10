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

-- Configuration for module: gucefCORE_TestApp


project( "gucefCORE_TestApp" )
location( os.getenv( "PM4OUTPUTDIR" ) )
configuration( { "WIN32" } )
kind( "WindowedApp" )
configuration( { "NOT WIN32" } )
  kind( "ConsoleApp" )
links( { "gucefCORE", "gucefMT" } )
links( { "gucefCORE", "gucefMT" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "include/TestCyclicDynamicBuffer.h",
  "include/TestIniParser.h",
  "include/TestNotifierObserver.h",
  "include/TestSharedPtr.h",
  "include/TestString.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/gucefCORE_TestApp_main.cpp",
  "src/TestCyclicDynamicBuffer.cpp",
  "src/TestIniParser.cpp",
  "src/TestNotifierObserver.cpp",
  "src/TestSharedPtr.cpp",
  "src/TestString.cpp"
 } )


configuration( {} )
includedirs( { "../../common/include", "../../gucefCORE/include", "../../gucefMT/include", "include" } )

configuration( { "ANDROID" } )
includedirs( { "../../gucefCORE/include/android" } )

configuration( { "LINUX" } )
includedirs( { "../../gucefCORE/include/linux" } )

configuration( { "WIN32" } )
includedirs( { "../../gucefCORE/include/mswin" } )

configuration( { "WIN64" } )
includedirs( { "../../gucefCORE/include/mswin" } )
