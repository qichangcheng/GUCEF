#-------------------------------------------------------------------
# This file was automatically generated by ProjectGenerator
# which is tooling part the build system designed for GUCEF
#     (Galaxy Unlimited Framework)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------
#

# Configuration for module: gucefPATCHERAPP_TestApp

set( SOURCE_FILES 
  src/gucefPATCHERAPP_TestApp.cpp
)

# Make sure the PLATFORM_HEADER_FILES variable is always defined
 set( PLATFORM_HEADER_FILES "" )

# Make sure the PLATFORM_SOURCE_FILES variable is always defined
 set( PLATFORM_SOURCE_FILES "" )

# For ease of use make a variable that has all files for this module
set( ALL_FILES ${HEADER_FILES} ${SOURCE_FILES} ${PLATFORM_HEADER_FILES} ${PLATFORM_SOURCE_FILES} )

set( MODULE_NAME "gucefPATCHERAPP_TestApp" )
if ( WIN32 )
  add_executable( ${MODULE_NAME} WIN32 ${ALL_FILES} )
else()
  add_executable( ${MODULE_NAME} ${ALL_FILES} )
endif()
add_dependencies( ${MODULE_NAME} gucefLOADER )
target_link_libraries( ${MODULE_NAME} gucefLOADER )

include_directories( ../../common/include ../../gucefCORE/include ../../gucefCORE/include/ ../../gucefLOADER/include ../../gucefMT/include ../../gucefMT/include/ )

if ( ANDROID )
  include_directories( ../../gucefCORE/include/ ../../gucefCORE/include/android ../../gucefMT/include/ )
endif( ANDROID )

if ( EMSCRIPTEN )
  include_directories( ../../gucefCORE/include/ ../../gucefMT/include/ )
endif( EMSCRIPTEN )

if ( GLX )
  include_directories( ../../gucefCORE/include/ ../../gucefMT/include/ )
endif( GLX )

if ( GTK )
  include_directories( ../../gucefCORE/include/ ../../gucefMT/include/ )
endif( GTK )

if ( IOS )
  include_directories( ../../gucefCORE/include/ ../../gucefMT/include/ )
endif( IOS )

if ( LINUX32 )
  include_directories( ../../gucefCORE/include/ ../../gucefCORE/include/linux ../../gucefMT/include/ )
endif( LINUX32 )

if ( LINUX64 )
  include_directories( ../../gucefCORE/include/ ../../gucefCORE/include/linux ../../gucefMT/include/ )
endif( LINUX64 )

if ( NACL )
  include_directories( ../../gucefCORE/include/ ../../gucefMT/include/ )
endif( NACL )

if ( OSX )
  include_directories( ../../gucefCORE/include/ ../../gucefMT/include/ )
endif( OSX )

if ( SDL )
  include_directories( ../../gucefCORE/include/ ../../gucefMT/include/ )
endif( SDL )

if ( SYMBIAN )
  include_directories( ../../gucefCORE/include/ ../../gucefMT/include/ )
endif( SYMBIAN )

if ( UNIX )
  include_directories( ../../gucefCORE/include/ ../../gucefMT/include/ )
endif( UNIX )

if ( WIN32 )
  include_directories( ../../gucefCORE/include/ ../../gucefCORE/include/mswin ../../gucefMT/include/ )
endif( WIN32 )

if ( WIN64 )
  include_directories( ../../gucefCORE/include/ ../../gucefCORE/include/mswin ../../gucefMT/include/ )
endif( WIN64 )



#******** START OF AUTOGENERATED TEMPLATED ADDITION CONTENT ********




if (ANDROID)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (EMSCRIPTEN)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (GLX)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (GTK)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (IOS)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (LINUX32)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (LINUX64)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (NACL)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (OSX)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (SDL)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (SYMBIAN)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (UNIX)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (WIN32)
GUCEF_config_tool( ${MODULE_NAME} )
elseif (WIN64)
GUCEF_config_tool( ${MODULE_NAME} )
else()
GUCEF_config_tool( ${MODULE_NAME} )
endif()



#******** END OF AUTOGENERATED TEMPLATED ADDITION CONTENT ********


