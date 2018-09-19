cmake_minimum_required(VERSION 3.12)
project(libanimeditor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_library(animeditor
        color.cpp
        color.h
        grapicsstate.h
        keyframe.hpp
        pixel.cpp
        pixel.h
        pixelgraphic.h
        pixelmatrix.cpp
        pixelmatrix.h
        pixelquartet.h
        timeline.hpp
        vec2.h)
