cmake_minimum_required(VERSION 3.17)
project(midterm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(midterm
        Controller.cpp
        Controller.h
        DynamicVector.h
        main.cpp
        Repository.cpp
        Repository.h
        UI.cpp
        UI.h Tutorial.cpp Tutorial.h)
