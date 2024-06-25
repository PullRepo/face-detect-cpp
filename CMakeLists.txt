
cmake_minimum_required(VERSION 3.23)

project(face_detect VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(face_detect
src/face_detect.cpp
src/main.cpp)

target_link_libraries(face_detect ${OpenCV_LIBS})
