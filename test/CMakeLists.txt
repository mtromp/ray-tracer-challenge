add_executable( libraryTests "" )

add_subdirectory( tuple )

target_sources(
    libraryTests
    PRIVATE
        main.cpp
    )

target_link_libraries(
    libraryTests
    PRIVATE
        tuple
        tupleTests
        gmock
    )

add_test( libraryTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/libraryTests)
