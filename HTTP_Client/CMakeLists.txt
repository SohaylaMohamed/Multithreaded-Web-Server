cmake_minimum_required(VERSION 3.12)
project(HTTP_Client)

set(CMAKE_CXX_STANDARD 14)

add_executable(HTTP_Client main.cpp Client.cpp Client.h FileSystem.cpp FileSystem.h Structs.cpp Structs.h Actions.cpp Actions.h Parser.cpp Parser.h Request.cpp Request.h)