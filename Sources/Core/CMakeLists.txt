cmake_minimum_required(VERSION 3.10)

project(Core CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib/)

# libftpcpp
include_directories(${CMAKE_SOURCE_DIR}/3rdparty/libftpcpp/include/)

include_directories(../Utils)

aux_source_directory(. SRC_LIST)
include_directories(.)

add_library(Core
    ${SRC_LIST}
)
