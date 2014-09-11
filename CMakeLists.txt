cmake_minimum_required(VERSION 2.8)
project(STL)

#add_definitions(-std=c++11)

add_subdirectory(includes)
add_subdirectory(part1)

# To find path to includes
include_directories(${STL_SOURCE_DIR}/part1)
include_directories(${STL_SOURCE_DIR}/includes)

add_executable(myBinary1 main1.cpp)
add_executable(myBinary6 a.cpp)
add_executable(myBinary2 main2.cpp)
add_executable(myBinary3 main3)
add_executable(myBinary4 main4)



add_executable(myBinary5 main_boost)
target_link_libraries(myBinary5 fourBoolsLib)