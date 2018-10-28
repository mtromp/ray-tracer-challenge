add_executable( libraryTests "" )

add_subdirectory( tuple )
add_subdirectory( canvas )

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
        gmock
    )

add_test( libraryTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/libraryTests)
