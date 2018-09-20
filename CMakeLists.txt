cmake_minimum_required(VERSION 3.9.2)
project(libanimeditor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_library(animeditor
        src/color.cpp
        src/color.h
        src/grapicsstate.h
        src/keyframe.hpp
        src/pixel.cpp
        src/pixel.h
        src/pixelgraphic.h
        src/pixelmatrix.cpp
        src/pixelmatrix.h
        src/pixelquartet.h
        src/timeline.hpp
        src/vec2.h)
