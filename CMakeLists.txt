cmake_minimum_required(VERSION 3.27)

project(gaussfilt
    VERSION 1.0
    DESCRIPTION "A Tool to apply Gaussian filter to images."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

configure_file(
    "${CMAKE_SOURCE_DIR}/config/config.h.in"
    "${CMAKE_SOURCE_DIR}/config/config.h"
)

find_package(ImGui-SFML CONFIG REQUIRED)
find_package(argparse CONFIG REQUIRED)

file(GLOB SOURCES "src/*.cc" "src/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${CONFIG})

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/config"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ImGui-SFML::ImGui-SFML
    argparse::argparse
)