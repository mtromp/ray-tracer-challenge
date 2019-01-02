add_library( matrixTests SHARED "")

target_sources(
        matrixTests
        PRIVATE
        matrixTest.cpp
)

target_link_libraries(
    matrixTests
    PRIVATE
        matrix
        tuple
        gmock
    )
