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

-- Configuration for module: gucefPATCHERAPP


project( "gucefPATCHERAPP" )
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
links( { "gucefCOM", "gucefCOMCORE", "gucefCORE", "gucefGUI", "gucefIMAGE", "gucefINPUT", "gucefMT", "gucefPATCHER" } )
links( { "gucefCOM", "gucefCOMCORE", "gucefCORE", "gucefGUI", "gucefIMAGE", "gucefINPUT", "gucefMT", "gucefPATCHER" } )


configuration( {} )
defines( { "GUCEF_PATCHERAPP_BUILD_MODULE" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "include/gucefPATCHERAPP_CMainPatcherAppLogic.h",
  "include/gucefPATCHERAPP_config.h",
  "include/gucefPATCHERAPP_CPatcherAppConfig.h",
  "include/gucefPATCHERAPP_CPatcherAppGlobal.h",
  "include/gucefPATCHERAPP_macros.h",
  "include/gucefPATCHERAPP_main.h",
  "include/gucefPATCHERAPP_SimpleTypes.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/gucefPATCHERAPP_CMainPatcherAppLogic.cpp",
  "src/gucefPATCHERAPP_CPatcherAppConfig.cpp",
  "src/gucefPATCHERAPP_CPatcherAppGlobal.cpp",
  "src/gucefPATCHERAPP_main.cpp"
 } )


configuration( {} )
includedirs( { "../../common/include", "../../gucefCOM/include", "../../gucefCOMCORE/include", "../../gucefCORE/include", "../../gucefGUI/include", "../../gucefIMAGE/include", "../../gucefINPUT/include", "../../gucefMT/include", "../../gucefPATCHER/include", "../../gucefVFS/include", "include" } )

configuration( { "ANDROID" } )
includedirs( { "../../gucefCORE/include/android" } )

configuration( { "LINUX" } )
includedirs( { "../../gucefCORE/include/linux" } )

configuration( { "WIN32" } )
includedirs( { "../../gucefCOMCORE/include/mswin", "../../gucefCORE/include/mswin" } )

configuration( { "WIN64" } )
includedirs( { "../../gucefCOMCORE/include/mswin", "../../gucefCORE/include/mswin" } )
