# ##########################################
SET( INCLUDE_DIRS
        ${CMAKE_CURRENT_LIST_DIR}/include
)
INCLUDE_DIRECTORIES( ${INCLUDE_DIRS} )


# ##########################################
SET( INCLUDE_FILES
        include/tuple.h
        include/point.h
        include/vector.h
)

# ##########################################
SET( SOURCE_FILES
        src/tuple.cpp
        src/point.cpp
        src/vector.cpp
)

# ##########################################
ADD_LIBRARY( tuple
        SHARED
        ${INCLUDE_FILES}
        ${SOURCE_FILES}
)

# ##########################################
# enable unit test building and running

ADD_EXECUTABLE( tupleTests
        test/main.cpp
        test/tupleTest.cpp
        test/tupleMathTest.cpp
)
TARGET_LINK_LIBRARIES( tupleTests
        tuple
        gmock
)

ADD_TEST( NAME
        tupleTests
        COMMAND
        tupleTests
)


