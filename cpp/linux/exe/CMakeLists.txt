cmake_minimum_required (VERSION 3.0)

project (ConwayExe)

add_executable(ConwayExe conway_main.cpp)
set_property(TARGET mandelbrot PROPERTY CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

include_directories(${CMAKE_SOURCE_DIR}/lib)

#find_package(TBB CONFIG REQUIRED)
target_link_libraries(ConwayExe PRIVATE ConwayLibrary)
#target_link_libraries(mandelbrot PRIVATE PNGwriter::PNGwriter)
#target_link_libraries(mandelbrot PRIVATE TBB::tbb)
