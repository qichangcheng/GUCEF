CALL CMakeCommon.bat

ECHO *** Set MVC14 specifics and run CMake ***

SET MVC14_OUTPUTDIR="%OUTPUTDIR%\MVC14ARM"
CMake.exe -DBUILD_SHARED_LIBS=ON -G"Visual Studio 14 2015 ARM" -H"%SRCROOTDIR%" -B%MVC14_OUTPUTDIR%
PAUSE