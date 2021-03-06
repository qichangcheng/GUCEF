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

-- Configuration for module: gucefPATCHERAPP_TestApp


project( "gucefPATCHERAPP_TestApp" )

configuration( {} )
  location( os.getenv( "PM4OUTPUTDIR" ) )

configuration( {} )
  targetdir( os.getenv( "PM4TARGETDIR" ) )

configuration( {} )
language( "C++" )

configuration( { "WIN32" } )


configuration( { WIN32 } )
kind( "WindowedApp" )
configuration( { "NOT WIN32" } )
  

configuration( {} )
kind( "ConsoleApp" )

configuration( {} )
links( { "gucefLOADER" } )
links( { "gucefLOADER" } )


configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/gucefPATCHERAPP_TestApp.cpp"
 } )


configuration( {} )
includedirs( { "../../common/include", "../../gucefCORE/include", "../../gucefCORE/include/", "../../gucefLOADER/include", "../../gucefMT/include" } )

configuration( { "ANDROID" } )
includedirs( { "../../gucefCORE/include/", "../../gucefCORE/include/android" } )

configuration( { "GLX" } )
includedirs( { "../../gucefCORE/include/" } )

configuration( { "GTK" } )
includedirs( { "../../gucefCORE/include/" } )

configuration( { "IPHONEOS" } )
includedirs( { "../../gucefCORE/include/" } )

configuration( { "LINUX" } )
includedirs( { "../../gucefCORE/include/", "../../gucefCORE/include/linux" } )

configuration( { "OSX" } )
includedirs( { "../../gucefCORE/include/" } )

configuration( { "SDL" } )
includedirs( { "../../gucefCORE/include/" } )

configuration( { "SYMBIAN" } )
includedirs( { "../../gucefCORE/include/" } )

configuration( { "UNIX" } )
includedirs( { "../../gucefCORE/include/" } )

configuration( { "WIN32" } )
includedirs( { "../../gucefCORE/include/", "../../gucefCORE/include/mswin" } )

configuration( { "WIN64" } )
includedirs( { "../../gucefCORE/include/", "../../gucefCORE/include/mswin" } )
