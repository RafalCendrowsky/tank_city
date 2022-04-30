cmake_minimum_required(VERSION 3.16)
project(proi_projekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(proi_projekt main.cpp)

target_include_directories(proi_projekt
        PRIVATE
        "${PROJECT_BINARY_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        )

target_link_libraries(proi_projekt
        sfml-graphics
        sfml-system
        sfml-window
        box2d
        )


