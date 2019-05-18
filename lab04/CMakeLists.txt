cmake_minimum_required(VERSION 3.13)
project(lab04)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab04
        Data.cpp
        Data.h
        main.cpp
        Produkt.cpp
        Produkt.h
        Towar.cpp
        Towar.h
        TowarZKaucja.cpp
        TowarZKaucja.h
        Usluga.cpp
        Usluga.h)
