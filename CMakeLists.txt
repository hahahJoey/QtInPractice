cmake_minimum_required(VERSION 3.12)
project(QtInPractice)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core)
find_package(Qt5Widgets)

add_executable(file file/main.cpp file/resource.qrc)
target_link_libraries(file Qt5::Widgets)

add_executable(application application/main.cpp application/application.qrc application/mainwindow.cpp application/mainwindow.hpp)
target_link_libraries(application Qt5::Widgets)