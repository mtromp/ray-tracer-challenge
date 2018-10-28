add_library(canvas SHARED "")

target_sources(
  canvas
  PRIVATE
    src/canvas.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include/canvas.h
  )

target_include_directories(
  canvas
  PUBLIC
    include
  )

target_link_libraries(
    canvas
    PRIVATE
        tuple
    )
