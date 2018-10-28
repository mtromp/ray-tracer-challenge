add_library( canvasTests SHARED "")

target_sources(
        canvasTests
        PRIVATE
        canvasTest.cpp
)

target_link_libraries(
    canvasTests
    PRIVATE
        canvas
        tuple
        gmock
    )
