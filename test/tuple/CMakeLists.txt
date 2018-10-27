# ##########################################
# enable unit test building and running

add_library( tupleTests SHARED "")

target_sources(
        tupleTests
        PRIVATE
        colorTest.cpp
        tupleTest.cpp
        tupleMathTest.cpp
        vectorMathTest.cpp
)

target_link_libraries(
    tupleTests
    PRIVATE
        tuple
        gmock
    )


