add_library(matrix SHARED "")

target_sources(
  matrix
  PRIVATE
    src/matrix.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include/matrix.h
  )

target_include_directories(
  matrix
  PUBLIC
    include
  )
