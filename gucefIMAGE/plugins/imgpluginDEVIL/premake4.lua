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

-- Configuration for module: imgpluginDEVIL


configuration( { "LINUX" } )
  project( "imgpluginDEVIL" )

configuration( { "WIN32" } )
  project( "imgpluginDEVIL" )

configuration( { "WIN64" } )
  project( "imgpluginDEVIL" )
location( os.getenv( "PM4OUTPUTDIR" ) )
configuration( { "LINUX" } )
kind( "SharedLib" )
configuration( { "WIN32" } )
kind( "SharedLib" )
configuration( { "WIN64" } )
kind( "SharedLib" )

configuration( { "LINUX" } )
  links( { "DevIL", "gucefCORE", "gucefMT" } )
  links( { "DevIL", "gucefCORE", "gucefMT" } )
  defines( { "GUCEF_CODECPLUGIN_BUILD_MODULE" } )

configuration( { "WIN32" } )
  links( { "DevIL", "gucefCORE", "gucefMT" } )
  links( { "DevIL", "gucefCORE", "gucefMT" } )
  defines( { "GUCEF_CODECPLUGIN_BUILD_MODULE" } )

configuration( { "WIN64" } )
  links( { "DevIL", "gucefCORE", "gucefMT" } )
  links( { "DevIL", "gucefCORE", "gucefMT" } )
  defines( { "GUCEF_CODECPLUGIN_BUILD_MODULE" } )


configuration( { "LINUX" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "include\imgpluginDEVIL.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "src\imgpluginDEVIL.c"
    } )



configuration( { "WIN32" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "include\imgpluginDEVIL.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "src\imgpluginDEVIL.c"
    } )



configuration( { "WIN64" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "include\imgpluginDEVIL.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "src\imgpluginDEVIL.c"
    } )


configuration( {} )
includedirs( { "../../../common/include", "../../../gucefCORE/include", "../../../gucefMT/include" } )

configuration( { "LINUX" } )
includedirs( { "../../../gucefCORE/include/linux", "include" } )

configuration( { "WIN32" } )
includedirs( { "../../../gucefCORE/include/mswin", "include" } )

configuration( { "WIN64" } )
includedirs( { "../../../gucefCORE/include/mswin", "include" } )
