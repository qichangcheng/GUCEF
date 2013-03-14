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

-- Configuration for module: zlib


configuration( { "LINUX" } )
  project( "zlib" )

configuration( { "WIN32" } )
  project( "zlib" )

configuration( { "WIN64" } )
  project( "zlib" )
location( os.getenv( "PM4OUTPUTDIR" ) )

configuration( { "LINUX" } )
language( "C" )

configuration( { "WIN32" } )
language( "C" )

configuration( { "WIN64" } )
language( "C" )

configuration( { "LINUX" } )


configuration( { LINUX } )
kind( "SharedLib" )
configuration( { "WIN32" } )


configuration( { WIN32 } )
kind( "SharedLib" )
configuration( { "WIN64" } )


configuration( { WIN64 } )
kind( "SharedLib" )

configuration( { "LINUX" } )
  

configuration( { LINUX } )
defines( { "ZLIB_DLL", "ZLIB_INTERNAL", "ZZIP_HAVE_STDINT_H" } )

configuration( { "WIN32" } )
  

configuration( { WIN32 } )
defines( { "ZLIB_DLL", "ZLIB_INTERNAL", "ZZIP_HAVE_STDINT_H" } )

configuration( { "WIN64" } )
  

configuration( { WIN64 } )
defines( { "ZLIB_DLL", "ZLIB_INTERNAL", "ZZIP_HAVE_STDINT_H" } )


configuration( { "LINUX" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "crc32.h",
      "deflate.h",
      "inffast.h",
      "inffixed.h",
      "inflate.h",
      "inftrees.h",
      "trees.h",
      "zconf.h",
      "zconf.in.h",
      "zlib.h",
      "zutil.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "adler32.c",
      "compress.c",
      "crc32.c",
      "deflate.c",
      "gzio.c",
      "infback.c",
      "inffast.c",
      "inflate.c",
      "inftrees.c",
      "trees.c",
      "uncompr.c",
      "zutil.c"
    } )



configuration( { "WIN32" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "crc32.h",
      "deflate.h",
      "inffast.h",
      "inffixed.h",
      "inflate.h",
      "inftrees.h",
      "trees.h",
      "zconf.h",
      "zconf.in.h",
      "zlib.h",
      "zutil.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "adler32.c",
      "compress.c",
      "crc32.c",
      "deflate.c",
      "gzio.c",
      "infback.c",
      "inffast.c",
      "inflate.c",
      "inftrees.c",
      "trees.c",
      "uncompr.c",
      "zutil.c"
    } )



configuration( { "WIN64" } )
    vpaths { ["Platform Headers"] = { "**.h", "**.hpp", "**.hxx" } }
    files( {
      "crc32.h",
      "deflate.h",
      "inffast.h",
      "inffixed.h",
      "inflate.h",
      "inftrees.h",
      "trees.h",
      "zconf.h",
      "zconf.in.h",
      "zlib.h",
      "zutil.h"
    } )

    vpaths { ["Platform Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
    files( {
      "adler32.c",
      "compress.c",
      "crc32.c",
      "deflate.c",
      "gzio.c",
      "infback.c",
      "inffast.c",
      "inflate.c",
      "inftrees.c",
      "trees.c",
      "uncompr.c",
      "zutil.c"
    } )

