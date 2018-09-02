# ##########################################
SET( INCLUDE_DIRS
        ${CMAKE_CURRENT_LIST_DIR}/include
)
INCLUDE_DIRECTORIES( ${INCLUDE_DIRS} )


# ##########################################
SET( INCLUDE_FILES
        include/tuples.h
        include/point.h
        include/vector.h
)

# ##########################################
SET( SOURCE_FILES
        src/tuples.cpp
        src/point.cpp
        src/vector.cpp
)

# ##########################################
ADD_LIBRARY( tuples
        SHARED
        ${INCLUDE_FILES}
        ${SOURCE_FILES}
)

# ##########################################
# enable unit test building and running

ADD_EXECUTABLE( tuplesTests
        tests/main.cpp
        tests/tuplesTest.cpp
)
TARGET_LINK_LIBRARIES( tuplesTests
        tuples
        gmock
)

ADD_TEST( NAME
        tuplesTests
        COMMAND
        tuplesTests
)


