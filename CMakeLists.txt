cmake_minimum_required(VERSION 3.23)
project(Billing_Manager)

set(CMAKE_CXX_STANDARD 14)

add_executable(Billing_Manager main.cpp Menu.cpp Menu.h CardVector.cpp CardVector.h global.h BillVector.cpp BillVector.h tool.h tool.cpp)
