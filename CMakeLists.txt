cmake_minimum_required(VERSION 3.20)
project(SilentOT_HLS)

set(CMAKE_CXX_STANDARD 17)

add_executable(SilentOT_HLS main.cpp PRNG.cpp PRNG.h)

include_directories("E:/intelFPGA_lite/19.1/hls/include")