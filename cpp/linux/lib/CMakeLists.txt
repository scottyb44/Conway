cmake_minimum_required(VERSION 3.2.2)

project(ConwayLibrary)

add_library(ConwayLibrary Grid.cpp Game.cpp)
set_property(TARGET conway_lib PROPERTY CXX_STANDARD 17)
# TODO SB: Figure out what this does
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")
