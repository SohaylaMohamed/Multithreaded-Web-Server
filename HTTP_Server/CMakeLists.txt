cmake_minimum_required(VERSION 3.12)
project(HTTP_Server)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)


add_executable(HTTP_Server main.cpp Server.cpp Server.h Parser.cpp Parser.h FileSystem.cpp FileSystem.h Actions.cpp Actions.h Worker.cpp Worker.h Request.cpp Request.h)