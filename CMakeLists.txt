cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(graphs VERSION 0.0.1 LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# fmt
find_package(fmt CONFIG REQUIRED)

# Compilation options

# compile the library
add_subdirectory(src)


# compile the application
add_subdirectory(app)

# compile the tests
include(CTest)
if(BUILD_TESTING)
  find_package(Catch2 REQUIRED)
  include(Catch)
  add_subdirectory(tests)
endif()



# Add an alias target for use if this project is included as a subproject in another project
add_library(graphs::graphs ALIAS graphs)

# Install targets and configuration
install(
  TARGETS graphs
  EXPORT graphs-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
  EXPORT graphs-config
  NAMESPACE graphs::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/graphs
)

install(
  DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
