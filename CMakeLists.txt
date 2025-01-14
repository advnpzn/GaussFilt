cmake_minimum_required(VERSION 3.20)

project(guassfil
    VERSION 1.0
    DESCRIPTION "Gaussian filter"
    LANGUAGES CXX
    )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB SOURCES "src/*.cc")

add_executable(${PROJECT_NAME} ${SOURCES})