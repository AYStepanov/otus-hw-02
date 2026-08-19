cmake_minimum_required(VERSION 3.30)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VERSION})

# Global options
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR})

add_compile_options(
  -Wall
  -Wextra
  -Werror
  -pedantic
)

# For boost 1.90
cmake_policy(SET CMP0167 NEW)

# Sub-projects
add_subdirectory(Lib)
add_subdirectory(App)

option(WITH_BOOST_TEST "Whether to build Boost test" ON)
if(WITH_BOOST_TEST)
    enable_testing()
    add_subdirectory(Test)
endif()

install(TARGETS ip_filter RUNTIME DESTINATION bin)

# Generate DEB package
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
