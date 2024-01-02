add_library(graphs graphs.cpp)
target_include_directories(graphs PUBLIC
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(graphs PRIVATE fmt::fmt-header-only)  