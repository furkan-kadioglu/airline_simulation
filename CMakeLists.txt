cmake_minimum_required(VERSION 3.0)
project(project2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Passenger.h Passenger.cpp Event.h Event.cpp Model.cpp Model.h)
add_executable(airline_simulation  ${SOURCE_FILES})
