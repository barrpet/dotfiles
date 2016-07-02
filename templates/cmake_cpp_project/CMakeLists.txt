# CMake Options
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Meta information
set(META_PROJECT_NAME        "cpp_proj")
set(META_PROJECT_DESCRIPTION "a short description")
set(META_VERSION_MAJOR       "0")
set(META_VERSION_MINOR       "1")
set(META_VERSION_PATCH       "0")
set(META_VERSION             "${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH}")
set(META_NAME_VERSION        "${META_PROJECT_NAME} ${META_VERSION}")

# Project options
option(BUILD_SHARED_LIBS  "Build shared instead of static libraries." ON)
option(OPTION_BUILD_TESTS "Build tests."                              ON)
option(OPTION_BUILD_DOCS  "Build documentation."                     OFF)

# Declare project
project(${META_PROJECT_NAME} CXX)

# Configuration Files
configure_file(project.pc.in "${PROJECT_BINARY_DIR}/project.pc" @ONLY)

# Guard against in source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

# Get build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

string(TOLOWER "${CMAKE_BUILD_TYPE}" cmake_build_type_tolower)
if(NOT cmake_build_type_tolower STREQUAL "debug"
  AND NOT cmake_build_type_tolower STREQUAL "release"
  AND NOT cmake_build_type_tolower STREQUAL "relwithdebinfo")
  message(FATAL_ERROR "Unknown build type \"${CMAKE_BUILD_TYPE}\". Allowed values are Debug, Release, RelWithDebInfo (case-insensitive).")
endif()

#-------------------------------------------------------------------------------
# INSTALL DIRECTORIES

set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries") 
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header
files")

foreach(p LIB BIN INCLUDE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

#-------------------------------------------------------------------------------
# PROJECT MODULES

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(docs)

#-------------------------------------------------------------------------------
# DEPLOYMENT (GLOBAL PROJECT FILES)

# Create a version file
file(WRITE "${PROJECT_BINARY_DIR}/VERSION" "${META_NAME_VERSION}")

# Install project meta files
#install(FILES AUTHORS   DESTINATION ${INSTALL_ROOT} COMPONENT runtime)
#install(FILES LICENSE   DESTINATION ${INSTALL_ROOT} COMPONENT runtime)
#install(FILES README.md DESTINATION ${INSTALL_ROOT} COMPONENT runtime)

# Install runtime data
#install(DIRECTORY ${PROJECT_SOURCE_DIR}/data
#        DESTINATION ${INSTALL_DATA}
#        COMPONENT runtime)

# Add uninstall target
add_custom_target(uninstall
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ProjectUninstall.cmake)
