add_executable( libraryTests "" )

add_subdirectory( tuple )
add_subdirectory( canvas )
add_subdirectory( matrix )

target_sources(
    libraryTests
    PRIVATE
        main.cpp
    )

target_link_libraries(
    libraryTests
    PRIVATE
        canvas
        canvasTests
        tuple
        tupleTests
        matrix
        matrixTests
        gmock
    )

add_test( libraryTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/libraryTests)
