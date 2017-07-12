cmake_minimum_required(VERSION 3.7)
project(optical_system)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR  ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCE_FILES core.c main.cpp main_window.cpp zdoublespinbox.cpp)
add_executable(optical_system ${SOURCE_FILES})
target_link_libraries(optical_system Qt5::Widgets)
