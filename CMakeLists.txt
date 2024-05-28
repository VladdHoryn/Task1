cmake_minimum_required(VERSION 3.27)
project(Task1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task1 main.cpp
        DoubleNode.h
        queue_sorted.cpp
        queue_sorted.h
        no_element.h
        out_of_list.h)
