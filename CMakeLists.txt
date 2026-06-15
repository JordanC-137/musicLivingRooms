cmake_minimum_required(VERSION 3.5)

project(LivingRooms)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

add_library(LivingRoomLib src/Album.cpp src/LivingRoom.cpp)

target_include_directories(LivingRoomLib PUBLIC include/)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC LivingRoomLib)
