cmake_minimum_required(VERSION 3.5)

project(LivingRooms)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

add_subdirectory(src/)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC LivingRoomLib)
