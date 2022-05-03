cmake_minimum_required(VERSION 3.16)
project(proi_projekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(app)

target_sources(app PRIVATE main.cpp)

add_subdirectory(src)

target_include_directories(app
        PRIVATE
        "${PROJECT_BINARY_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        )

target_link_libraries(app
        sfml-graphics
        sfml-system
        sfml-window
        box2d
        )


