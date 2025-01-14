cmake_minimum_required(VERSION 3.20)

project(guassfil
    VERSION 1.0
    DESCRIPTION "An application to apply Guassian filter to images."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(
    "${CMAKE_SOURCE_DIR}/config/config.h.in"
    "${CMAKE_SOURCE_DIR}/include/config.h"
)

find_package(ImGui-SFML CONFIG REQUIRED)
find_package(argparse CONFIG REQUIRED)

file(GLOB SOURCES "src/*.cc" "src/*.h")

add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ImGui-SFML::ImGui-SFML
    argparse::argparse
)