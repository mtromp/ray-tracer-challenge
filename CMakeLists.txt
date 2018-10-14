# ###############################################
# Check for a valid version of CMake.
CMAKE_MINIMUM_REQUIRED( VERSION 2.8.3 )

# ###############################################
# Start the project.
PROJECT( RayTracerChallenge )

# ##########################################
# get rid of policy CMP0042 warning on Mac
SET ( CMAKE_MACOSX_RPATH 1 )

# ###############################################
# Find the threading package for this machine.
# Needed by gtest
FIND_PACKAGE( Threads )

enable_testing()
### Would like let cmake know were gtest is located
###   apparently that will allow ctest to run
###   tests that have been ADD_TEST defined.
### FIND_PACKAGE( GTest REQUIRED )

# ###############################################
# Include the external CMakeLists.txt so that
#   only that file need be modified when new
#   external tools are added
INCLUDE( external/CMakeLists.txt )


# ###############################################
# Include the libraries CMakeLists.txt so that
#   only that file need be modified when new
#   libraries are added
INCLUDE( libraries/CMakeLists.txt )

# ###############################################
# Include the application CMakeLists.txt so that
#   only that file need be modified when new
#   application files are added

INCLUDE( application/CMakeLists.txt )

TARGET_INCLUDE_DIRECTORIES( tuple PUBLIC libraries/tuple/include)

