#cmake_minimum_required(VERSION 3.17)
#project(oop_drill_p)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(oop_drill_p
#        main.cpp
#        read_file.cpp
#        read_file.h)

cmake_minimum_required(VERSION 3.17)
project(oop_drill_p)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_PREFIX_PATH C:\\Qt\\5.12.2\\mingw73_32\\lib\\cmake\\)
#set(CMAKE_PREFIX_PATH C:\\Qt\\5.12.2\\mingw73_32\\lib\\cmake\\Qt5Charts\\)
set(CMAKE_PREFIX_PATH C:\\Qt\\5.12.2\\mingw73_32\\)
# set(CMAKE_PREFIX_PATH D:/Qt/Qt5.4.0MinGw/5.4/mingw491_32)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

include_directories(GUI)

include_directories(headers)

add_executable(oop_drill_p
        main.cpp
        form.cpp
        form.h
        ui_form.h
        ui_programmerwindow.h
        programmerwindow.cpp
        programmerwindow.h
        read_file.cpp
        read_file.h
        TableModel.cpp
        TableModel.h)

target_link_libraries(oop_drill_p Qt5::Widgets)
target_link_libraries(oop_drill_p C:/Users/Andrei/Documents/Qt_dll)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Charts REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Sql REQUIRED)

qt5_use_modules(oop_drill_p Widgets Charts)
qt5_use_modules(oop_drill_p Widgets Sql)
qt5_wrap_cpp(gui_SRC gui.h gui.cpp)

#find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Charts REQUIRED)

add_custom_target(Qt5CopyBinaries
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/libgcc_s_dw2-1.dll ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/Qt5Charts.dll ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/Qt5Chartsd.dll ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/Qt5Cored.dll ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/Qt5Guid.dll ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/Qt5Widgetsd.dll ${CMAKE_CURRENT_BINARY_DIR})

add_dependencies(oop_drill_p Qt5CopyBinaries)

