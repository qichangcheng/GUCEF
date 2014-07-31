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

-- Configuration for module: gucefLOADER


project( "gucefLOADER" )
location( os.getenv( "PM4OUTPUTDIR" ) )

configuration( {} )
language( "C++" )



configuration( {} )
kind( "SharedLib" )

configuration( {} )
links( { "gucefCORE", "gucefMT" } )


configuration( {} )
defines( { "GUCEF_CORE_EMBED_CODE", "GUCEF_LOADER_BUILD_MODULE", "GUCEF_MT_EMBED_CODE", "GUCEF_NO_LOGGING" } )
  links( { "dl", "log" } )
  links( { "dl", "rt" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "../gucefCORE/include/DVOSWRAP.h",
  "../gucefCORE/include/dvstrutils.h",
  "../gucefCORE/include/CDVString.h",
  "../gucefCORE/include/dvfileutils.h",
  "../gucefCORE/include/dvcppstringutils.h",
  "../gucefCORE/include/md5.h",
  "../gucefCORE/include/dvmd5utils.h",
  "include/gucefLOADER.h",
  "include/gucefLOADER_config.h",
  "include/gucefLOADER_ETypes.h",
  "include/gucefLOADER_macros.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "../gucefCORE/src/DVOSWRAP.cpp",
  "../gucefCORE/src/dvstrutils.c",
  "../gucefCORE/src/CDVString.cpp",
  "../gucefCORE/src/dvfileutils.c",
  "../gucefCORE/src/dvcppstringutils.cpp",
  "../gucefCORE/src/md5.c",
  "../gucefCORE/src/dvmd5utils.c",
  "src/gucefLOADER.cpp"
 } )



configuration( { "ANDROID" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )



configuration( { "GLX" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )



configuration( { "GTK" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )



configuration( { "IPHONEOS" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )



configuration( { "LINUX" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )



configuration( { "OSX" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )



configuration( { "SDL" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )



configuration( { "SYMBIAN" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )



configuration( { "UNIX" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )



configuration( { "WIN32" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )



configuration( { "WIN64" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "../gucefCORE/include/DVOSWRAP.h",
      "../gucefCORE/include/dvstrutils.h",
      "../gucefCORE/include/CDVString.h",
      "../gucefCORE/include/dvfileutils.h",
      "../gucefCORE/include/dvcppstringutils.h",
      "../gucefCORE/include/md5.h",
      "../gucefCORE/include/dvmd5utils.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "../gucefCORE/src/DVOSWRAP.cpp",
      "../gucefCORE/src/dvstrutils.c",
      "../gucefCORE/src/CDVString.cpp",
      "../gucefCORE/src/dvfileutils.c",
      "../gucefCORE/src/dvcppstringutils.cpp",
      "../gucefCORE/src/md5.c",
      "../gucefCORE/src/dvmd5utils.c"
    } )


configuration( {} )
includedirs( { "../common/include", "../gucefCORE/include", "../gucefMT/include", "../gucefCORE/include/", "include" } )

configuration( { "ANDROID" } )
includedirs( { "../gucefCORE/include/android", "../gucefCORE/include/" } )

configuration( { "GLX" } )
includedirs( { "../gucefCORE/include/" } )

configuration( { "GTK" } )
includedirs( { "../gucefCORE/include/" } )

configuration( { "IPHONEOS" } )
includedirs( { "../gucefCORE/include/" } )

configuration( { "LINUX" } )
includedirs( { "../gucefCORE/include/linux", "../gucefCORE/include/" } )

configuration( { "OSX" } )
includedirs( { "../gucefCORE/include/" } )

configuration( { "SDL" } )
includedirs( { "../gucefCORE/include/" } )

configuration( { "SYMBIAN" } )
includedirs( { "../gucefCORE/include/" } )

configuration( { "UNIX" } )
includedirs( { "../gucefCORE/include/" } )

configuration( { "WIN32" } )
includedirs( { "../gucefCORE/include/mswin", "../gucefCORE/include/" } )

configuration( { "WIN64" } )
includedirs( { "../gucefCORE/include/mswin", "../gucefCORE/include/" } )