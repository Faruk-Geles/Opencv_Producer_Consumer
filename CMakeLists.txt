cmake_minimum_required(VERSION 3.17)
project(CLION_PROJECTS)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(CLION_PROJECTS main.cpp Producer.cpp Producer.h Consumer.cpp Consumer.h)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(CLION_PROJECTS ${OpenCV_LIBS} /lib/x86_64-linux-gnu/libpthread.so.0)
