cmake_minimum_required(VERSION 3.26)
project(Exam_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Exam_project main.cpp
        Person.cpp
        Person.h
        Menu.cpp
        Menu.h
        Worker.cpp
        Worker.h
        Barbershop.cpp
        Barbershop.h
        Service.cpp
        Service.h
        Order.cpp
        Order.h)
