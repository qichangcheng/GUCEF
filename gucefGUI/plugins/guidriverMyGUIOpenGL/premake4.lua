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

-- Configuration for module: guidriverMyGUIOpenGL


project( "guidriverMyGUIOpenGL" )
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
links( { "MyGUI.Engine", "freetype", "gucefCORE", "gucefGUI", "gucefIMAGE", "gucefINPUT", "gucefMT", "gucefVFS", "guidriverMyGUI" } )
links( { "MyGUI.Engine", "freetype", "gucefCORE", "gucefGUI", "gucefIMAGE", "gucefINPUT", "gucefMT", "gucefVFS", "guidriverMyGUI" } )


configuration( {} )
defines( { "GUIDRIVERMYGUIOPENGL_BUILD_MODULE" } )

configuration( { "ANDROID" } )
  
configuration( { ANDROID } )
links( { "MyGUI.OpenGLESPlatform" } )
  links( { "GLESv1_CM", "MyGUI.OpenGLESPlatform" } )

configuration( { "LINUX" } )
  
configuration( { LINUX } )
links( { "MyGUI.OpenGLPlatform" } )
  links( { "GL", "MyGUI.OpenGLPlatform" } )

configuration( { "WIN32" } )
  
configuration( { WIN32 } )
links( { "MyGUI.OpenGLPlatform" } )
  links( { "MyGUI.OpenGLPlatform", "OpenGL32" } )

configuration( { "WIN64" } )
  
configuration( { WIN64 } )
links( { "MyGUI.OpenGLPlatform" } )
  links( { "MyGUI.OpenGLPlatform", "OpenGL32" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "include/guidriverMyGUIOpenGL.h",
  "include/guidriverMyGUIOpenGL_CGUIContextGL.h",
  "include/guidriverMyGUIOpenGL_CGUIDriverGL.h",
  "include/guidriverMyGUIOpenGL_CImageLoader.h",
  "include/guidriverMyGUIOpenGL_config.h",
  "include/guidriverMyGUIOpenGL_macros.h",
  "include/guidriverMyGUIOpenGL_pluginAPI.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/guidriverMyGUIOpenGL.cpp",
  "src/guidriverMyGUIOpenGL_CGUIContextGL.cpp",
  "src/guidriverMyGUIOpenGL_CGUIDriverGL.cpp",
  "src/guidriverMyGUIOpenGL_CImageLoader.cpp",
  "src/guidriverMyGUIOpenGL_pluginAPI.cpp"
 } )


configuration( {} )
includedirs( { "../../../common/include", "../../../dependencies/MyGui/MyGUIEngine/include", "../../../dependencies/freetype/include", "../../../dependencies/freetype/include/freetype", "../../../dependencies/freetype/include/freetype/config", "../../../dependencies/freetype/include/freetype/internal", "../../../dependencies/freetype/include/freetype/internal/services", "../../../dependencies/freetype/src/winfonts", "../../../gucefCORE/include", "../../../gucefGUI/include", "../../../gucefIMAGE/include", "../../../gucefINPUT/include", "../../../gucefMT/include", "../../../gucefVFS/include", "../guidriverMyGUI/include", "include" } )

configuration( { "ANDROID" } )
includedirs( { "../../../dependencies/MyGui/Common/FileSystemInfo", "../../../gucefCORE/include/android", "OpenGLESPlatform/include" } )

configuration( { "LINUX" } )
includedirs( { "../../../gucefCORE/include/linux" } )

configuration( { "WIN32" } )
includedirs( { "../../../gucefCORE/include/mswin" } )

configuration( { "WIN64" } )
includedirs( { "../../../gucefCORE/include/mswin" } )
