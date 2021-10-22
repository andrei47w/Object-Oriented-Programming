cmake_minimum_required(VERSION 3.17)
project(a45_916_Popa_Andrei_Calin_tmp)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(a45_916_Popa_Andrei_Calin_tmp
        headers/Controller.h
        headers/DynamicVector.h
        headers/Iterator.h
        headers/Repo.h
        headers/List.h
        headers/UI.h
        Controller.cpp
        Iterator.cpp
        main.cpp
        Repo.cpp
        List.cpp
        UI.cpp)
