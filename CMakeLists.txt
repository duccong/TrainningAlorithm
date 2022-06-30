cmake_minimum_required(VERSION 3.5)

project(TrainningAlgorithm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TrainningAlgorithm main.cpp
                    utils.h utils.cpp
                    part2.h part2.cpp
                    buildpyramid.h buildpyramid.cpp
                )
