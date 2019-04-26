cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
project (sdltest)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(/usr/local/include)

add_executable(sdltest main.cpp)
target_link_libraries(sdltest ${SDL2_LIBRARIES} ${OPENGL_LIBRARY})
