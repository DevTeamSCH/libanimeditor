cmake_minimum_required(VERSION 3.9.2)
project(libanimeditor)

set(CMAKE_CXX_STANDARD 11)

include_directories(.
        include)

# Library
set(HEADERS include/color.h
        include/grapicsstate.h
        include/keyframe.hpp
        include/pixel.h
        include/pixelgraphic.h
        include/pixelmatrix.h
        include/pixelquartet.h
        include/timeline.hpp
        include/vec2.h)

set(SOURCES src/color.cpp
        src/pixel.cpp
        src/pixelmatrix.cpp)

add_library(animeditor ${HEADERS} ${SOURCES})
