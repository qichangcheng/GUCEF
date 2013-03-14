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

-- Configuration for module: ProjectGenerator


project( "ProjectGenerator" )
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

configuration( { "WIN32" } )


configuration( { WIN32 } )
kind( "WindowedApp" )
configuration( { "NOT WIN32" } )
  

configuration( {} )
kind( "ConsoleApp" )

configuration( {} )
links( { "gucefCORE", "gucefMT" } )
links( { "gucefCORE", "gucefMT" } )


configuration( {} )
vpaths { ["Headers"] = { "**.h", "**.hpp", "**.hxx" } }
files( {
  "include/gucefProjectGenerator_CAndroidMakefileGenerator.h",
  "include/gucefProjectGenerator_CCMakeProjectGenerator.h",
  "include/gucefProjectGenerator_CDirCrawlingProjectInfoGatherer.h",
  "include/gucefProjectGenerator_CIProjectGenerator.h",
  "include/gucefProjectGenerator_CIProjectInfoGatherer.h",
  "include/gucefProjectGenerator_CPremake4ProjectGenerator.h",
  "include/gucefProjectGenerator_CXmlProjectGenerator.h",
  "include/gucefProjectGenerator_DataTypes.h"
 } )



configuration( {} )
vpaths { ["Source"] = { "**.c", "**.cpp", "**.cs", "**.asm" } }
files( {
  "src/gucefProjectGenerator_CAndroidMakefileGenerator.cpp",
  "src/gucefProjectGenerator_CCMakeProjectGenerator.cpp",
  "src/gucefProjectGenerator_CDirCrawlingProjectInfoGatherer.cpp",
  "src/gucefProjectGenerator_CIProjectGenerator.cpp",
  "src/gucefProjectGenerator_CIProjectInfoGatherer.cpp",
  "src/gucefProjectGenerator_CPremake4ProjectGenerator.cpp",
  "src/gucefProjectGenerator_CXmlProjectGenerator.cpp",
  "src/gucefProjectGenerator_DataTypes.cpp",
  "src/main.cpp"
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
