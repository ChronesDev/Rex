cmake_minimum_required(VERSION 3.21)
project(Rex)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(rex STATIC "rex/rex-entry.cc")
set_target_properties(rex PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(rex PUBLIC "./rex/")
target_include_directories(rex PUBLIC "./lib/Index2/Index/Include/Include_Index/")

target_link_libraries(rex PUBLIC yogacore)

add_subdirectory(lib)
add_subdirectory(rex)


add_executable(rex-runnable "rex/rex-entry.cc")
target_link_libraries(rex-runnable PUBLIC rex)