cmake_minimum_required(VERSION 3.22)
project(Vektoruebung C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror -Wall -Wextra -pedantic")


add_executable(Vektoruebung vektormain.c vektor.c vektor.h)
