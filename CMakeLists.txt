# ###############################################
# Check for a valid version of CMake.
cmake_minimum_required( VERSION 3.0 FATAL_ERROR )

#[==[
 20181027: reworking with modern cmake conventions
    Search for Daniel Pfeiffer's presentaions on
    effective cmake.
#]==]

# ###############################################
# Start the project.
project( RayTracerChallenge )

# ##########################################
# get rid of policy CMP0042 warning on Mac
set ( CMAKE_MACOSX_RPATH 1 )

# enable the C++ 17 std libraries
set (CMAKE_CXX_FLAGS "-std=c++1z")

# ###############################################
# Find the threading package for this machine.
# Needed by gtest
find_package( Threads )

### Would like let cmake know were gtest is located
###   apparently that will allow ctest to run
###   tests that have been ADD_TEST defined.
### FIND_PACKAGE( GTest REQUIRED )

# ###############################################
# Include the external CMakeLists.txt so that
#   only that file need be modified when new
#   external tools are added
include( external/CMakeLists.txt )

include(GoogleTest)


# ###############################################
# Include the libraries CMakeLists.txt so that
#   only that file need be modified when new
#   libraries are added
add_subdirectory( libraries )

# ###############################################
# Include the application CMakeLists.txt so that
#   only that file need be modified when new
#   application files are added

add_subdirectory( application )

enable_testing()

add_subdirectory( test )

