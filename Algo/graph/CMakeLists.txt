cmake_minimum_required(VERSION 3.22)
project(graph C)

set(CMAKE_C_STANDARD 11)

add_executable(prims prims.c)
add_executable(kruskal kruskal.c)
add_executable(djikstra djikstra.c)
add_executable(test testing.c)
add_executable(graph_coloring graph_coloring.c)
