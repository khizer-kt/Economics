cmake_minimum_required(VERSION 3.23)
project(Economics)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Economics
        ecom.csv
        LinkedList.h
        main.cpp
        parser.h)
