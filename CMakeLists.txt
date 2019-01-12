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
        src/pixelmatrix.cpp
        src/pixelquartet.cpp)

add_library(animeditor ${HEADERS} ${SOURCES})

# Tests
set(TEST_HEADERS test/catch.hpp)

set(TEST_SOURCES test/main.cpp
        test/test_color.cpp
        test/test_pixel.cpp)

add_executable(libanimeditor-test ${TEST_HEADERS} ${HEADERS} ${TEST_SOURCES} ${SOURCES})

set_target_properties(libanimeditor-test PROPERTIES
                        COMPILE_FLAGS "-fkeep-inline-functions -fkeep-static-functions -fprofile-arcs -ftest-coverage"
                        LINK_FLAGS "-lgcov -fprofile-arcs")
