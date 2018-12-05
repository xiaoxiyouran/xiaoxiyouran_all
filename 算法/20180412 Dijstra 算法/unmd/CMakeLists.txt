CMAKE_MINIMUM_REQUIRED(VERSION 2.8) # 没有这个会出错？
project(Dijstra)

include_directories(include)

add_library(libDijstra lib/Dijkstra.c)

add_executable(Dijstra_exe main.c)

target_link_libraries(Dijstra_exe libDijstra)