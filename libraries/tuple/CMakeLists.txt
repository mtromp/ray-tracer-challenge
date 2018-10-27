add_library(tuple SHARED "")

target_sources(
  tuple
  PRIVATE
    src/color.cpp
    src/tuple.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include/color.h
    ${CMAKE_CURRENT_LIST_DIR}/include/tuple.h
  )

target_include_directories(
  tuple
  PUBLIC
    include
  )

