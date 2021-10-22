cmake_minimum_required(VERSION 3.17)
project(t1_916_Popa_Andrei_Calin_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t1_916_Popa_Andrei_Calin_1
        Controller.cpp
        Controller.h
        DynamicVector.h
        main.cpp
        Repository.cpp
        Repository.h
        Gene.cpp
        Gene.h
        UI.cpp
        UI.h)
