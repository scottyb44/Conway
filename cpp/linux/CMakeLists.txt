cmake_minimum_required(VERSION 3.2.2)
project(conwayMaster)

#TODO SB: Figure out how to get this working without this kind of cmake hack
#find_package(PNGwriter PATHS /home/sbartlett/vcpkg/ NO_DEFAULT_PATH REQUIRED)
find_package(PNGwriter CONFIG REQUIRED)
#find_package(Catch2 PATHS /home/sbartlett/vcpkg/ NO_DEFAULT_PATH)
find_package(Catch2 CONFIG REQUIRED)

