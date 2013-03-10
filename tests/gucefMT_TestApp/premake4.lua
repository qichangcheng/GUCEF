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

-- Configuration for module: gucefMT_TestApp


project( "gucefMT_TestApp" )
location( os.getenv( "PM4OUTPUTDIR" ) )
configuration( { "WIN32" } )
kind( "WindowedApp" )
configuration( { "NOT WIN32" } )
  kind( "ConsoleApp" )
links( { "gucefMT" } )
links( { "gucefMT" } )


configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/gucefMT_TestApp.cpp"
 } )


configuration( {} )
includedirs( { "../../common/include", "../../gucefMT/include" } )
