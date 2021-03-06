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

# Configuration for module: lcms2

set( HEADER_FILES 
  include/lcms.h
  include/lcms2.h
  include/lcms2_plugin.h
  src/lcms2_internal.h
)

set( SOURCE_FILES 
  src/cmsalpha.c
  src/cmscam02.c
  src/cmscgats.c
  src/cmscnvrt.c
  src/cmserr.c
  src/cmsgamma.c
  src/cmsgmt.c
  src/cmshalf.c
  src/cmsintrp.c
  src/cmsio0.c
  src/cmsio1.c
  src/cmslut.c
  src/cmsmd5.c
  src/cmsmtrx.c
  src/cmsnamed.c
  src/cmsopt.c
  src/cmspack.c
  src/cmspcs.c
  src/cmsplugin.c
  src/cmsps2.c
  src/cmssamp.c
  src/cmssm.c
  src/cmstypes.c
  src/cmsvirt.c
  src/cmswtpnt.c
  src/cmsxform.c
)

# Make sure the PLATFORM_HEADER_FILES variable is always defined
 set( PLATFORM_HEADER_FILES "" )

# Make sure the PLATFORM_SOURCE_FILES variable is always defined
 set( PLATFORM_SOURCE_FILES "" )

# For ease of use make a variable that has all files for this module
set( ALL_FILES ${HEADER_FILES} ${SOURCE_FILES} ${PLATFORM_HEADER_FILES} ${PLATFORM_SOURCE_FILES} )

set( MODULE_NAME "lcms2" )
add_library( ${MODULE_NAME} ${ALL_FILES} )
set_property( TARGET ${MODULE_NAME} APPEND_STRING PROPERTY COMPILE_DEFINITIONS "CMS_DLL_BUILD" )

if ( WIN32 )
  set_property( TARGET ${MODULE_NAME} APPEND_STRING PROPERTY COMPILE_DEFINITIONS "CMS_RELY_ON_WINDOWS_STATIC_MUTEX_INIT" )
endif( WIN32 )

if ( WIN64 )
  set_property( TARGET ${MODULE_NAME} APPEND_STRING PROPERTY COMPILE_DEFINITIONS "CMS_RELY_ON_WINDOWS_STATIC_MUTEX_INIT" )
endif( WIN64 )

include_directories( include src )



#******** START OF AUTOGENERATED TEMPLATED ADDITION CONTENT ********




if (LINUX32)
GUCEF_config_lib( ${MODULE_NAME} )
elseif (LINUX64)
GUCEF_config_lib( ${MODULE_NAME} )
elseif (WIN32)
GUCEF_config_lib( ${MODULE_NAME} )
elseif (WIN64)
GUCEF_config_lib( ${MODULE_NAME} )
else()
GUCEF_config_lib( ${MODULE_NAME} )
endif()



#******** END OF AUTOGENERATED TEMPLATED ADDITION CONTENT ********


