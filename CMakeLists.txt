cmake_minimum_required(VERSION 3.21)
project(My_annuaire)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug)
include_directories(build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/debug)
include_directories(My_annuaire)
include_directories(My_annuaire/headers)

add_executable(My_annuaire
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/debug/main.o
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/debug/mainwindow.o
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/debug/moc_mainwindow.cpp
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/debug/moc_mainwindow.o
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/debug/moc_predefs.h
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/debug/My_annuaire.exe
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/.qmake.stash
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/Makefile
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/Makefile.Debug
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/Makefile.Release
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/ui_mainwindow.h
        build-My_annuaire-Desktop_Qt_5_12_3_MinGW_64_bit-Debug/usersyedappdatalocaltemptmp7pozzg
        My_annuaire/headers/mainwindow.h
        My_annuaire/headers/test.h
        My_annuaire/src/main.cpp
        My_annuaire/src/mainwindow.cpp
        My_annuaire/src/test.cpp
        My_annuaire/UI/mainwindow.ui
        My_annuaire/main.cpp
        My_annuaire/mainwindow.h
        My_annuaire/mainwindow.ui
        My_annuaire/My_annuaire.pro
        My_annuaire/My_annuaire.pro.user)
