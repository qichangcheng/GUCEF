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


solution( "GUCEF" )

  configurations( { "ANDROID", "GLX", "GTK", "IPHONEOS", "LINUX", "OSX", "SDL", "SYMBIAN", "UNIX", "WIN32", "WIN64" } )

  location( os.getenv( "PM4OUTPUTDIR" ) )

  --
  -- Includes for all modules in the solution:
  --
  include( "apps/gucefPATCHERAPP" )
  include( "apps/gucefPRODMANAPP" )
  include( "dependencies/FreeImage" )
  include( "dependencies/freetype" )
  include( "dependencies/libRocket/Source/Controls" )
  include( "dependencies/libRocket/Source/Core" )
  include( "dependencies/libRocket/Source/Debugger" )
  include( "dependencies/miniupnpc" )
  include( "dependencies/MyGui/MyGUIEngine" )
  include( "dependencies/MyGui/Platforms/Ogre/OgrePlatform" )
  include( "dependencies/MyGui/Platforms/OpenGL/OpenGLPlatform" )
  include( "dependencies/MyGui/Tools/FontViewer" )
  include( "dependencies/MyGui/Tools/ImageSetViewer" )
  include( "dependencies/MyGui/Tools/LayoutEditor" )
  include( "dependencies/MyGui/Tools/SkinEditor" )
  include( "dependencies/uuid" )
  include( "dependencies/zlib" )
  include( "dependencies/zziplib" )
  include( "gucefANDROIDGLUE/Gingerbread/jni" )
  include( "gucefCOM" )
  include( "gucefCOMCORE" )
  include( "gucefCORE" )
  include( "gucefCORE/plugins/dstorepluginPARSIFALXML" )
  include( "gucefCORE/plugins/dstorepluginPARSIFALXML/dependancy/libparsifal" )
  include( "gucefDRN" )
  include( "gucefGUI" )
  include( "gucefGUI/plugins/guidriverAndroidGLES" )
  include( "gucefGUI/plugins/guidriverMyGUI" )
  include( "gucefGUI/plugins/guidriverMyGUIOpenGL" )
  include( "gucefGUI/plugins/guidriverMyGUIOpenGL/OpenGLESPlatform" )
  include( "gucefGUI/plugins/guidriverRocket" )
  include( "gucefGUI/plugins/guidriverRocketOpenGL" )
  include( "gucefGUI/plugins/guidriverWin32GL" )
  include( "gucefGUI/plugins/guidriverXWinGL" )
  include( "gucefIMAGE" )
  include( "gucefIMAGE/plugins/imgpluginDEVIL" )
  include( "gucefIMAGE/plugins/imgpluginFreeImage" )
  include( "gucefINPUT" )
  include( "gucefINPUT/plugins/inputdriverDIRECTINPUT8" )
  include( "gucefINPUT/plugins/inputdriverMSWINMSG" )
  include( "gucefINPUT/plugins/inputdriverNANDROID" )
  include( "gucefINPUT/plugins/inputdriverOIS" )
  include( "gucefINPUT/plugins/inputdriverOIS/dependency/OIS" )
  include( "gucefINPUT/plugins/inputdriverXWINMSG" )
  include( "gucefLOADER" )
  include( "gucefMATH" )
  include( "gucefMT" )
  include( "gucefMULTIPLAY" )
  include( "gucefPATCHER" )
  include( "gucefPRODMAN" )
  include( "gucefSMDRN" )
  include( "gucefVFS" )
  include( "gucefVFS/plugins/vfspluginDVP" )
  include( "gucefVFS/plugins/vfspluginDVP/dependencies/DVPACKSYS" )
  include( "gucefVFS/plugins/vfspluginVP" )
  include( "gucefVFS/plugins/vfspluginZIP" )
  include( "tests/gucefCOMCORE_TestApp" )
  include( "tests/gucefCOM_TestApp" )
  include( "tests/gucefCORE_TestApp" )
  include( "tests/gucefDRN_TestApp" )
  include( "tests/gucefGUI_TestApp" )
  include( "tests/gucefIMAGE_TestApp" )
  include( "tests/gucefINPUT_TestApp" )
  include( "tests/gucefLOADER_TestApp" )
  include( "tests/gucefMT_TestApp" )
  include( "tests/gucefPRODMAN_TestApp" )
  include( "tools/ArchiveDiff" )
  include( "tools/ArchiveDiffLib" )
  include( "tools/CMakeListGenerator" )
  include( "tools/DuplicateFileFinder" )
  include( "tools/DVPPackTool" )
  include( "tools/FileDiff" )
  include( "tools/FileReplacer" )
  include( "tools/GucefLogServiceApp" )
  include( "tools/GucefLogServiceClientPlugin" )
  include( "tools/GucefLogServiceLib" )
  include( "tools/GucefLogService_TestApp" )
  include( "tools/HDFiller" )
  include( "tools/MemoryLeakFinder" )
  include( "tools/PatcherGUI/MFCPatcherGUI" )
  include( "tools/PatchSetGenerator" )
  include( "tools/ProjectGenerator" )
  include( "tools/ReferenceUpdater" )
  include( "tools/ServerPortExtender" )
  include( "tools/SVNMagicMerge" )
