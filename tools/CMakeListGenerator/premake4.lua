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

-- Configuration for module: CMakeListGenerator


configuration( { "LINUX" } )
  project( "CMakeListGenerator" )

configuration( { "WIN32" } )
  project( "CMakeListGenerator" )

configuration( { "WIN64" } )
  project( "CMakeListGenerator" )
location( os.getenv( "PM4OUTPUTDIR" ) )
configuration( { "LINUX" } )
kind( "ConsoleApp" )
configuration( { "WIN32" } )
kind( "WindowedApp" )
configuration( { "WIN64" } )
kind( "WindowedApp" )

configuration( { "LINUX" } )
  links( { "gucefCORE", "gucefMT" } )
  links( { "gucefCORE", "gucefMT" } )
  defines( { "CMAKELISTGENERATOR_BUILD_MODULE" } )

configuration( { "WIN32" } )
  links( { "gucefCORE", "gucefMT" } )
  links( { "gucefCORE", "gucefMT" } )
  defines( { "CMAKELISTGENERATOR_BUILD_MODULE" } )

configuration( { "WIN64" } )
  links( { "gucefCORE", "gucefMT" } )
  links( { "gucefCORE", "gucefMT" } )
  defines( { "CMAKELISTGENERATOR_BUILD_MODULE" } )


configuration( { "LINUX" } )
    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "src\main.cpp"
    } )



configuration( { "WIN32" } )
    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "src\main.cpp"
    } )



configuration( { "WIN64" } )
    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "src\main.cpp"
    } )


configuration( {} )
includedirs( { "../../common/include", "../../gucefCORE/include", "../../gucefMT/include" } )

configuration( { "LINUX" } )
includedirs( { "../../gucefCORE/include/linux" } )

configuration( { "WIN32" } )
includedirs( { "../../gucefCORE/include/mswin" } )

configuration( { "WIN64" } )
includedirs( { "../../gucefCORE/include/mswin" } )
