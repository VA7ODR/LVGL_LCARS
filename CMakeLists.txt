cmake_minimum_required(VERSION 3.28)
project(SDL3LVGLTest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set(CMAKE_CXX_STANDARD 26)

add_subdirectory(SDL EXCLUDE_FROM_ALL)
include_directories(SDL/include)

set(LV_BUILD_CONF_PATH ${CMAKE_SOURCE_DIR}/lv_conf.h)
add_subdirectory(lvgl)

include_directories(lvgl/src)

add_executable(SDL3LVGLTest
        main.cpp
        UI.cpp
        UI.hpp
        fonts/antonio_22.c
        fonts/antonio_24.c
        fonts/antonio_28.c
        fonts/antonio_32.c
        fonts/antonio_36.c
        fonts/antonio_48.c
        fonts/antonio_96.c
        fonts/antonio_bold_22.c
        fonts/antonio_bold_24.c
        fonts/antonio_bold_28.c
        fonts/antonio_bold_32.c
        fonts/antonio_bold_36.c
        fonts/antonio_bold_48.c
        fonts/antonio_bold_96.c
)
target_link_libraries(SDL3LVGLTest PRIVATE SDL3::SDL3 lvgl)
