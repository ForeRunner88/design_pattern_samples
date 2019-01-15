cmake_minimum_required(VERSION 3.5)
project(samples)

set(CMAKE_CXX_STANDARD 11)

message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install)

include(FileUtil)
SUBDIRLIST(sample_dirs_list ${CMAKE_SOURCE_DIR})
foreach(sample ${sample_dirs_list})
    if("${sample}" MATCHES "^sample_*")
        message(STATUS "sample matched: ${sample}")
        add_subdirectory(${sample})
    endif()
endforeach()

