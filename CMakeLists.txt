cmake_minimum_required(VERSION 3.24)
project(WindowsReadMediaInfo)

find_package(JNI REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_JNI_IMPLEMENTATION_")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

include_directories(${WINRT_INCLUDE_DIRS} ${JNI_INCLUDE_DIRS} main.hpp)

add_library(WindowsReadMediaInfo SHARED main.cpp)

set_target_properties(WindowsReadMediaInfo PROPERTIES VS_WINRT_COMPONENT TRUE)
target_link_libraries(WindowsReadMediaInfo WindowsApp.lib JNI::JNI)
