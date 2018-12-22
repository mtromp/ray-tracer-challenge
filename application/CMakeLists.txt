# ##########################################
add_executable(tickApplication "")

target_sources(
  tickApplication
  PRIVATE
    tick.cpp
  )

target_link_libraries(
  tickApplication
  PRIVATE
    tuple
    canvas
  )
