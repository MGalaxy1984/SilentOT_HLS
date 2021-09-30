cmake_minimum_required(VERSION 3.20)
project(SilentOT_HLS)

set(CMAKE_CXX_STANDARD 17)

add_executable(SilentOT_HLS main.cpp Modules/PRNG.cpp Modules/PRNG.h Defines.h Tools/PRNG_Tool.cpp Tools/PRNG_Tool.h)